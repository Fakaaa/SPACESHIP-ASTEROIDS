#include "enemies.h"
#include "screen.h"

namespace Enemies {

	ENEMY a;
	ENEMY b;
	ENEMY c;
	ENEMY d;
	float posRandX = 0;
	float posRandY = 0;
	bool aPlaced = false;
	bool bPlaced = false;
	bool cPlaced = false;
	bool dPlaced = false;
	Rectangle colliderA;
	Rectangle colliderB;
	Rectangle colliderC;
	Rectangle colliderD;

	float frameWidth = 0;
	float frameHeigth = 0;
	Rectangle sourceRec;
	Rectangle destRec;
	Vector2 origin = {0.0f,0.0f};

	int rotation = 0;

	void Initialize() {
		Load();
		a.speed = 2.5f;
		a.rotation = 1.5f;
		b.speed = 2.5f;
		b.rotation = 1.5f;
		c.speed = 2.5f;
		c.rotation = 1.5f;
		d.speed = 2.5f;
		d.rotation = 1.5f;
		colliderA.x = 0;
		colliderA.y = 0;
		colliderB.x = 0;
		colliderB.y = 0;
		colliderC.x = 0;
		colliderC.y = 0;
		colliderD.x = 0;
		colliderD.y = 0;

		frameWidth = a.enemy.width;
		frameWidth = a.enemy.height;
		sourceRec = { 0.0f, 0.0f,frameWidth,frameHeigth};
		destRec = { static_cast<float>(Screen::width / 2),static_cast<float>(Screen::width / 2), frameWidth*2,frameHeigth*2};
		origin = {frameWidth,frameHeigth};
		rotation = 0;

		colliderA.width = a.enemy.width / 2;
		colliderA.height = a.enemy.height / 2;
		colliderB.width = b.enemy.width / 2;
		colliderB.height = b.enemy.height / 2;
		colliderC.width = c.enemy.width / 2;
		colliderC.height = c.enemy.height / 2;
		colliderD.width = d.enemy.width / 2;
		colliderD.height = d.enemy.height / 2;
	}

	void Load() {
		a.enemy = LoadTexture("res/raw/ASTEROID.png");
		b.enemy = LoadTexture("res/raw/ASTEROID.png");
		c.enemy = LoadTexture("res/raw/ASTEROID.png");
		d.enemy = LoadTexture("res/raw/ASTEROID.png");
	}

	void Unload() {
		UnloadTexture(a.enemy);
		UnloadTexture(b.enemy);
		UnloadTexture(c.enemy);
		UnloadTexture(d.enemy);
	}

	void Draw() {

		if(aPlaced)
			destRec = { a.pos->x, a.pos->y, frameWidth * 2,frameHeigth * 2 };

		if (aPlaced) {
		DrawTextureEx(a.enemy, *a.pos, a.rotation, 0.5f, LIGHTGRAY);
		//DrawTexturePro(a.enemy,sourceRec,destRec,origin,(float)rotation,WHITE);
		//DrawRectangleLinesEx(colliderA, 5, RED);
		}
		if (bPlaced) {
		DrawTextureEx(b.enemy, *b.pos, b.rotation, 0.5f, LIGHTGRAY);
		//DrawRectangleLinesEx(colliderB, 5, RED);
		}
		if (cPlaced) {
		DrawTextureEx(c.enemy, *c.pos, c.rotation, 0.5f, LIGHTGRAY);
		//DrawRectangleLinesEx(colliderC, 5, RED);
		}
		if (dPlaced) {
		DrawTextureEx(d.enemy, *d.pos, d.rotation, 0.5f, LIGHTGRAY);
		//DrawRectangleLinesEx(colliderD, 5, RED);
		}
	}

	void MoveEnemies() {
		if (aPlaced) {
			if (a.pos->x <= -a.enemy.width) {
				Delete(a.pos);
				aPlaced = false;
			}
			else {
				a.pos->x -= a.speed;
				colliderA.x -= a.speed;
				//a.rotation += (static_cast<float>(20 * GetFrameTime()));
			}
		}
		else {
			AddAsteroid();
			colliderA.x = a.pos->x;
			colliderA.y = a.pos->y;
		}

		if (bPlaced) {
			if (b.pos->x <= -b.enemy.width) {
				Delete(b.pos);
				bPlaced = false;
			}
			else {
				b.pos->x -= b.speed;
				colliderB.x -= b.speed;
				//b.rotation += (static_cast<float>(12 * GetFrameTime()));
			}
		}
		else {
			AddAsteroid();
			colliderB.x = b.pos->x;
			colliderB.y = b.pos->y;
		}

		if (cPlaced) {
			if (c.pos->x <= -c.enemy.width) {
				Delete(c.pos);
				cPlaced = false;
			}
			else {
				c.pos->x -= c.speed;
				colliderC.x -= c.speed;
				//c.rotation += (static_cast<float>(12 * GetFrameTime()));
			}
		}
		else {
			AddAsteroid();
			colliderC.x = c.pos->x;
			colliderC.y = c.pos->y;
		}
			
		if (dPlaced) {
			if (d.pos->x <= -d.enemy.width) {
				Delete(d.pos);
				dPlaced = false;
			}
			else {
				d.pos->x -= d.speed;
				colliderD.x -= d.speed;
				//d.rotation += (static_cast<float>(12 * GetFrameTime()));
			}
		}
		else {
			AddAsteroid();
			colliderD.x = d.pos->x;
			colliderD.y = d.pos->y;
		}
	}

	void AddAsteroid() {
		if (!aPlaced) {
			a.pos = Create();
			//a.rotation = GetRandomValue(static_cast<int>(0.5f), static_cast<int>(300.0f));
			aPlaced = true;
		}
		if (!bPlaced) {
			b.pos = Create();
			//b.rotation = GetRandomValue(static_cast<int>(0.5f), static_cast<int>(300.0f));
			bPlaced = true;
		}
		if (!cPlaced) {
			c.pos = Create();
			//c.rotation = GetRandomValue(static_cast<int>(0.5f), static_cast<int>(300.0f));
			cPlaced = true;
		}
		if (!dPlaced) {
			d.pos = Create();
			//d.rotation = GetRandomValue(static_cast<int>(0.5f), static_cast<int>(300.0f));
			dPlaced = true;
		}
	}

	Vector2* Create() {
		posRandX = GetRandomValue(static_cast<int>(Screen::width + a.enemy.width), static_cast<int>(Screen::width + a.enemy.width + 50));
		posRandY = GetRandomValue(0, static_cast<int>(Screen::heigth - a.enemy.height));

		return new Vector2 {posRandX,posRandY};
	}

	void Delete(Vector2* n) {
		if (n)
			delete n;
	}
}