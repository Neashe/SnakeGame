#include <iostream>
#include "apple.h"
#include <deque>
#include "raymath.h"

bool elementInDeque(Vector2 new_position,std::deque<Vector2> snakeBody){
    for (unsigned int i = 0;i<snakeBody.size();i++){
        if (Vector2Equals(new_position,snakeBody[i])){
            return true;
        }
    }
    return false;
}
Vector2 generate_random_position(const std::deque<Vector2>& snakeBody){
    while(true){
        auto x = (float)GetRandomValue(0,CELL_IN_ROW-1);
        auto y = (float)GetRandomValue(0,CELL_IN_COL-1);
        Vector2 new_position = {x,y};
        while (elementInDeque(new_position,snakeBody)){
            x = (float)GetRandomValue(0,CELL_IN_ROW-1);
            y = (float)GetRandomValue(0,CELL_IN_COL-1);
            new_position = {x,y};
        }
        return new_position;

    }
}

Apple::Apple(const std::deque<Vector2>& snakeBody) {
    Image image = LoadImage("Graphics/apple.png");
    this->texture = LoadTextureFromImage(image);
    UnloadImage(image);
    this->position = generate_random_position(snakeBody);
}
void Apple::Draw() {
    DrawTexture(this->texture,OFFSET+position.x*(float)CELL_SIZE,OFFSET+position.y*(float)CELL_SIZE,WHITE);
}

Apple::~Apple() {
    UnloadTexture(this->texture);
}

void Apple::update_position(const std::deque<Vector2>& snakeBody) {
    this->position = generate_random_position(snakeBody);
}




