#include "gameLoop.h"
#include <iostream>
using namespace std;

namespace GLoop {

	void Main_Loop() {

		Initialize_All();
		SetTargetFPS(120);

		while (!WindowShouldClose()){

			Enemies::rotation++;

			Bg::Parallax_Ini();

			BeginDrawing();

			Draw_All();

			EndDrawing();
		}

		Unload_All();
		CloseWindow();
	}
	
	void Move_Enemies() {
		Enemies::MoveEnemies();
	}

	void Initialize_All() {
		
		Screen::StartWindow();

		Player::Initialize();

		Enemies::Initialize();

		Bg::Load();

	}
	
	void DestroyAsteroids() {
		
		if (CheckCollisionRecs(*Player::bullets, Enemies::colliderA)) {

			Player::time = 0;
			Player::moreScore = true;
			Player::posScore = { Enemies::a.pos->x,Enemies::a.pos->y };

			if (Enemies::a.pos) {
				Enemies::Delete(Enemies::a.pos);
				Enemies::aPlaced = false;
			}
			if (Player::bullets) {
				Player::DeleteBullet(Player::bullets);
				Player::bulletShoted = false;
				Player::shoot = false;
			}
			Player::player.score += Player::scoreAmount;
		}

		if (CheckCollisionRecs(*Player::bullets, Enemies::colliderB)) {

			Player::time = 0;
			Player::moreScore = true;
			Player::posScore = { Enemies::b.pos->x,Enemies::b.pos->y };

			if (Enemies::b.pos) {
				Enemies::Delete(Enemies::b.pos);
				Enemies::bPlaced = false;
			}
			if (Player::bullets) {
				Player::DeleteBullet(Player::bullets);
				Player::bulletShoted = false;
				Player::shoot = false;
			}
			Player::player.score += Player::scoreAmount;
		}

		if (CheckCollisionRecs(*Player::bullets, Enemies::colliderC)) {

			Player::time = 0;
			Player::moreScore = true;
			Player::posScore = { Enemies::c.pos->x,Enemies::c.pos->y };

			if (Enemies::c.pos) {
				Enemies::Delete(Enemies::c.pos);
				Enemies::cPlaced = false;
			}
			if (Player::bullets) {
				Player::DeleteBullet(Player::bullets);
				Player::bulletShoted = false;
				Player::shoot = false;
			}
			Player::player.score += Player::scoreAmount;
		}

		if (CheckCollisionRecs(*Player::bullets, Enemies::colliderD)) {

			Player::time = 0;
			Player::moreScore = true;
			Player::posScore = { Enemies::d.pos->x,Enemies::d.pos->y };

			if (Enemies::d.pos) {
				Enemies::Delete(Enemies::d.pos);
				Enemies::dPlaced = false;
			}
			if (Player::bullets) {
				Player::DeleteBullet(Player::bullets);
				Player::bulletShoted = false;
				Player::shoot = false;
			}
			Player::player.score += Player::scoreAmount;
		}
	}

	void Check_Physichs() {
		if (CheckCollisionRecs(Player::pjShip, Enemies::colliderA)) {
			DrawText("Colision!", Screen::width / 2, Screen::heigth / 2, 20, WHITE);
		}

		if (Player::bullets) {
			DestroyAsteroids();
		}
		Player::ShotMachineGun();
	}

	void Draw_All() {
		ClearBackground(BLACK);

		Bg::Parallax_Draw();

		Check_Physichs();

		Player::ShowScore();

		Move_Enemies();

		Inputs();

		Enemies::Draw();

		Player::Draw();

		Bg::Parallax_End();

		Player::GetTime();
	}

	void Inputs() {
		Player::PlayerInputs();

		if (IsKeyPressed(KEY_ESCAPE))
			WindowShouldClose();
	}

	void Unload_All() {
		Bg::Unload();
		Player::Unload();
		Enemies::Unload();
	}
}