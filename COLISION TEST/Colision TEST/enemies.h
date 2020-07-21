#ifndef ENEMIES
#define ENEMIES
#include "raylib.h"

const int size = 5;

namespace Enemies {

	struct ENEMY
	{
		Vector2* pos;
		Texture2D enemy;
		float speed;
		float rotation;
	};
	
	extern Rectangle colliderA;
	extern Rectangle colliderB;
	extern Rectangle colliderC;
	extern Rectangle colliderD;
	extern ENEMY a;
	extern ENEMY b;
	extern ENEMY c;
	extern ENEMY d;
	extern float posRandX;
	extern float posRandY;
	extern bool aPlaced;
	extern bool bPlaced;
	extern bool cPlaced;
	extern bool dPlaced;

	extern float frameWidth;
	extern float frameHeigth;
	extern Rectangle sourceRec;
	extern Rectangle destRec;
	extern Vector2 origin;

	extern int rotation;

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