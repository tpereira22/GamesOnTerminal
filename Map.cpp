#include "pacmanOnTerminal.h"

// '|' and '-' are walls
// 'P' is the player
// 'E' is the enemys
// 'o' is that thing that changes enemys + extra points
// '.' is to gain points
Map::Map(void) : _rows(13), _cols(32), _score(0)
{
    this->_map = new std::string[_rows * _cols] {
        "--------------------------------",
        "|        |            |        |", 
        "| ------ |  --------  | ------ |",
        "| |      |            |      | |",
        "| |o|                      |o| |",
        "| ---  |  -----  -----  |  --- |",
        "|      |  |          |  |      |", 
        "| ---  |  ------------  |  --- |",
        "| |o|                      |o| |",
        "| |      |            |      | |",
        "| ------ |  --------  | ------ |",
        "|        |            |        |",
        "--------------------------------"
    };
}

Map::Map(const int rows, const int cols) : _rows(rows), _cols(cols), _score(0)
{

}

Map::~Map(void)
{
    delete[] _map;
}

// checks
bool    Map::checkForPCollision(int x, int y)
{
    if (_map[x][y] == '|' || _map[x][y] == '-')
        return false;
    return true;
}

bool    Map::checkForECollision(int x, int y)
{
    if (_map[x][y] == '|' || _map[x][y] == '-' || _map[x][y] == 'E')
        return false;
    return true;
}

void    Map::checkForCollectable(int x, int y)
{
    if (_map[x][y] == 'o')
        _score += 100;
    else if (_map[x][y] == '.')
        _score += 5;
}

// change entity position
void    Map::setEntityPos(int x, int y, char entity)
{
    _map[x][y] = entity;
}

void    Map::eraseEntityPos(int x, int y)
{
    _map[x][y] = ' ';
}

void    Map::drawMap(void)
{
    std::cout << std::endl << "   Pacman On Terminal" << std::endl;
    std::cout << "   _______________________________" << std::endl;
    std::cout << std::endl;
    for (int x = 0; x < _rows;x++)
    {
        std::cout << "   ";
        for (int y = 0; y < _cols; y++)
            std::cout << _map[x][y];
        std::cout << std::endl;
    }
    drawScore();
}

void    Map::drawScore(void)
{
    std::cout << std::endl << "   SCORE: " << _score << std::endl;
}