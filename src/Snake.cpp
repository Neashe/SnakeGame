#include "Snake.h"
#include "raymath.h"

void Snake::updateSnake() {
    if (!addSegment){
        body.pop_back();
    }
    body.push_front(Vector2Add(body[0],directionV));
    addSegment = false;

}

void Snake::setDirectionV(Vector2 new_direction) {
    this->directionV = new_direction;

}

Vector2 Snake::getDirectionV() {
    return this->directionV;
}

Vector2 Snake::getHead() {
    return this->body[0];
}

void Snake::Draw() {
    for (auto & i : body){
        float x = i.x;
        float y = i.y;
        auto segment = Rectangle{(float)OFFSET+x*(float)CELL_SIZE,(float)OFFSET+y*(float)CELL_SIZE,(float)CELL_SIZE,(float)CELL_SIZE};
        DrawRectangleRounded(segment, 0.5, 6, snakeColor);
//        DrawRectangleLinesEx(segment,1,snakeBorderColor);
        DrawRectangleRoundedLines(segment, 0.5, 6, 2, snakeBorderColor);
//        DrawRectangleRoundedLines(segment,0.5,1,1,snakeBorderColor);
    }

}

std::deque<Vector2> Snake::getBody() {
    return this->body;
}

bool Snake::tailCollision() {
    for (unsigned int i = 1; i<this->body.size();i++){
        if (Vector2Equals(this->body[0],this->body[i])){
            return true;
        }
    }
    return false;
}

void Snake::reset() {
    this->body = {Vector2{15,10},Vector2{14,10},Vector2{13,10}};
    this->directionV = Vector2 {1,0};
    this->addSegment = false;
}
