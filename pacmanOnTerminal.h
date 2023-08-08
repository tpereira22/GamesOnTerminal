#ifndef PACMAN_ON_TERMINAL_HPP
# define PACMAN_ON_TERMINAL_HPP

# include <iostream>
# include <stdio.h>
# include <termios.h>
# include <unistd.h>
# include <cstdlib>
# include "Map.hpp"
# include "Player.hpp"

// pacmanOnTerminal.cpp
void    checkForInput(char input);
void    intro(void);

// utils.cpp
char getCharWithoutEnter();

#endif