#include "SGCtrlManager.h"
#include "SGObservers.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <iostream>

SGCtrlManager::SGCtrlManager(): currentCtrlIndex(-1), lastKeyPressed(0) {
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_acodec_addon();

	al_install_keyboard();
	al_install_audio();

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
	SGRKeyObserver* rKeyObserver = new SGRKeyObserver(*(firstGameCtrl->GetView()), *this);
	SGEscapeObserver* firstGameEscapeObserver = new SGEscapeObserver(*(firstGameCtrl->GetView()), *this); // find a way to use the same observers when reusing

	sequenceCtrls.push_back(firstGameCtrl);
}
SGCtrlManager::~SGCtrlManager() {
	for (auto ctrl : sequenceCtrls) {
		delete ctrl;
	}
	al_destroy_display(display);
	al_uninstall_keyboard();
	al_uninstall_audio();

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

void SGCtrlManager::RestartCurrentMode() { // refactor with abstract factory
	// find better way to restart the current mode (reset the model, don't throw away the controller
	SGFirstGameCtrl* newGameCtrl = new SGFirstGameCtrl;
	SGTickObserver* tickObserver = new SGTickObserver(*(newGameCtrl->GetView()), *this);
	SGUpObserver* upObserver = new SGUpObserver(*(newGameCtrl->GetView()), *this);
	SGDownObserver* downObserver = new SGDownObserver(*(newGameCtrl->GetView()), *this);
	SGLeftObserver* leftObserver = new SGLeftObserver(*(newGameCtrl->GetView()), *this);
	SGRightObserver* rightObserver = new SGRightObserver(*(newGameCtrl->GetView()), *this);
	SGRKeyObserver* rKeyObserver = new SGRKeyObserver(*(newGameCtrl->GetView()), *this);
	SGEscapeObserver* escapeObserver = new SGEscapeObserver(*(newGameCtrl->GetView()), *this); // find a way to use the same observers when reusing

	SGAbstractCtrl* currentCtrl = GetCurrentCtrl();
	sequenceCtrls.at(currentCtrlIndex) = newGameCtrl;
	currentCtrl->EndMode();
	delete currentCtrl;
	newGameCtrl->StartMode();
}