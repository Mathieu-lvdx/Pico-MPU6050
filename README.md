# MPU6050 interface for Raspberry Pi Pico

This repository is the simpiest way to use MPU6050. You just have you initialize the MPU6050 and get its data.<br/>
**Don't forget to import your _pico_sdk_import.cmake_ if you build this project !**

## How does it work ?

`mpu6050_init()` is the fuction which initialize the hardware. The default connection follows the array below. You can change I²C pins in _mpu6050.c_.

| Pico Pins           | MPU6050 Pins |
|------------------|-------------|
| Pin 36 (3V3 Out) | VCC  |
| Pin 38 (GND)     | GND  |
| Pin 7 (GPIO 5)   | SCL  |
| Pin 6 (GPIO 4)   | SDL  |

`mpu6050_data_t` is the struct where data are stored. The MPU6050 can get data about acceleration, gyroscope, and temperature.
```
// The struct is located in mpu6050.h

typedef struct {
    float AccelX, AccelY, AccelZ;
    float GyroX, GyroY, GyroZ;
    float Temp;
} mpu6050_data_t;
```

`mpu6050_get_data()` is the function that get all data. You have to put the pointer to your _mpu6050_data_t_ variable as argument to get data. All values are stored as float.

## Code sample
This part prints the temperature got by the MPU6050.
```
mpu6050_init():

mpu6050_data_t data;
while(1) {
    mpu6050_get_data(&data);
    printf("Temperature : %.2f°C\n", data.Temp);
    sleep_ms(500);
}
```
