#include "assignment3.h"

void Handler(int signo)
{
    // System Exit
    printf("\r\nHandler:Motor Stop\r\n");
    Motor_Stop(MOTORA);
    Motor_Stop(MOTORB);
    DEV_ModuleExit();

    exit(0);
}

int main(void)
{
    // 1.System Initialization
    if (DEV_ModuleInit())
        exit(0);

    // 2.Motor Initialization
    Motor_Init();

    printf("Motor_Run\r\n");

    // Motor A running forward at 100% speed for 2 seconds
    Motor_Run(MOTORA, FORWARD, 100);
    sleep(2);

    // Gradually slow down to 15%
    for (int speed = 100; speed >= 15; speed -= 5)
    {
        Motor_Run(MOTORA, FORWARD, speed);
        usleep(200000); // 0.2 seconds delay for gradual change
    }
    Motor_Run(MOTORA, FORWARD, 15);
    sleep(1);

    // Stop the motor for 1 second
    Motor_Stop(MOTORA);
    sleep(1);

    // Gradually increase speed to max in reverse direction
    for (int speed = 15; speed <= 100; speed += 5)
    {
        Motor_Run(MOTORA, BACKWARD, speed);
        usleep(200000); // 0.2 seconds delay for gradual change
    }
    Motor_Run(MOTORA, BACKWARD, 100);
    sleep(2);

    // Stop the motor for 1 second
    Motor_Stop(MOTORA);
    sleep(1);

    // Exception handling:ctrl + c
    signal(SIGINT, Handler);

    // Program finished, exit gracefully
    DEV_ModuleExit();
    return 0;

    // 3.System Exit
    DEV_ModuleExit();
    return 0;
}
