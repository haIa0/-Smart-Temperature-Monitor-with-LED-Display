# Smart-Temperature-Monitor-with-LED-Display

This project measures room temperature using an NTC thermistor voltage divider. By processing the analog voltage through Ohm's law and the Steinhart-Hart equation, the firmware calculates the temperature and dynamically scales LED brightness to reflect environmental changes.

## Wiring
* **Thermistor:** Connect to 5V and the second resistor.
* **Resistor:** Connect to GND (with the analog pin connected at the junction).

## How It Works 
* **Reading Method:** The code reads the voltage between the two elements through an analog pin, yielding a 10-bit ADC value between 0 and 1023.
* **Voltage Conversion:** The raw reading is converted into a 0–5V voltage interval.
* **Resistance Calculation:** Using Ohm's law, we calculate the resistance of the thermistor.
* **Steinhart-Hart Equation:** The constants provided by the manufacturer and the calculated resistance are put into the Steinhart-Hart equation, giving the temperature in Kelvin.
* **Celsius Conversion:** To transform it to Celsius, we subtract 273 from the Kelvin value.
* **Visual Application:** Finally, the temperature value is mapped to a light intensity scale between 0 and 255 (assuming a working range of 20°C to 35°C) to drive the LED.
