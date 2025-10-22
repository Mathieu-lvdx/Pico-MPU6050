#include <stdio.h>
#include "pico/stdlib.h"
#include "mpu6050.h"

int main(void) {
    stdio_init_all();
    mpu6050_init();

    mpu6050_data_t data;
    while(1)
    {
        mpu6050_get_data(&data);
        printf("Accel: X=%.2f Y=%.2f Z=%.2f g | Gyro: X=%.2f Y=%.2f Z=%.2f °/s | Temp=%.2f °C\n",
            data.AccelX, data.AccelY, data.AccelZ, data.GyroX, data.GyroY, data.GyroZ, data.Temp);

        sleep_ms(500);
    }

    return 0;
}