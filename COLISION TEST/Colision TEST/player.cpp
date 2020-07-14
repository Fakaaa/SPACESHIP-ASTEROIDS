#include "player.h"
#include "screen.h"

using namespace Screen;

namespace Player {

	PJ player;
	float inclination = 0.0f; 
	Rectangle pjShip;
	Rectangle* bullets;
	bool bulletShoted = false;
	bool shoot = false;
	bool moreScore = false;
	float time = 0;

	Vector2 posScore;
	float timeToDestroy = 0.5f;
	int fontSize = 50;
	int scoreAmount = 150;

	void LoadText2D() {
		player.ship = LoadTexture("res/raw/ship.png");
	}

	void Initialize() {
		player.pos = { 200,300 };
		player.speed = 1.5f;
		player.lifes = 3;
		player.score = 0; 
		pjShip.width = 180;
		pjShip.height = 70;
		LoadText2D();
	}

	void DeleteBullet(Rectangle* bullet) {
		if (bullet)
			delete bullet;
	}

	void Draw() {
		DrawText(FormatText("SCORE: %i", player.score), 800, 20, 50, WHITE);
		DrawText(FormatText ("LIFES: %i", player.lifes), 25, 20, 40, GREEN);
		DrawTextureEx(player.ship, player.pos,inclination, 0.45f, LIGHTGRAY);
		if (bulletShoted) {
			//DrawRectangle(static_cast<int>(bullets->x), static_cast<int>(bullets->y), static_cast<int>(bullets->width), static_cast<int>(bullets->height), ORANGE);
			DrawRectangleGradientEx(*bullets, WHITE, YELLOW, ORANGE, RED);
		}
	}

	Rectangle* CreateBullets() {
		return new Rectangle { (player.pos.x + (player.ship.width / 3)) , (player.pos.y + 150), 30 , 5};
	}

	void ShotMachineGun() {
		if (bulletShoted) {
			if (bullets->x > width) {
				DeleteBullet(bullets);
				bulletShoted = false;
				shoot = false;
			}
			else {
				bullets->x += 20;
			}
		}
		else {
			if (shoot) {
				AddBullet();
			}
		}
	}

	void AddBullet() {
		bullets = CreateBullets();
		bulletShoted = true;
	}

	void GetTime() {
		time += GetFrameTime();
	}

	void ShowScore() {
		if (moreScore) {
			DrawText("+150", static_cast<int>(posScore.x), static_cast<int>(posScore.y), fontSize, GREEN);
		}

		if (time >= timeToDestroy && moreScore) {
			time = 0;
			moreScore = false;
		}
	}

	void PlayerInputs() {
		
		pjShip.x = { player.pos.x + 45};
		pjShip.y = { player.pos.y + 90};

		if (IsKeyDown(KEY_D)){
			player.pos.x += 200.0f * GetFrameTime() * player.speed;
		}
		if (IsKeyDown(KEY_W)){
			player.pos.y -= 300.0f * GetFrameTime() * player.speed;
			inclination -= (5.0f * GetFrameTime());
		}
		if (IsKeyDown(KEY_S)){
			player.pos.y += 300.0f * GetFrameTime() * player.speed;
			inclination += (5.0f * GetFrameTime());
		}
		if (IsKeyDown(KEY_A)){
			player.pos.x -= 200.0f * GetFrameTime() * player.speed;
		}
		if (IsKeyDown(KEY_F)){
			DrawRectangleLines(pjShip.x, pjShip.y, pjShip.width, pjShip.height, GREEN);
		}
		if (IsKeyDown(KEY_SPACE)) {
			shoot = true;
		}
		GetTime();
	}

	void Unload() {
		UnloadTexture(player.ship);
	}
}