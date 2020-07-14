#include "enemies.h"
#include "screen.h"

namespace Enemies {

	ENEMY a;
	float posRandX = 0;
	float posRandY = 0;
	bool enemyPlaced = false;
	Rectangle collider;

	void Initialize() {
		a.speed = 2.5f;
		a.rotation = 1.5f;
		collider.x = 0;
		collider.y = 0;
		Load();
		collider.width = a.enemy.width / 2;
		collider.height = a.enemy.height / 2;
	}

	void Load() {
		a.enemy = LoadTexture("res/raw/ASTEROID.png");
	}

	void Unload() {
		UnloadTexture(a.enemy);
	}

	void Draw() {
		DrawTextureEx(a.enemy, *a.pos, 0, 0.5f, LIGHTGRAY);
		//DrawRectangleLinesEx(collider, 5, RED);
	}
	
	void MoveEnemies() {
		if (enemyPlaced) {
			if (a.pos->x <= -a.enemy.width) {
				Delete(a.pos);
				enemyPlaced = false;
			}
			else {
				a.pos->x -= a.speed;
				collider.x-= a.speed;
				a.rotation+= (8* GetFrameTime());
			}
		}
		else {
			AddAsteroid();
			collider.x = a.pos->x;
			collider.y = a.pos->y;
		}
	}

	void AddAsteroid() {
		a.pos = Create();
		enemyPlaced = true;
	}

	Vector2* Create() {
		posRandX = GetRandomValue(Screen::width + a.enemy.width, (Screen::width + a.enemy.width + 50));
		posRandY = GetRandomValue(0, Screen::heigth - a.enemy.height);
		a.rotation = GetRandomValue(static_cast<int>(0.5f), static_cast<int>(300.0f));

		return new Vector2 {posRandX,posRandY};
	}

	void Delete(Vector2* n) {
		if (n)
			delete n;
	}
}