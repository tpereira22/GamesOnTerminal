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
    void    setPlayerPos(int x, int y);
    void    erasePlayerPos(int x, int y);

    bool    checkForCollision(int x, int y);
    void    checkForCollectable(int x, int y);

    void    drawMap(void);

};

#endif