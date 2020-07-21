#include <iostream>
#include <time.h>
#include <cmath>
#include "raylib.h"

using namespace std;

//CONSTANTES
const int width = 1920;
const int heigth = 1080;
void simpleMenu();

struct Ent
{
	Vector2 pos;
	float speed;
	Texture2D asteroid;
	float gravityRotation = 0.0f;
	float scaleAst = 0.0f;
	float radius = 0.0f;
};

struct Player
{
	Vector2 pos;
	Texture2D ship;
	Texture2D lifes[3];
	float speed;
	float radius = 0.0f;
};

Player pj;
Ent asteroid;
Ent asteroidM[5];
bool asteroidsPlaced = false;
int alreadyCrash = 0;
float scrollingback = 0.0f;
float inclination = 0.0f;
Vector2 pjShip;
Vector2 collisionAst;
Vector2 lifesV;
int lifes = 0;
char tres = '3';
char dos = '2';
char uno = '1';


Player playerMove(Player player);
Ent placeAsteroids(Ent ast);
void detectCollision();

int main(){

	srand(time(NULL));

	InitWindow(width,heigth, "COLLISIONS");

	pj.pos = { 200,300 };

	pj.speed = 1.5f;
	asteroid.speed = 3.5f;

	SetTargetFPS(120);

	Texture2D background;
	Vector2 vecBackground;
	Vector2 vecBackgroundTwice;

	background = LoadTexture("res/raw/BACKGROUND2.png");
	pj.ship = LoadTexture("res/raw/ship.png");
	pj.lifes[0] = LoadTexture("res/raw/THIRDLIFE.png");
	pj.lifes[1] = LoadTexture("res/raw/SECONDLIFE.png");
	pj.lifes[2] = LoadTexture("res/raw/LASTLIFE.png");

	lifes = 3;

	asteroid.asteroid = LoadTexture("res/raw/ASTEROID.png");

	for (int i = 0; i < 5; i++)
	{
		asteroidM[i].asteroid = LoadTexture("res/raw/ASTEROID.png");
	}

		int score = 0;

	while (!WindowShouldClose())
	{

		scrollingback -= 5.5f;
		pjShip = { pj.pos.x + 45, pj.pos.y + 90 };
		//PJSHIP POSCICION REAL DE LA NAVE (TEXTURA CARGADA)
		collisionAst = { asteroid.pos.x + 50, asteroid.pos.y + 50};
		//COLLISION REAL DEL ASTEROIDE PRINCIPAL

		lifesV = { 100,-60 };

		//asteroid.gravityRotation += 0.2f;
		inclination = 0.0f * GetFrameTime();

		if (scrollingback <= -background.width) 
		{ 
			scrollingback = 0.0f;
		}

		BeginDrawing();
		ClearBackground(BLACK);
		
		vecBackground = { scrollingback, -10.0f };
		vecBackgroundTwice = { background.width + scrollingback ,-10.0f };

		DrawTextureEx(background, vecBackground , 0.0f, 1.0f, WHITE);
		DrawTextureEx(background, vecBackgroundTwice, 0.0f, 1.0f, WHITE);

		DrawTextureEx(asteroid.asteroid, asteroid.pos, asteroid.gravityRotation, 0.5f, GRAY);
		DrawTextureEx(asteroidM[0].asteroid, asteroidM[0].pos, asteroid.gravityRotation, 0.5f, GRAY);
		DrawTextureEx(asteroidM[1].asteroid, asteroidM[1].pos, asteroid.gravityRotation, 0.6f, GRAY);
		DrawTextureEx(asteroidM[2].asteroid, asteroidM[2].pos, asteroid.gravityRotation, 0.9f, GRAY);
		DrawTextureEx(asteroidM[3].asteroid, asteroidM[3].pos, asteroid.gravityRotation, 0.2f, GRAY);
		DrawTextureEx(asteroidM[4].asteroid, asteroidM[4].pos, asteroid.gravityRotation, 0.65f, GRAY);

		if (!asteroidsPlaced)
		{
			asteroid = placeAsteroids(asteroid);
			asteroidM[0] = placeAsteroids(asteroid);
			asteroidM[1] = placeAsteroids(asteroid);
			asteroidM[2] = placeAsteroids(asteroid);
			asteroidM[3] = placeAsteroids(asteroid);
			asteroidM[4] = placeAsteroids(asteroid);
		}
		
		if (asteroidsPlaced)
		{
			asteroid.pos.x = asteroid.pos.x - asteroid.speed;
			asteroidM[0].pos.x = asteroidM[0].pos.x - asteroid.speed;
			asteroidM[1].pos.x = asteroidM[1].pos.x - asteroid.speed;
			asteroidM[2].pos.x = asteroidM[2].pos.x - asteroid.speed;
			asteroidM[3].pos.x = asteroidM[3].pos.x - asteroid.speed;
			asteroidM[4].pos.x = asteroidM[4].pos.x - asteroid.speed;

			if (asteroid.pos.x < -1000)
			{
				asteroidsPlaced = false;
			}
		}

		DrawText("COLLISION MODE (To see colliders and real radius and positions) [F]", 550, 100, 30, GREEN);
		DrawText("SCORE: ", 950, 20, 50, WHITE);
		DrawText(TextFormat("%i", score), 1250, 20, 50, WHITE);
		
		score += 1;

		detectCollision();
		
		DrawText("LIFES: ", 15, 20, 50, GREEN);

		if (lifes == 3)
		{
			DrawTextureEx(pj.lifes[0],lifesV,0.0f,0.5f , RAYWHITE);
		}
		if (lifes == 2)
		{
			DrawTextureEx(pj.lifes[1], lifesV, 0.0f, 0.5f, RAYWHITE);
		}
		if (lifes == 1)
		{
			DrawTextureEx(pj.lifes[2], lifesV, 0.0f, 0.5f, RAYWHITE);
		}
	
		pj = playerMove(pj);
		DrawTextureEx(pj.ship, pj.pos, inclination, 0.45f, LIGHTGRAY);
		
		
		EndDrawing();
	}


	UnloadTexture(background);
	UnloadTexture(pj.ship);
	UnloadTexture(asteroid.asteroid);

	CloseWindow();

	return 0;
}

