#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;

PwmOut pin5(D5), pin6(D6);
BBCar car(pin5, pin6, servo_ticker);

int main() {
    // please contruct you own calibration table with each servo
    double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
    double speed_table0[] = {-14.429, -14.031, -13.314, -11.002, -5.899, 0.080, 5.102, 10.603, 13.234, 14.190, 14.589};
    double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
    double speed_table1[] = {-14.908, -14.509, -13.632, -11.241, -5.740, 0.000, 5.421, 10.922, 13.553, 14.430, 14.828};

    // first and fourth argument : length of table
    car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);

    while (1) {
        car.goStraightCalib(5);
        ThisThread::sleep_for(5s);
        car.stop();
        ThisThread::sleep_for(5s);
    }

}