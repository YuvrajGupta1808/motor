#include "MotorDriver.h"
#include "Debug.h"

/**
 * Motor rotation.
 *
 * Example:
 * Motor_Init();
 */
void Motor_Init(void)
{
    PCA9685_Init(0x40);
    PCA9685_SetPWMFreq(100);
}

/**
 * Motor rotation.
 *
 * @param motor: Motor A and Motor B.
 * @param dir: forward and backward.
 * @param speed: Rotation speed.  //(0~100)
 *
 * Example:
 * @code
 * Motor_Run(MOTORA, FORWARD, 50);
 * Motor_Run(MOTORB, BACKWARD, 100);
 */
void Motor_Run(UBYTE motor, DIR dir, UWORD speed)
{
    if (speed > 100)
        speed = 100;

    if (motor == MOTORA)
    {
        DEBUG("Motor A Speed = %d\r\n", speed);
        PCA9685_SetPwmDutyCycle(PWMA, speed);
        if (dir == FORWARD)
        {
            DEBUG("forward...\r\n");
            PCA9685_SetLevel(AIN1, 0);
            PCA9685_SetLevel(AIN2, 1);
	    DEBUG("Setting Motor A: AIN1 = %d, AIN2 = %d\r\n", 0, 1); // For forward
        }
        else
        {
            DEBUG("backward...\r\n");
            PCA9685_SetLevel(AIN1, 1);
            PCA9685_SetLevel(AIN2, 0);
	    DEBUG("Setting Motor A: AIN1 = %d, AIN2 = %d\r\n", 1, 0); // For backward
}
    }
    else
    {
        DEBUG("Motor B Speed = %d\r\n", speed);
        PCA9685_SetPwmDutyCycle(PWMB, speed);
        if (dir == FORWARD)
        {
            DEBUG("forward...\r\n");
            PCA9685_SetLevel(BIN1, 0);
            PCA9685_SetLevel(BIN2, 1);
        }
        else
        {
            DEBUG("backward...\r\n");
            PCA9685_SetLevel(BIN1, 1);
            PCA9685_SetLevel(BIN2, 0);
        }
    }
}

/**
 * Motor stop rotation.
 *
 * @param motor: Motor A and Motor B.
 *
 * Example:
 * @code
 * Motor_Stop(MOTORA);
 */
void Motor_Stop(UBYTE motor)
{
    if (motor == MOTORA)
    {
        PCA9685_SetPwmDutyCycle(PWMA, 0);
    }
    else
    {
        PCA9685_SetPwmDutyCycle(PWMB, 0);
    }
}
