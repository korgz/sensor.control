# Arduino Uno R3 Projects

---

## Project Descriptions

### `main.ino`
- Reads characters from serial input.
- Controls the onboard LED based on received characters `'1'` or `'0'`.

### `/TempControl`
- Divided into 3 files.
- Runs a motor connected to pin 8 based on temperature readings.

### `motortest.ino`
- Controls the motor operation based on temperature sensor input.

### `TempHum.ino`
- Logs temperature and humidity data.
- Uses a DHT11 sensor.

### `GarageDoor.ino`
- Controls a switch connected to PIN 2.
- Does **not** use an ultrasonic sensor.
