#include "Player.hpp"

Player::Player(Map &map, int x, int y) : _level(&map), _x(x), _y(y)
{
    _level->setPlayerPos(_x, _y);
}

Player::~Player(void)
{

}

// move player
void    Player::moveRight(void)
{
    if (_level->checkForCollision(_x, _y + 1))
    {
        _level->checkForCollectable(_x, _y + 1);
        _level->erasePlayerPos(_x, _y);
        _level->setPlayerPos(_x, ++_y);
    }
}

void    Player::moveLeft(void)
{
    if (_level->checkForCollision(_x, _y - 1))
    {
        _level->checkForCollectable(_x, _y - 1);
        _level->erasePlayerPos(_x, _y);
        _level->setPlayerPos(_x, --_y);
    }
}

void    Player::moveUp(void)
{
    if (_level->checkForCollision(_x - 1, _y))
    {
        _level->checkForCollectable(_x - 1, _y);
        _level->erasePlayerPos(_x, _y);
        _level->setPlayerPos(--_x, _y);
    }
}

void    Player::moveDown(void)
{
    if (_level->checkForCollision(_x + 1, _y))
    {
        _level->checkForCollectable(_x + 1, _y);
        _level->erasePlayerPos(_x, _y);
        _level->setPlayerPos(++_x, _y);
    }
}