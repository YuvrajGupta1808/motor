#include "main.h"

void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:Motor Stop\r\n");
    Motor_Stop(MOTORA);
    Motor_Stop(MOTORB);
    DEV_ModuleExit();

    exit(0);
}

int main(void)
{
    //1.System Initialization
    if(DEV_ModuleInit())
        exit(0);
    
    //2.Motor Initialization
    Motor_Init();

    Motor_Run(MOTORA, BACKWARD, 100);
    // Exception handling:ctrl + c
    signal(SIGINT, Handler);
    while(1) {

    }

    //3.System Exit
    DEV_ModuleExit();
    return 0;
}



