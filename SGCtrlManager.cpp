#include "SGCtrlManager.h"
#include "SGObservers.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>

SGCtrlManager::SGCtrlManager(): currentCtrlIndex(-1), lastKeyPressed(0) {
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();

	display = al_create_display(GetDisplayWidth(), GetDisplayHeight());

	SGStartupCtrl* startupCtrl = new SGStartupCtrl;
	SGEnterObserver* enterObserver = new SGEnterObserver(*(startupCtrl->GetView()), *this);
	SGEscapeObserver* escapeObserver = new SGEscapeObserver(*(startupCtrl->GetView()), *this);
	sequenceCtrls.push_back(startupCtrl);

	SGFirstGameCtrl* firstGameCtrl = new SGFirstGameCtrl;
	SGTickObserver* tickObserver = new SGTickObserver(*(firstGameCtrl->GetView()), *this);
	SGUpObserver* upObserver = new SGUpObserver(*(firstGameCtrl->GetView()), *this);
	SGDownObserver* downObserver = new SGDownObserver(*(firstGameCtrl->GetView()), *this);
	SGLeftObserver* leftObserver = new SGLeftObserver(*(firstGameCtrl->GetView()), *this);
	SGRightObserver* rightObserver = new SGRightObserver(*(firstGameCtrl->GetView()), *this);
	sequenceCtrls.push_back(firstGameCtrl);
}
SGCtrlManager::~SGCtrlManager() {
	for (auto ctrl : sequenceCtrls) {
		delete ctrl;
	}
	al_destroy_display(display);
	al_uninstall_keyboard();
}
SGAbstractCtrl* SGCtrlManager::GetCurrentCtrl() {
	return sequenceCtrls.at(currentCtrlIndex);
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
	if (currentCtrlIndex < (int)sequenceCtrls.size() - 1) {
		currentCtrlIndex++;
		sequenceCtrls.at(currentCtrlIndex)->StartMode();
	}
	SetLastKeyPressed(0);
}
void SGCtrlManager::PrevMode() {
	if (currentCtrlIndex > 0) {
		currentCtrlIndex--;
	}
}
void SGCtrlManager::End() {
	sequenceCtrls.at(currentCtrlIndex)->EndMode();
}
int SGCtrlManager::GetLastKeyPressed() const {
	return lastKeyPressed;
}
void SGCtrlManager::SetLastKeyPressed(int key) {
	lastKeyPressed = key;
}