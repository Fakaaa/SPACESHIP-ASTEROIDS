#include "background.h"

namespace Bg {

	Texture2D background;
	Vector2 vecBackground;
	Vector2 vecBackgroundTwice;
	float scrollingback = 0.0f; 
	int iterator_Bg = 0;

	void Load() {
		background = LoadTexture("res/raw/BACKGROUND2.png");
	}
	
	void Unload() {
		UnloadTexture(background);
	}

	void Parallax_Ini() {
		iterator_Bg = 0;
		scrollingback -= 5.5f;

		if (scrollingback <= -background.width){
			scrollingback = 0.0f;
		}
	}

	void Parallax_Draw() {
		vecBackground = { scrollingback, -10.0f };
		vecBackgroundTwice = { background.width + scrollingback ,-10.0f };

		DrawTextureEx(background, vecBackground, 0.0f, 1.0f, WHITE);
		DrawTextureEx(background, vecBackgroundTwice, 0.0f, 1.0f, WHITE);
	}

	void Parallax_End() {
		scrollingback = scrollingback - iterator_Bg;
		iterator_Bg++;
	}
}