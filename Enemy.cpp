#include "Enemy.hpp"

Enemy::Enemy(Map &map, int x, int y) : _level(&map), _x(x), _y(y), moveFlag(0)
{
    _level->setEntityPos(_x, _y, 'E');
}

Enemy::~Enemy(void)
{

}

// moveFlag:
// 0-> right, 1-> left, 2->up, 3->down
void    Enemy::autoMove(void)
{
    switch(moveFlag)
    {
        case 0:
        {
            if (moveRight())
                moveFlag = 0;
            else
                moveFlag = 1;
            break ;
        }
        case 1:
        {
            if (moveLeft())
                moveFlag = 1;
            else
                moveFlag = 2;
            break ;
        }
        case 2:
        {
            if (moveUp())
                moveFlag = 2;
            else
                moveFlag = 3;
            break ;
        }
        case 3:
        {
            if (moveDown())
                moveFlag = 3;
            else
                moveFlag = 0;
            break ;
        }
    }
}

bool    Enemy::moveRight(void)
{
    if (_level->checkForECollision(_x, _y + 1))
    {
        _level->eraseEntityPos(_x, _y);
        _level->setEntityPos(_x, ++_y, 'E');
        return true;
    }
    return false;
}

bool    Enemy::moveLeft(void)
{
    if (_level->checkForECollision(_x, _y - 1))
    {
        _level->eraseEntityPos(_x, _y);
        _level->setEntityPos(_x, --_y, 'E');
        return true;
    }
    return false;
}

bool    Enemy::moveUp(void)
{
    if (_level->checkForECollision(_x - 1, _y))
    {
        _level->eraseEntityPos(_x, _y);
        _level->setEntityPos(--_x, _y, 'E');
        return true;
    }
    return false;
}

bool    Enemy::moveDown(void)
{
    if (_level->checkForECollision(_x + 1, _y))
    {
        _level->eraseEntityPos(_x, _y);
        _level->setEntityPos(++_x, _y, 'E');
        return true;
    }
    return false;
}