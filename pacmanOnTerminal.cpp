#include "pacmanOnTerminal.h"

static struct termios oldt, newt;

void    restoreTerminal(void)
{
    // Restore the terminal settings
    std::cout << "\e[m";
    std::cout << "\e[?25h";
    fflush(stdout);
    system("clear");
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

// 0-> intro mode, 1->game mode 
void    setTerminal(int mode)
{
    // Set the terminal to non-canonical mode
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    if (mode == 1) // keeps the program running without waiting for the input
    {
        newt.c_cc[VMIN] = 0;
        newt.c_cc[VTIME] = 0;
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    std::cout << "\e[?25l";
    atexit(restoreTerminal);
}

// fix press key keeps going
void    checkForInput(Player &player)
{
    char input;
    read(STDIN_FILENO, &input, 1);
    if (input == 'd')
        player.moveRight();
    if (input == 'a')
        player.moveLeft();
    if (input == 'w')
        player.moveUp();
    if (input == 's')
        player.moveDown();
    if (input == 'k')
        exit(0);
}

void    intro(void)
{
    setTerminal(0);
    system("clear");
    std::cout << std::endl << "  Welcome to Pacman On Terminal" << std::endl;
    std::cout << " _______________________________" << std::endl;
    std::cout << std::endl << " How to play: " << std::endl << std::endl;
    std::cout << "  -> Tap ASDW to move. Dont press just tap!" << std::endl;
    std::cout << "  -> Tap K to exit" << std::endl;
    std::cout << " _______________________________" << std::endl;
    std::cout << std::endl << " Ready to play?" << std::endl;
    std::cout << std::endl << " Press any key to start" << std::endl;
    char input;
    read(STDIN_FILENO, &input, 1);
    restoreTerminal();
}

//pacman
int main()
{
    struct  timespec req = {};
    struct  timespec rem = {};

    Map map;
    Player player(map, 9, 16);
    Enemy enemy1(map, 6, 14);
    Enemy enemy2(map, 6, 15);
    Enemy enemy3(map, 6, 16);
    Enemy enemy4(map, 6, 17);
    intro();
    setTerminal(1);
    while (1)
    {
        system("clear");
        map.drawMap();
        checkForInput(player);
        enemy1.autoMove();
        enemy2.autoMove();
        enemy3.autoMove();
        enemy4.autoMove();
        req.tv_nsec = 0.1 * 1000000000; // 0.1 sec
        nanosleep(&req, &rem);
    }
}