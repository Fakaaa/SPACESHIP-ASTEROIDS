#include "screen.h"

namespace Screen {

	const int width = 1920;
	const int heigth = 1080;

	void StartWindow() {

		InitWindow(width, heigth, "Space Ship Invade!");
	}
}