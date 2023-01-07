#include "SGModel.h"

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

#include <fstream>
SGStartupModel::SGStartupModel() {
	/*std::ofstream f;
	f.open("Assets/Startup/test.txt", std::ios::trunc);
	f << "test" << std::endl;
	f.close();
	exit(0);*/
	SGIndivSpriteComponent* background = new SGIndivSpriteComponent(0, 0, .12);
	background->AddFrame(al_load_bitmap("Assets/Startup/StartupBackground/ColorLess/frame0.png"));
	background->AddFrame(al_load_bitmap("Assets/Startup/StartupBackground/ColorLess/frame1.png"));
	background->AddFrame(al_load_bitmap("Assets/Startup/StartupBackground/ColorLess/frame2.png"));
	background->AddFrame(al_load_bitmap("Assets/Startup/StartupBackground/ColorLess/frame3.png"));
	background->AddFrame(al_load_bitmap("Assets/Startup/StartupBackground/ColorLess/frame4.png"));
	AddVisualComponent(background);

	SGIndivSpriteComponent* snake = new SGIndivSpriteComponent(550, 300, .12);
	snake->AddFrame(al_load_bitmap("Assets/Startup/StartupSnake.png"));
	AddVisualComponent(snake);
}
SGStartupModel::~SGStartupModel() {}