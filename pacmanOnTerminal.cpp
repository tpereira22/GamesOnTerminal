#include "pacmanOnTerminal.h"

void    checkForInput(char input, Player &player)
{
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
    system("clear");
    std::cout << std::endl << "  Welcome to Pacman On Terminal" << std::endl;
    std::cout << " _______________________________" << std::endl;
    std::cout << std::endl << " How to play: " << std::endl << std::endl;
    std::cout << "  -> Tap ASDW to move. Dont press just tap!" << std::endl;
    std::cout << "  -> Tap K to exit" << std::endl;
    std::cout << " _______________________________" << std::endl;
    std::cout << std::endl << " Ready to play?" << std::endl;
    std::cout << std::endl << " Press any key to start" << std::endl;
    getCharWithoutEnter();
}

//pacman
int main()
{
    char input = ' ';
    Map map;
    Player player(map, 6, 15);
    intro();
    while (1)
    {
        system("clear");
        checkForInput(input, player);
        map.drawMap();
        input = getCharWithoutEnter();
    }
}