#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Map.hpp"

class Player
{
private:
    int _x;
    int _y;
    Map *_level;
public:
    Player(Map &map, int x, int y);
    ~Player(void);

    // move player
    void    moveRight(void);
    void    moveLeft(void);
    void    moveUp(void);
    void    moveDown(void);
};

#endif