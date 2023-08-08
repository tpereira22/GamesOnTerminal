#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "Map.hpp"

class Enemy
{
private:
    int _x;
    int _y;
    int moveFlag;
    Map *_level;
public:
    Enemy(Map &map, int x, int y);
    ~Enemy(void);

    void    autoMove(void);
    bool    moveRight(void);
    bool    moveLeft(void);
    bool    moveUp(void);
    bool    moveDown(void);
};

#endif