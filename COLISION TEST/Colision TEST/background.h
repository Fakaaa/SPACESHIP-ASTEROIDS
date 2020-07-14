#ifndef BACKGROUND
#define BACKGROUND
#include "raylib.h"

namespace Bg {

	extern Texture2D background;
	extern Vector2 vecBackground;
	extern Vector2 vecBackgroundTwice;
	extern float scrollingback;
	extern int iterator_Bg;

	extern void Load();
	extern void Unload();
	extern void Parallax_Ini();
	extern void Parallax_Draw();
	extern void Parallax_End();
}

#endif // !BACKGROUND