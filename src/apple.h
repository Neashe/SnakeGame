#include <deque>
#include "raylib.h"
#include "utils.h"

#ifndef EXAMPLE_APPLE_H
#define EXAMPLE_APPLE_H

class Apple {
private:
    Vector2 position = {6,7};
    Texture2D texture{};
public:
    explicit Apple(const std::deque<Vector2>& snakeBody);
    void Draw();
    void update_position(const std::deque<Vector2>& snakeBody);
    Vector2 get_position(){
        return this->position;
    }

    ~Apple();

};


#endif //EXAMPLE_APPLE_H
