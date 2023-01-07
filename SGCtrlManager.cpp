#include "SGCtrlManager.h"
#include "SGObservers.h"
#include <allegro5/allegro_image.h>
#include <iostream>

SGCtrlManager::SGCtrlManager(): currentCtrlIndex(-1) {
	al_init();
	al_init_image_addon();
	al_install_keyboard();


	display = al_create_display(GetDisplayWidth(), GetDisplayHeight());

	SGStartupCtrl* startupCtrl = new SGStartupCtrl;
	SGEnterObserver* enterObserver = new SGEnterObserver(*(startupCtrl->GetView()), *this);
	SGEscapeObserver* escapeObserver = new SGEscapeObserver(*(startupCtrl->GetView()), *this);
	sequenceCtrls.push_back(startupCtrl);
}
SGCtrlManager::~SGCtrlManager() {
	for (auto ctrl : sequenceCtrls) {
		delete ctrl;
	}
	al_destroy_display(display);
	al_uninstall_keyboard();
}
int SGCtrlManager::GetDisplayWidth() const {
	return 1500;
}
int SGCtrlManager::GetDisplayHeight() const {
	return 800;
}
void SGCtrlManager::NextMode() {
	if (currentCtrlIndex >= 0) {
		sequenceCtrls.at(currentCtrlIndex)->EndMode();
	}
	std::cout << currentCtrlIndex << " < " << sequenceCtrls.size() << std::endl;
	if (currentCtrlIndex < (int)sequenceCtrls.size() - 1) {
		currentCtrlIndex++;
		sequenceCtrls.at(currentCtrlIndex)->StartMode();
	}
}
void SGCtrlManager::PrevMode() {
	if (currentCtrlIndex > 0) {
		currentCtrlIndex--;
	}
}
void SGCtrlManager::End() {
	sequenceCtrls.at(currentCtrlIndex)->EndMode();
}