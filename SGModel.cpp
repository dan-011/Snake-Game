#include "SGModel.h"
#include "SGCell.h"
#include "SGTextComponent.h"
#include <cstdlib>

SGAbstractModel::~SGAbstractModel() {
	for (auto component : visualComponents) {
		delete component;
	}
}
SGVisualComponent* SGAbstractModel::GetVisualComponentAt(int index) {
	return visualComponents.at(index);
}
void SGAbstractModel::AddVisualComponent(SGVisualComponent* component) {
	visualComponents.push_back(component);
}
int SGAbstractModel::GetNumComponents() const {
	return (int)visualComponents.size();
}
double SGAbstractModel::GetTickTime() const {
	return 0;
}
void SGAbstractModel::SetTickTime(double time) {}

#include <fstream>
SGStartupModel::SGStartupModel() {
	SGIndivSpriteComponent* background = new SGIndivSpriteComponent(0, 0, .12);
	background->AddFrame(al_load_bitmap("Assets/Startup/StartupBackground/ColorLess/frame0.png"));
	background->AddFrame(al_load_bitmap("Assets/Startup/StartupBackground/ColorLess/frame1.png"));
	background->AddFrame(al_load_bitmap("Assets/Startup/StartupBackground/ColorLess/frame2.png"));
	background->AddFrame(al_load_bitmap("Assets/Startup/StartupBackground/ColorLess/frame3.png"));
	background->AddFrame(al_load_bitmap("Assets/Startup/StartupBackground/ColorLess/frame4.png"));
	/*background->AddFrame(al_load_bitmap("Assets/Startup/StartupBackground/Colorful/frame0.png"));
	background->AddFrame(al_load_bitmap("Assets/Startup/StartupBackground/Colorful/frame1.png"));
	background->AddFrame(al_load_bitmap("Assets/Startup/StartupBackground/Colorful/frame2.png"));
	background->AddFrame(al_load_bitmap("Assets/Startup/StartupBackground/Colorful/frame3.png"));
	background->AddFrame(al_load_bitmap("Assets/Startup/StartupBackground/Colorful/frame4.png"));*/
	AddVisualComponent(background);

	SGIndivSpriteComponent* snake = new SGIndivSpriteComponent(550, 300, .12);
	snake->AddFrame(al_load_bitmap("Assets/Startup/StartupSnake.png"));
	AddVisualComponent(snake);

	SGTextComponent* title = new SGTextComponent(460, 100, 200, "Assets/Fonts/orange_juice.ttf", al_map_rgb(255, 255, 255), "SNAKE");
	AddVisualComponent(title);

	SGTextComponent* enterToPlay = new SGTextComponent(460, 760, 30, "Assets/Fonts/PressStart2P.ttf", al_map_rgb(255, 255, 255), "Press ENTER to start");
	AddVisualComponent(enterToPlay);
}
SGStartupModel::~SGStartupModel() {}

SGFirstGameModel::SGFirstGameModel() : xOffset(250), yOffset(75), tickTime(0.1), gameStart(false), score(0), gameOver(false) {
	SGIndivSpriteComponent* background = new SGIndivSpriteComponent(0, 0, .12);
	background->AddFrame(al_load_bitmap("Assets/ClassicMode/CartoonJungleBackground.jpg"));
	AddVisualComponent(background);

	for (int i = 1; i <= GetNRows(); i++) {
		std::vector<SGAbstractCell*> row;
		for (int j = 1; j <= GetNCols(); j++) {
			int x = i;
			int y = j;
			EvaluateCoords(x, y);
			SGEmptyCell* cell = new SGEmptyCell(x, y);
			AddVisualComponent(cell);
			row.push_back(NULL);
		}
		row.push_back(NULL);
		cells.push_back(row);
	}
	std::vector<SGAbstractCell*> lastRow;
	for (int j = 1; j <= GetNCols(); j++) {
		lastRow.push_back(NULL);
	}
	lastRow.push_back(NULL);
	cells.push_back(lastRow);
	int ci = (GetNRows() / 2) + 1;
	int cj = (GetNCols() / 2) + 1;
	int _ci = ci;
	int _cj = cj;
	EvaluateCoords(ci, cj); // make an abstract factory to make these
	apple = new SGAppleCell(ci, cj);
	AddVisualComponent(apple);
	cells.at(_ci).at(_cj) = apple;

	ci = 3;
	cj = (GetNCols() / 2) + 1;
	std::pair<int, int> headCoords = std::pair<int, int>(ci, cj);
	EvaluateCoords(ci, cj);
	SGSnakeCell* snakeHead = new SGSnakeCell(ci, cj);
	snakeHead->SetColors(0, 200, 0);
	snake.push_back(std::pair<SGSnakeCell*, std::pair<int, int>>(snakeHead, headCoords));
	AddVisualComponent(snakeHead);
	cells.at(headCoords.first).at(headCoords.second) = snakeHead;

	// scoreText = new SGTextComponent(900, 30, 75, "../../Game\ Fonts/FunBlob.ttf", al_map_rgb(0, 0, 0), "");
	scoreText = new SGTextComponent(900, 55, 40, "Assets/Fonts/PressStart2P.ttf", al_map_rgb(255, 255, 255), "");
	scoreText->SetText("Score: 0");
	AddVisualComponent(scoreText);
}
SGFirstGameModel::~SGFirstGameModel() {}
void SGFirstGameModel::EvaluateCoords(int& i, int& j) {
	int rad = apple->GetRadius();
	i = xOffset + (rad * i);
	j = yOffset + (rad * j);
}
SGSnakeCell* SGFirstGameModel::GetSnakeHead() {
	return snake.at(0).first;
}

