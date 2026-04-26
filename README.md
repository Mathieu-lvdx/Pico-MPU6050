# MPU6050 interface for Raspberry Pi Pico

This repository is the simpiest way to use MPU6050. You just have you initialize the MPU6050 and get its data.

**Don't forget to import your _pico_sdk_import.cmake_ file if you build this project !**

The default connection follows the array below. You can change I²C pins in _mpu6050.c_.

| Pico Pins           | MPU6050 Pins |
|------------------|-------------|
| Pin 36 (3V3 Out) | VCC  |
| Pin 38 (GND)     | GND  |
| Pin 7 (GPIO 5)   | SCL  |
| Pin 6 (GPIO 4)   | SDA  |

## Data struct

Here's the struct where data are stored. The MPU6050 can get data about acceleration, gyroscope, and temperature. All values are stored as `float`.

```c
// The struct is located in mpu6050.h

typedef struct {
    float AccelX, AccelY, AccelZ;
    float GyroX, GyroY, GyroZ;
    float Temp;
} mpu6050_data_t;
```

## Functions

### Initialize connection

This is the fuction which initialize I²C and hardware. If you already have initialized I²C, please remove lines 45 to 49 from the function in _mpu6050.c_.

```c
void mpu6050_init(void)
```

It doesn't take any arguments.

### Get data

This is the function that get data from MPU6050.

```c
void mpu6050_get_data(mpu6050_data_t* dataStruct)
```

`dataStruct` is the pointer to `mpu6050_data_t` variable. 

## Code sample
This part prints the temperature got by the MPU6050.
```c
mpu6050_init():

mpu6050_data_t data;
while(1) {
    mpu6050_get_data(&data);
    printf("Temperature : %.2f°C\n", data.Temp);
    sleep_ms(500);
}
```