void simpleMenu()
{
	DrawText("This Is An Hardcore Game...", 550, 500, 60, WHITE);
	DrawText(" [ENTER TO START] | [ESC TO EXIT] ", 565, 640, 40, GREEN);
}

void showLifes()
{


}

Player playerMove(Player player)
{
	if (IsKeyDown(KEY_D))
	{
		player.pos.x += 200.0f * GetFrameTime() * pj.speed;
	}
	if (IsKeyDown(KEY_W))
	{
		player.pos.y -= 300.0f *  GetFrameTime() *pj.speed;
		inclination -= 400.0f * GetFrameTime();
	}
	if (IsKeyDown(KEY_S))
	{
		player.pos.y += 300.0f * GetFrameTime() * pj.speed;
		inclination += 400.0f * GetFrameTime();
	}
	if (IsKeyDown(KEY_A))
	{
		player.pos.x -= 200.0f * GetFrameTime() * pj.speed;
	}
	if (IsKeyDown(KEY_SPACE))
	{
		scrollingback += scrollingback * GetFrameTime() * 0.8f;
		asteroid.speed -= scrollingback * GetFrameTime() * 0.2f;
		asteroidM[0].speed -= scrollingback * GetFrameTime() * 0.2f;
		asteroidM[1].speed -= scrollingback * GetFrameTime() * 0.2f;
		asteroidM[2].speed -= scrollingback * GetFrameTime() * 0.2f;
		asteroidM[3].speed -= scrollingback * GetFrameTime() * 0.2f;
		asteroidM[4].speed -= scrollingback * GetFrameTime() * 0.2f;
	}
	if (IsKeyDown(KEY_F))
	{
		DrawRectangleLines(pjShip.x, pjShip.y, 180, 70, GREEN);
		DrawCircleLines(collisionAst.x, collisionAst.y, 50, GREEN);
		if (CheckCollisionCircles(pjShip,60,collisionAst,50) == true)
		{
			DrawText(" !COLLISION! ", 550, 500, 50, YELLOW);
		}
	}

	return player;
}

Ent placeAsteroids(Ent ast)
{
	float x;
	float y;

	ast.speed = rand() % 3 + 1.2f;
	ast.gravityRotation = rand() % 8 + 4.1f;

	x = rand() % 1000 + 1920;
	y = rand() % 1070 + 10;

	ast.pos.x = x;
	ast.pos.y = y;
	

	asteroidsPlaced = true;

	return ast;
}

void detectCollision()
{
	Rectangle recPlayer;
	//DrawCircleLines(pjShip.x, pjShip.y, 60, GREEN);
	DrawCircleLines(collisionAst.x, collisionAst.y, 50, BLANK);
	DrawRectangleLines(pjShip.x, pjShip.y, 180, 70, BLANK);

	recPlayer.width = 180;
	recPlayer.height = 70;
	recPlayer.x = pjShip.x;
	recPlayer.y = pjShip.y;

	if (CheckCollisionCircleRec(collisionAst,50,recPlayer) == true)
	{
		lifes--;
		DrawText(" !CRASH! ", 550, 500, 150, RED);
	}

	/*
	if (CheckCollisionCircles(pjShip, 60, collisionAst, 50) == true)
	{
		DrawText(" !CRASH! ", 550, 500, 150, RED);
	}*/
}