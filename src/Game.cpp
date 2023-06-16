#include "Game.h"

void Game::Draw() {
    snake.Draw();
    apple.Draw();

}

void Game::Update() {
    if (gameRunning){
        snake.updateSnake();
        this->checkFood();
        this->checkCollisionWithBorder((float) CELL_IN_ROW, (float) CELL_IN_COL);
    }

}

void Game::reset() {
    snake = Snake();
    apple.update_position(snake.getBody());
}

void Game::checkCollisionWithBorder(float xBorder, float yBorder) {
    //with border
    if (snake.getHead().x == -1 || snake.getHead().x == xBorder
    || snake.getHead().y == -1 || snake.getHead().y == yBorder){
        GameOver();
    }
    //with tail
    if (snake.tailCollision()){
        GameOver();
    }
}

void Game::GameOver() {
    this->snake.reset();
    this->apple.update_position(snake.getBody());
    this->gameRunning = false;
    this->bestScore = std::max(score,bestScore);
    this->score = 0;
}

void Game::runGame() {
    this->gameRunning = true;
}

bool Game::isRunning() const {
    return this->gameRunning;
}

void Game::pauseGame() {
    this->gameRunning = false;
}

int Game::getScore() const {
    return this->score;
}
