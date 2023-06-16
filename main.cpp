#include <iostream>
#include "raylib.h"
#include "src/apple.h"
#include "src/Game.h"


double lastUpdateTime = 0;

bool eventTriggered(double interval){
    double currentTime = GetTime();
    if (currentTime-lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}


int main(){

    InitWindow(2*OFFSET+CELL_SIZE*CELL_IN_ROW,2*OFFSET+CELL_SIZE*CELL_IN_COL,"Snake Game");
    Image snakeImage=LoadImage("Graphics/snake.png");
    SetWindowIcon(snakeImage);
    UnloadImage(snakeImage);
    SetTargetFPS(80);
    Texture2D grassTexture = LoadTexture("Graphics/grass.png");

    Game game = Game();

    while(!WindowShouldClose()){
        BeginDrawing();
        
        if (eventTriggered(0.15)){
            game.Update();
        }
        if (IsKeyPressed(KEY_UP)&& game.getSnake().getDirectionV().y !=1){
            game.getSnake().setDirectionV(Vector2{0,-1});
            game.runGame();
        }
        if (IsKeyPressed(KEY_DOWN) && game.getSnake().getDirectionV().y !=-1){
            game.getSnake().setDirectionV(Vector2{0,1});
            game.runGame();
        }
        if (IsKeyPressed(KEY_LEFT)&& game.getSnake().getDirectionV().x !=1){
            game.getSnake().setDirectionV(Vector2{-1,0});
            game.runGame();
        }
        if (IsKeyPressed(KEY_RIGHT)&& game.getSnake().getDirectionV().x !=-1){
            game.getSnake().setDirectionV(Vector2{1,0});
            game.runGame();
        }
        if (IsKeyPressed(KEY_SPACE)){
            if (game.isRunning()) game.pauseGame(); else game.runGame();
        }
        ClearBackground(GREEN);
        DrawTexture(grassTexture,0,0,WHITE);
        //draw border
        DrawRectangleLinesEx(Rectangle{OFFSET-5,OFFSET-5, CELL_SIZE*CELL_IN_ROW+10,CELL_SIZE*CELL_IN_COL+10},5,borderColor);
        //print score

        DrawText(TextFormat("Score: %i",game.getScore()),OFFSET-5,20,40,borderColor);
        DrawText(TextFormat("Best score: %i",game.getBestScore()),CELL_IN_ROW*CELL_SIZE-2*OFFSET,20,40,borderColor);

        game.Draw();

        EndDrawing();

    }
    CloseWindow();
    UnloadTexture(grassTexture);

}

