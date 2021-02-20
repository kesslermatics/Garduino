# Garduino by Robert Kessler

This is the first prototype of a selfwatering garden

#### Components

1x Arduino Nano (ATMega 328p, old bootloader) <br>
1x DHT11 (Temperature and Humidity Sensor) <br>
1x LCD Screen  <br>
1x I2C Interface Adapter <br>
1x Soil Moisture Sensor <br>
1x 5V Waterpump <br>

#### Pin control

I've soldered all pins and the nano to a PCB <br>

// Sensors <br>
Soil Moisture Data Pin  - A0 <br>
Temperature Pin         - D2 <br>
// I2C Bus  <br>
SDA                     - A4 <br>
SCL                     - A5 <br>
// Water Pump <br>
Water Pump Pin          - D3 <br>
// Current flow <br>
VCC and Ground were soldered in a line

#### Water flow

For the waterflow I've used a PVC tube and 3D-printed stands for it. <br>
Then I blocked off the other side off the tube and pricked little holes in there so the water could spread horizontally. <br>
Just like a soaker hose!

#### Sensor Data

Before showing the data I did 100 measurements and calculated the average. This prevents any data-runaway. <br>
Then I mapped the analog data to their respective percentage (e.g. 0-1024 -> 0-100%). <br>
This lets me easily print it to the lcd screen and read it out from there. <br>
Moisture and Humidity will be printed as percentage and temperature as degree celcius. <br>

#### External libraries

1. LiquidCrystal_I2C and Wire.H
2. DHT Sensor Library
3. Adafruit Unified Sensor

#### Power supply

I run the nano with a 9V power adapter and a USB Type B Mini. <br>
I've measured voltage and current to calculate how much it will cost in continous operation. <br>
For that I measured a voltage of 5V on VCC and a currentflow of ~90mA. <br>
That multiplicated results in 0,45W. That times 9769 hours (or one year) is 3942Wh. <br>
If one Wh costs you 30 cents in germany, this curcuit will cost you ~1,18€ per year.
