#ifndef GAMELOOP
#define GAMELOOP
#include "player.h"
#include "enemies.h"
#include "screen.h"
#include "background.h"
#include "raylib.h"

namespace GLoop {

	extern void Initialize_All();
	extern void Unload_All();
	extern void Inputs();
	extern void Draw_All();
	extern void Main_Loop();
	extern void Move_Enemies();
	extern void Check_Physichs();
}
#endif // !GAMELOOP