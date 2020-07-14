#ifndef ENEMIES
#define ENEMIES
#include "raylib.h"

namespace Enemies {

	struct ENEMY
	{
		Vector2* pos;
		Texture2D enemy;
		float speed;
		float rotation;
	};
	
	extern Rectangle collider;
	extern ENEMY a;
	extern float posRandX;
	extern float posRandY;
	extern bool enemyPlaced;

	extern void Initialize();
	extern void Load();
	extern void Unload();
	extern void Draw();
	extern Vector2* Create();
	extern void Delete(Vector2* n);
	extern void MoveEnemies();
	extern void AddAsteroid();
}
#endif // !ENEMIES