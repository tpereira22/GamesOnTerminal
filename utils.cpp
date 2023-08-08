#include "pacmanOnTerminal.h"

// try to find how to stop pressed keys
char getCharWithoutEnter()
{
    char ch = ' ';

    // Set the terminal to non-canonical mode
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Read a single character without waiting for Enter
    ch = getchar();

    // Restore the terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}
