#include "Player.hpp"

Player::Player(Map &map, int x, int y) : _level(&map), _x(x), _y(y)
{
    _level->setEntityPos(_x, _y, 'P');
}

Player::~Player(void)
{

}

// move player
void    Player::moveRight(void)
{
    if (_level->checkForPCollision(_x, _y + 1))
    {
        _level->checkForCollectable(_x, _y + 1);
        _level->eraseEntityPos(_x, _y);
        _level->setEntityPos(_x, ++_y, 'P');
    }
}

void    Player::moveLeft(void)
{
    if (_level->checkForPCollision(_x, _y - 1))
    {
        _level->checkForCollectable(_x, _y - 1);
        _level->eraseEntityPos(_x, _y);
        _level->setEntityPos(_x, --_y, 'P');
    }
}

void    Player::moveUp(void)
{
    if (_level->checkForPCollision(_x - 1, _y))
    {
        _level->checkForCollectable(_x - 1, _y);
        _level->eraseEntityPos(_x, _y);
        _level->setEntityPos(--_x, _y, 'P');
    }
}

void    Player::moveDown(void)
{
    if (_level->checkForPCollision(_x + 1, _y))
    {
        _level->checkForCollectable(_x + 1, _y);
        _level->eraseEntityPos(_x, _y);
        _level->setEntityPos(++_x, _y, 'P');
    }
}