#include <raylib.h>
#include <iostream>
#include <string>
using namespace std;

class Ball {
public:
    float pos_x;
    float pos_y;
    int speed_x;
    int speed_y;
    int radius;

    // constructor
    Ball(float tempX, float tempY, int tempSpeedX, int tempSpeedY, int rad) {
        pos_x = tempX;
        pos_y = tempY;
        speed_x = tempSpeedX;
        speed_y = tempSpeedY;
        radius = rad;
    }

    void drawBall() {
        DrawCircle(pos_x, pos_y, radius, RED);
    }

    void update() {
        pos_x += speed_x;
        pos_y += speed_y;
    }
};
void movement(int&x, int&y);
void checkScore(float x, float ScreenWidth, int radius, int& speedX, int & playerScore, int & enemyScore, float& ballY, float & ballX, Ball& ball, bool& gameOver);
void checkBounce(float y, float screenHeight, int radius, int& speedY);
void ballBouncer(
    float& x,
    float& y,
    int radius,
    int& speedX,
    Rectangle& paddle1,
    Rectangle& paddle2,
    Sound pongSound

);
void playerBoundary(int&x, int&y, const int & SCREEN_HEIGHT, int&enemyY);
void enemyMovement(float y, int& enemyY);


int main() {
    int playerScore = 0;
    int enemyScore = 0;
    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 800;
    int playerX = 10;
    int playerY = SCREEN_HEIGHT / 2 - 60;
    int enemyX= SCREEN_WIDTH - 35;
    int enemyY = SCREEN_HEIGHT / 2 - 60;
    bool gameOver =false;
    double gameOverStartTime = 0;

    InitAudioDevice();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "PONG GAME");
    SetTargetFPS(60);
    const string assetDirectory = string(GetApplicationDirectory()) + "../assets/";
    Sound pongSound = LoadSound((assetDirectory + "pongsfx.mp3").c_str());
    Music bgMusic = LoadMusicStream((assetDirectory + "bgSong.mp3").c_str());
    Texture2D background = LoadTexture((assetDirectory + "tennisBg.png").c_str());
    Rectangle source = {0,0,float(background.width), float(background.height)};
    Rectangle destination = {0,0, float(SCREEN_WIDTH), float(SCREEN_HEIGHT)};

    Ball ball(600, 400, 7, 7, 20);
    Rectangle paddle1 = {playerX, playerY, 25, 120};
    Rectangle paddle2 = {enemyX, enemyY, 25,120};

PlayMusicStream(bgMusic);


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        UpdateMusicStream(bgMusic);
        DrawTexturePro(background, source, destination, {0,0},0, WHITE);
        DrawText(TextFormat("Player Score: %d", playerScore), 10, 30,15,WHITE);
        DrawText(TextFormat("Enemy Score: %d", enemyScore), SCREEN_WIDTH -200, 30,15,WHITE);

        if (!gameOver) {
            ball.update();
            checkBounce(ball.pos_y, SCREEN_HEIGHT, ball.radius, ball.speed_y);
            checkScore(ball.pos_x, SCREEN_WIDTH, ball.radius, ball.speed_x, playerScore, enemyScore, ball.pos_y, ball.pos_x, ball, gameOver);
        }
        ball.drawBall();
        DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 30, WHITE);

        if (!gameOver) {
            playerBoundary(playerX, playerY, SCREEN_HEIGHT, enemyY);
            movement(playerX, playerY);
            enemyMovement(ball.pos_y, enemyY);

            paddle1.x = playerX;
            paddle1.y = playerY;
            paddle2.x =enemyX;
            paddle2.y = enemyY;

            DrawRectangleRec(paddle1, WHITE);
            DrawRectangleRec(paddle2, WHITE);
            ballBouncer(ball.pos_x,ball.pos_y,ball.radius, ball.speed_x, paddle1,paddle2, pongSound);
        } else {
            const char* winner = playerScore >= 3 ? "Player Wins!" : "Enemy Wins!";
            const char* finalScore = TextFormat("Final Score: %d - %d", playerScore, enemyScore);
           DrawText(winner, SCREEN_WIDTH / 2 - MeasureText(winner, 40) / 2, SCREEN_HEIGHT / 2 - 180, 40, WHITE);
DrawText(finalScore, SCREEN_WIDTH / 2 - MeasureText(finalScore, 25) / 2, SCREEN_HEIGHT / 2 - 90, 25, WHITE);

            if (gameOverStartTime == 0) {
                gameOverStartTime = GetTime();
            } else if (GetTime() - gameOverStartTime >= 3.0) {
                playerScore = 0;
                enemyScore = 0;
                ball.pos_x = SCREEN_WIDTH / 2;
                ball.pos_y = SCREEN_HEIGHT / 2;
                gameOver = false;
                gameOverStartTime = 0;
            }
        }

        DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, WHITE);

        EndDrawing();
    }
    UnloadTexture(background);
    UnloadSound(pongSound);

    UnloadMusicStream(bgMusic);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}

void checkBounce(float y, float screenHeight, int radius, int& speedY) {

    // Top of screen
    if (y - radius <= 0) {
        speedY = -speedY;
    }

    // Bottom of screen
    if (y + radius >= screenHeight) {
        speedY = -speedY;
    }

}
void checkScore(float x, float SCREEN_WIDTH, int radius, int& speedX, int & playerScore, int & enemyScore, float& ballY, float & ballX, Ball& ball, bool& gameOver){
   if (x - radius > SCREEN_WIDTH){
        playerScore++;
        ball.pos_x = 600;
        ball.pos_y = 400;
        speedX = -speedX;
    }

    if (x + radius < 0)
    {
        enemyScore++;
        ball.pos_x = 600;
        ball.pos_y = 400;
        speedX = -speedX;
    }

    if (playerScore >= 3 || enemyScore >= 3) {
        gameOver = true;
    }
}
void movement(int&x, int&y){
    if (IsKeyDown(KEY_W) )
    {
        y-=10;
    }
    if (IsKeyDown(KEY_S))
    {
        y+=10;
    }
}

void playerBoundary(int& x, int& y, const int& SCREEN_HEIGHT, int&enemyY)
{
    // bottom boundary
    if (y + 120 > SCREEN_HEIGHT)
    {
        y = SCREEN_HEIGHT - 120;
    }

    // top boundary
    if (y < 0)
    {
        y = 0;
    }

        if (enemyY + 120 > SCREEN_HEIGHT)
    {
        enemyY = SCREEN_HEIGHT - 120;
    }

    // top boundary
    if (enemyY < 0)
    {
        enemyY = 0;
    }
}


void ballBouncer(
    float& x,
    float& y,
    int radius,
    int& speedX,
    Rectangle& paddle1,
    Rectangle& paddle2,
    Sound pongSound
) {
    Vector2 ballPosition = {x, y};

if (CheckCollisionCircleRec(
    ballPosition,
    radius,
    paddle1
)) 
{
    if (speedX < 0) 
    {
        speedX = -speedX;
        PlaySound(pongSound);
    }
}
if(CheckCollisionCircleRec(ballPosition,radius, paddle2)){
     if (speedX > 0) 
    {
        speedX = -speedX;
        PlaySound(pongSound);
    }
}
}
void enemyMovement(float y, int& enemyY){
    if (y > enemyY)
{
    enemyY += 10/1.5;
}

if (y < enemyY)
{
    enemyY -= 10/1.5;
}
}
