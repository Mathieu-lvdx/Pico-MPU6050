#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "mpu6050.h"

i2c_inst_t* I2C_PORT = i2c0;

const uint8_t addr = 0x68;
const uint8_t reg = 0x3B;

const uint8_t PIN_SDA = 4;
const uint8_t PIN_SCL = 5;

void mpu6050_write_byte(uint8_t reg, uint8_t data) {
    uint8_t buf[2] = {reg, data};
    i2c_write_blocking(I2C_PORT, addr, buf, 2, false);
}

int16_t read_word(uint8_t high, uint8_t low) {
    return (int16_t)((high << 8) | low);
}

void mpu6050_get_data(mpu6050_data_t* dataStruct) {
    uint8_t raw[14];
    i2c_write_blocking(I2C_PORT, addr, &reg, 1, true);
    i2c_read_blocking(I2C_PORT, addr, raw, 14, false);

    int16_t accel_x = read_word(raw[0], raw[1]);
    int16_t accel_y = read_word(raw[2], raw[3]);
    int16_t accel_z = read_word(raw[4], raw[5]);
    int16_t temp_raw = read_word(raw[6], raw[7]);
    int16_t gyro_x = read_word(raw[8], raw[9]);
    int16_t gyro_y = read_word(raw[10], raw[11]);
    int16_t gyro_z = read_word(raw[12], raw[13]);

    dataStruct->AccelX = accel_x / 16384.0;
    dataStruct->AccelY = accel_y / 16384.0;
    dataStruct->AccelZ = accel_z / 16384.0;
    dataStruct->GyroX = gyro_x / 131.0;
    dataStruct->GyroY = gyro_y / 131.0;
    dataStruct->GyroZ = gyro_z / 131.0;
    dataStruct->Temp = (temp_raw / 340.0) + 36.53;
}

void mpu6050_init(void) {
    i2c_init(I2C_PORT, 400*1000);
    gpio_set_function(PIN_SDA, GPIO_FUNC_I2C);
    gpio_set_function(PIN_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(PIN_SDA);
    gpio_pull_up(PIN_SCL);

    mpu6050_write_byte(0x6B, 0x00);
    mpu6050_write_byte(0x1B, 0x00);
    mpu6050_write_byte(0x1C, 0x00);
    sleep_ms(100);
}