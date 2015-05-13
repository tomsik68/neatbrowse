#include "terminal.h"


/* struct that holds old terminal settings */
static struct termios oldt;

void terminalInit(){
    struct termios newt;
    /* store old terminal settings */
    tcgetattr(STDIN_FILENO, &oldt);
    /* copy old settings */
    newt = oldt;
    /* remove ICANON and ECHO flags */
    newt.c_lflag &= ~(ICANON | ECHO);
    /* apply the new settings */
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void terminalCleanup(){
    /* apply settings from the `oldt` variable */
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