void SGFirstGameModel::GetSnakeHeadCoords(int& x, int& y) {
	x = snake.at(0).second.first;
	y = snake.at(0).second.second;
}
void SGFirstGameModel::SetSnakeHeadCoords(int x, int y) {
	std::pair<int, int> coords(x, y);
	snake.at(0).second = coords;
	EvaluateCoords(x, y);
	GetSnakeHead()->SetXPos(x);
	GetSnakeHead()->SetYPos(y);
}
int SGFirstGameModel::GetNRows() const {
	return 31;
}
int SGFirstGameModel::GetNCols() const {
	return 21;
}
std::vector<std::pair<SGSnakeCell*, std::pair<int, int>>>& SGFirstGameModel::GetSnake() {
	return snake;
}
void SGFirstGameModel::MoveSnakeCell(int index, int i, int j) {
	std::pair<int, int> beforeCoords(snake.at(index).second);
	std::pair<int, int> coords(i, j);
	cells.at(i).at(j) = snake.at(index).first;
	snake.at(index).second = coords;
	EvaluateCoords(i, j);
	snake.at(index).first->SetXPos(i);
	snake.at(index).first->SetYPos(j);
	cells.at(beforeCoords.first).at(beforeCoords.second) = NULL;
}
double SGFirstGameModel::GetTickTime() const {
	return tickTime;
}
void SGFirstGameModel::SetTickTime(double time) {
	tickTime = time;
}
// ctrl responds to tick
// need a way to add a new snake part (use .back)
// 
std::vector<std::vector<SGAbstractCell*>>& SGFirstGameModel::GetCells() {
	return cells;
}

void SGFirstGameModel::AddSnakePart(SGDirection dir, int i, int j) {
	std::pair<int, int> coords(i, j);
	EvaluateCoords(i, j);
	SGSnakeCell* newPart = new SGSnakeCell(i, j, dir);
	AddVisualComponent(newPart);
	snake.push_back(std::pair<SGSnakeCell*, std::pair<int, int>>(newPart, coords));
	cells.at(coords.first).at(coords.second) = newPart;
}

void SGFirstGameModel::MoveConsumableAt(int i, int j) {
	SGAbstractCell* consumable = cells.at(i).at(j);
	int newRow;
	int newCol;
	srand(al_get_time());
	do {
		newRow = rand() % GetNRows() + 1;
		newCol = rand() % GetNCols() + 1;
	} while (cells.at(newRow).at(newCol) != NULL);
	cells.at(newRow).at(newCol) = consumable;
	EvaluateCoords(newRow, newCol);
	consumable->SetXPos(newRow);
	consumable->SetYPos(newCol);
}

bool SGFirstGameModel::GetGameStart() const {
	return gameStart;
}
void SGFirstGameModel::SetGameStart(bool status) {
	gameStart = status;
}
int SGFirstGameModel::GetScore() const {
	return score;
}
void SGFirstGameModel::SetScore(int scr) {
	score = scr;
	char buff[128];
	const char* txt = buff;
	snprintf(buff, 128, "Score: %d", score);
	scoreText->SetText(txt);
}
bool SGFirstGameModel::GetGameOver() const {
	return gameOver;
}
void SGFirstGameModel::ActivateGameOver() {
	for (auto snakeCell : snake) {
		snakeCell.first->SetColors(150, 100, 100);
	}
	GetSnakeHead()->SetColors(126, 8, 8);
	gameOver = true;
}