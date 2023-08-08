#ifndef PACMAN_ON_TERMINAL_HPP
# define PACMAN_ON_TERMINAL_HPP

# include <iostream>
# include <stdio.h>
# include <termios.h>
# include <unistd.h>
# include <fcntl.h>
# include <cstdlib>
# include "Map.hpp"
# include "Player.hpp"
# include "Enemy.hpp"

// pacmanOnTerminal.cpp
void    setTerminal(int mode);
void    restoreTerminal(void);
void    intro(void);
void    checkForInput(Player &player);


#endif