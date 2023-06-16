#ifndef EXAMPLE_GAME_H
#define EXAMPLE_GAME_H

#include "Snake.h"
#include "apple.h"
#include "raymath.h"
#include <algorithm>

class Game {
private:
    Snake snake = Snake();
    Apple apple = Apple(snake.getBody());
    int gameRunning = true;
    int score = 0;
    int bestScore = 0;
public:
    void Draw();
    //updates game state
    void Update();
    //returns snake object
    Snake &getSnake(){return this->snake;}
    //check if food can be eaten by snake
    void checkFood(){
        if (Vector2Equals(snake.getHead(),apple.get_position())){
            apple.update_position(snake.getBody());
            score +=1;
            snake.addNewSegment();
        }
    }
    void checkCollisionWithBorder(float xBorder, float yBorder);
    void reset();
    void GameOver();
    void runGame();
    void pauseGame();
    [[nodiscard]] bool isRunning() const;
    [[nodiscard]] int getScore() const;
    [[nodiscard]] int getBestScore() const{ return this->bestScore;}

};

#endif //EXAMPLE_GAME_H
