#ifndef EXAMPLE_SNAKE_H
#define EXAMPLE_SNAKE_H

#include <deque>
#include "raylib.h"
#include "utils.h"


class Snake {
private:
    std::deque<Vector2> body = {Vector2{15,10},Vector2{14,10},Vector2{13,10}};
    Vector2 directionV = Vector2{1,0};
    bool addSegment = false;

public:
    void Draw();
    void setDirectionV(Vector2 new_direction);
    Vector2 getDirectionV();
    Vector2 getHead();
    std::deque<Vector2> getBody();
    void updateSnake();

    //checks if there is collision with tail
    bool tailCollision();
    void addNewSegment(){this->addSegment = true;}
    //resets snake position
    void reset();

};


#endif //EXAMPLE_SNAKE_H
