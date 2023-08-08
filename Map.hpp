#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>

class Map
{
private:
    std::string *_map;
    const int _rows;
    const int _cols;
    int _score;

    void    drawScore(void);
public:
    Map(void);
    Map(const int rows, const int cols);
    ~Map(void);

    // change entity position
    void    setEntityPos(int x, int y, char entity);
    void    eraseEntityPos(int x, int y);

    // checks
    bool    checkForPCollision(int x, int y); // player collision
    bool    checkForECollision(int x, int y); // enemy collison
    void    checkForCollectable(int x, int y);

    void    drawMap(void);

};

#endif