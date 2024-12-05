#include <Arduino.h>

#define START 9
#define STOP A3
#define OUT 10
#define ERROR 11

#define DURATION 90000

long last_seen = millis() - DURATION;
bool state = false;
bool isDisabled = false;

void startSystem();
void stopSystem();
void killSystem();
bool isHigh(byte pin);

void setup() {
    // put your setup code here, to run once:
    pinMode(START, INPUT);
    pinMode(STOP, INPUT);
    pinMode(OUT, OUTPUT);
    pinMode(ERROR, OUTPUT);

    digitalWrite(ERROR, !LOW);
}

void loop() {
    // put your main code here, to run repeatedly:

    if (isDisabled) return;
    if (!state && isHigh(START)) {
        if (0 < millis() - last_seen && millis() - last_seen < DURATION) killSystem();
        else startSystem();
    }
    if (!isHigh(STOP)) stopSystem();
    if (state && millis() - last_seen > DURATION) stopSystem();
    
    digitalWrite(OUT, state);
    
}

void startSystem() {
    state = true;
    last_seen = millis();
}
void stopSystem() {
    state = false;
}
void killSystem() {
    isDisabled = true;
    digitalWrite(ERROR, !HIGH);
}

bool isHigh(byte pin) {
    for (int i = 0; i < 20; i++)
        if (digitalRead(pin)) return false;
        else delay(1);
    return true;
}