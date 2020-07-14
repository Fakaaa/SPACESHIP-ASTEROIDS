#ifndef PLAYER
#define PLAYER
#include "raylib.h"

namespace Player {

	struct PJ
	{
		Vector2 pos;
		Texture2D ship;
		float speed;
		int lifes;
		unsigned long int score;
		bool crash;
	};

	//VARIABLES
	extern PJ player;
	extern float inclination;
	extern Rectangle pjShip;
	extern Rectangle* bullets;
	extern bool bulletShoted;
	extern bool shoot;
	extern float time;
	extern bool moreScore;

	extern Vector2 posScore;
	extern int scoreAmount;

	//FUNCIONES
	extern void Initialize();
	extern void Draw();
	extern void LoadText2D();
	extern void Unload();
	extern void PlayerInputs();
	extern Rectangle* CreateBullets();
	extern void DeleteBullet(Rectangle* bullet);
	extern void AddBullet();
	extern void ShotMachineGun();
	extern void GetTime();
	extern void ShowScore();
}
#endif // !PLAYER