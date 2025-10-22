#ifndef MPU6050_H
#define MPU6050_H

typedef struct {
    float AccelX, AccelY, AccelZ;
    float GyroX, GyroY, GyroZ;
    float Temp;
} mpu6050_data_t;

void mpu6050_init(void);
void mpu6050_get_data(mpu6050_data_t* dataStruct);

#endif