#include "SGScreens.h"
#include <allegro5/allegro_primitives.h>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include <iostream>
// .01 speed
int height = 500;
SGClassicGameOverScreen::SGClassicGameOverScreen() : SGVisualComponent(345, height * -1, .01), yOffset(0), sadSnake(new SGIndivSpriteComponent(400, 0, .08)) {
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame0.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame1.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame2.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame3.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame4.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame5.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame6.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame7.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame8.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame9.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame10.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame11.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame12.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame13.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame14.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame15.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame16.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame17.png"));
	sadSnake->AddFrame(al_load_bitmap("Assets/GameOver/CryingSnake/frame18.png"));

	gameOverText = new SGTextComponent(550, 550, 95, "Assets/Fonts/ArcadeClassic.ttf", al_map_rgb(0, 0, 0), "GAME OVER");
	restartText = new SGTextComponent(750, 900, 20, "Assets/Fonts/PressStart2P.ttf", al_map_rgb(255, 255, 255), "Press R to restart");
	exitText = new SGTextComponent(750, 900, 20, "Assets/Fonts/PressStart2P.ttf", al_map_rgb(255, 255, 255), "Press ESC to exit");
	highScoresText = new SGTextComponent(700, 900, 30, "Assets/Fonts/PressStart2P.ttf", al_map_rgb(0, 200, 0), "High Scores:");
	// highScoresOneText = new SGTextComponent(725, 900, 25, "Assets/Fonts/PressStart2P.ttf", al_map_rgb(0, 255, 0), "~");
	// highScoresTwoText = new SGTextComponent(725, 900, 25, "Assets/Fonts/PressStart2P.ttf", al_map_rgb(0, 255, 0), "~");
	// highScoresThreeText = new SGTextComponent(725, 900, 25, "Assets/Fonts/PressStart2P.ttf", al_map_rgb(0, 255, 0), "~");
	highScoresOneText = new SGTextComponent(725, 900, 25, "Assets/Fonts/PressStart2P.ttf", al_map_rgb(0, 200, 200), "~");
	highScoresTwoText = new SGTextComponent(725, 900, 25, "Assets/Fonts/PressStart2P.ttf", al_map_rgb(0, 200, 200), "~");
	highScoresThreeText = new SGTextComponent(725, 900, 25, "Assets/Fonts/PressStart2P.ttf", al_map_rgb(0, 200, 200), "~");
}
SGClassicGameOverScreen::~SGClassicGameOverScreen() {}
void SGClassicGameOverScreen::Draw() {
	if (al_get_time() - GetTime() > GetWaitingTime() && GetYPos() + yOffset < 165) {
		yOffset += 10;
		SetTime(al_get_time());
		sadSnake->SetYPos(GetYPos() + yOffset + 115);
		gameOverText->SetYPos(GetYPos() + yOffset);
		restartText->SetYPos(GetYPos() + yOffset + 400);
		exitText->SetYPos(GetYPos() + yOffset + 450);
		highScoresText->SetYPos(GetYPos() + yOffset + 125);

		highScoresOneText->SetYPos(GetYPos() + yOffset + 175);
		highScoresTwoText->SetYPos(GetYPos() + yOffset + 225);
		highScoresThreeText->SetYPos(GetYPos() + yOffset + 275);
	}
	int rectangleHeight = height;
	int rectangleWidth = 800;
	al_draw_filled_rounded_rectangle(GetXPos(), yOffset + GetYPos(), GetXPos() + rectangleWidth, yOffset + GetYPos() + rectangleHeight, 10, 10, al_map_rgb(128, 128, 128));
	al_draw_rounded_rectangle(GetXPos(), yOffset + GetYPos(), GetXPos() + rectangleWidth, yOffset + GetYPos() + rectangleHeight, 10, 10, al_map_rgb(0, 0, 0), 2);
	sadSnake->Draw();
	gameOverText->Draw();
	restartText->Draw();
	exitText->Draw();
	highScoresText->Draw();

	GetHighScores();
	highScoresOneText->Draw();
	highScoresTwoText->Draw();
	highScoresThreeText->Draw();
}

void SGClassicGameOverScreen::AddScore(int score) {
	std::ofstream outputFile;
	outputFile.open("ScoreHistory/classic_mode_scores.txt", std::ios::app);
	outputFile << score << std::endl;
	outputFile.close();
}

void SGClassicGameOverScreen::GetHighScores() {
	std::vector<int> scores;
	std::ifstream inputFile;
	inputFile.open("ScoreHistory/classic_mode_scores.txt");
	std::string line;
	while (!inputFile.eof()) {
		std::getline(inputFile, line);
		if (line.size() == 0) continue;
		scores.push_back(std::stoi(line));
	}
	sort(scores.begin(), scores.end());
	int length = (int)scores.size();
	int score;
	char text[128];
	if (length > 2) {
		score = scores.at(length - 3);
		snprintf(text, 128, "%d", score);
		const char* scoreThreeInput = text;
		highScoresThreeText->SetText(scoreThreeInput);
	}
	if (length > 1) {
		score = scores.at(length - 2);
		snprintf(text, 128, "%d", score);
		const char* scoreTwoInput = text;
		highScoresTwoText->SetText(scoreTwoInput);
	}
	if (length > 0) {
		score = scores.at(length - 1);
		snprintf(text, 128, "%d", score);
		const char* scoreOneInput = text;
		highScoresOneText->SetText(scoreOneInput);
	}
}