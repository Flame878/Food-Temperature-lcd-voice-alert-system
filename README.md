# Food-Temperature-lcd-voice-alert-system
Arduino-based food temperature monitoring system with LCD display and voice alerts
  --Overview--
This project is an embedded system designed to monitor, read and print tempreture using an Audio module, lcd screen and a waterproof DS18B20 Sensor.

--Hardware Used--
- Arduino
- DS18B20 Waterproof Temperature Sensor
- 16x2 LCD display
- Voice playback module
- External speaker
- Breadboard and jumper wires

  --The mechanism--
- The DS18B20 Sensor measures the Temperature of the food.
- Temperature is evaluated against predefined saftey thresholds ( Food needs to be above 145 Degrees Fahrenheit (°F)).
- The LCD alternates between displaying Fahrenheit and Celsius readings.
- When the Temperature is above 145 (°F), a voice alert is triggered confirming it.
- The system continuously updates readings in real time and is also printed in the serial monitor.

  --My thought process--
  
  This project was designed and implemented independently, including sensor integration, LCD interface design, control logic, and audio alert functionality.
  The place I work at is a resturant when we have food out we need to use a thermometer every few hours to check Temperature, Which can be tedious this came out as an idea to make the process more simple and not waste time.

  --Improvements ideas--
  - Using a text to speech modulue instead to speak mutiple prompts
  - Improve the LCD formatting
  - Find a better way to display the Temperature for more clairity
  - Add data logging for Temperature history
  

  
