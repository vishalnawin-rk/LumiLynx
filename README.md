
# Smart Street Light Fault Detection System 🚦

### Overview
The Smart Street Light Fault Detection System is an IoT-based solution designed to monitor urban street lighting infrastructure in real-time. This project addresses the inefficiencies in current street light maintenance by detecting and classifying faults such as non-functional lights and cable issues. By providing precise fault type identification and exact location tracking, this system ensures faster and more efficient maintenance, reducing linemen's workload.

### Features
- **Real-time Monitoring**: Continuous monitoring of street lights using LDRs, Current Sensors, and ESP8266 module.
- **Accurate Fault Detection**: Identifies specific fault types like bulb failure or cable malfunction.
- **Precise Location Tracking**: Pinpoints the exact street light and location of the fault using Street ID and GPS coordinates.
- **Proactive Maintenance**: Moves away from complaint-based systems to proactive, real-time fault notifications.
- **Web Dashboard**: Displays fault data and locations for easy access and efficient management.

### Components Used
- **Light Dependent Resistors (LDR)**: Detects light intensity to identify non-functional street lights.
- **Current Sensors**: Monitors the current flow to detect abnormal behavior like cable faults.
- **ESP8266 Wi-Fi Module**: Transmits data to the cloud for real-time monitoring.
- **Microcontroller**: Controls sensors and processes fault data.
- **LED Indicators**: Displays the status of the system.

### System Architecture
1. **Sensor Network**: LDRs and Current Sensors collect data on light intensity and current flow.
2. **Fault Detection**: Sensor readings are processed by the microcontroller to detect any issues.
3. **Data Transmission**: Detected faults, along with Street ID and location details, are sent to the cloud using the ESP8266 module.
4. **Web Dashboard**: Fault data is retrieved from the cloud and displayed on a web interface for real-time monitoring.
  
### How It Works
1. **Sensor Setup**: LDR and Current Sensors are connected to the microcontroller to monitor each street light's functionality.
2. **Fault Detection**: When an issue is detected (e.g., low light intensity or no current flow), the system records the fault.
3. **Notification System**: A message containing a predefined error code, Street ID, and exact location is sent to the cloud.
4. **Web Interface**: The fault data is retrieved from the cloud and displayed on a website, allowing authorities to take prompt action.

### Installation and Usage
1. **Hardware Setup**: 
   - Connect LDR and Current Sensor modules to the microcontroller following their respective datasheets.
   - Use the ESP8266 module to establish a Wi-Fi connection.
2. **Software Setup**:
   - Flash the microcontroller with the firmware to read sensor data and process it for fault detection.
   - Set up the database and web server to store and visualize real-time data.
3. **Real-Time Monitoring**:
   - Monitor the fault detection data on the web interface and track the status of each street light in real time.

### Future Enhancements
- **Automated Maintenance Alerts**: Implement automated alerts to notify linemen via SMS or email.
- **Energy Optimization**: Extend the system to optimize energy usage based on real-time lighting needs.
- **Advanced Fault Detection**: Introduce machine learning algorithms for predicting potential faults before they occur.

### License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

### Acknowledgments
- Special thanks to open-source IoT platforms and the embedded systems community for their contributions.
