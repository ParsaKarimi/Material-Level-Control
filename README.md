# Arduino Material Level Control System  

This project is an Arduino-based system designed to monitor and control the material level in a container. It ensures that the material stays within a desired range by starting or stopping a process (like filling or dispensing) based on sensor inputs.  

## Features  
- **Automatic Level Control**:  
  - Starts the process when the material level drops below a set threshold.  
  - Stops the process when the material level exceeds the threshold.  
- **Error Handling**: Prevents repeated system starts within a short time frame and halts operations for a technician to inspect the sensors if needed.  
- **Noise Filtering**: Handles noisy high signals using a custom `isHigh` function.  
- **Customizable Duration**: Adjustable time for handling operations.  

## Hardware Requirements  
- Arduino board (compatible with the `Arduino.h` library).  
- Photocell for obstacle detection.  
- GPIO pin configuration:  
  - **START**: Pin 9 (low signal to start the process).  
  - **STOP**: Pin A3 (high signal to stop the process).  
  - **OUT**: Pin 10 (control output).  
  - **ERROR**: Pin 11 (error indication output).  

## Software Requirements  
- PlatformIO  
- Basic knowledge of Arduino programming.  

## Installation  
1. Clone this repository:  
   ```bash  
   git clone https://github.com/ParsaKarimi/Material-Level-Control.git
   ```  
2. Open the project folder in PlatformIO.  
3. Connect your Arduino to the computer.  
4. Compile and upload the code to your Arduino board.  

## Usage  
1. Connect the **START** pin to a sensor/output that signals low when the material level is below the threshold.  
2. Connect the **STOP** pin to a sensor/output that signals high when the material level exceeds the threshold.  
3. Connect the **OUT** pin to the control mechanism (e.g., a valve, motor, or dispenser).  
4. Monitor the **ERROR** pin for error indications:  
   - The system will not start repeatedly within a predefined time frame (`DURATION`).  
   - If this occurs, the system halts, and a technician must inspect the sensors.  
5. Adjust the `DURATION` constant in the code for operation timing if needed.  

## Code Overview  
- **`setup()`**: Configures GPIO pins and initializes the system.  
- **`loop()`**: Continuously monitors input pins and controls the process accordingly.  
- Key functions:  
  - `startSystem()`: Activates the process when triggered by the START pin.  
  - `stopSystem()`: Deactivates the process when triggered by the STOP pin.  
  - `killSystem()`: Disables the process in error conditions.  
  - `isHigh(byte pin)`: Resolves noise issues from the photocell sensor. It ensures high signals are valid and not just noise. If the photocell is not blocked (indicating no obstacle in front of the sensor), it returns high.  

## Contributing  
Contributions are welcome! Please follow the standard GitHub flow:  
1. Fork this repository.  
2. Create a new branch with your feature or bugfix.  
3. Submit a pull request with a detailed explanation of your changes.  

---

**Author**: Parsa Karimi  
