#include "SGObservers.h"
#include <iostream>

SGEnterObserver::SGEnterObserver(SGSubject& subj, SGCtrlManager& manager) : subject(subj), ctrlManager(manager) {
	subject.AddChild(this);
}
SGEnterObserver::~SGEnterObserver() {}
bool SGEnterObserver::Update() {
	if (al_key_down(subject.GetKeyState(), ALLEGRO_KEY_ENTER)) {
		ctrlManager.NextMode();
		return true;
	}
	return false;
}

SGEscapeObserver::SGEscapeObserver(SGSubject& subj, SGCtrlManager& manager) : subject(subj), ctrlManager(manager) {
	subject.AddChild(this);
}
SGEscapeObserver::~SGEscapeObserver() {}
bool SGEscapeObserver::Update() {
	if (al_key_down(subject.GetKeyState(), ALLEGRO_KEY_ESCAPE)) {
		ctrlManager.End();
		return true;
	}
	return false;
}
SGTickObserver::SGTickObserver(SGSubject& subj, SGCtrlManager& manager) : subject(subj), ctrlManager(manager), time(al_get_time()) {
	subject.AddChild(this);
}
SGTickObserver::~SGTickObserver() {}
bool SGTickObserver::Update() {
	if (al_get_time() - time > ctrlManager.GetCurrentCtrl()->GetModel()->GetTickTime()) {
		ctrlManager.GetCurrentCtrl()->Tick();
		time = al_get_time();
		return true;
	}
	return false;
}

SGUpObserver::SGUpObserver(SGSubject& subj, SGCtrlManager& manager) : subject(subj), ctrlManager(manager) {
	subject.AddChild(this);
}
SGUpObserver::~SGUpObserver() {}
bool SGUpObserver::Update() {
	if ((al_key_down(subject.GetKeyState(), ALLEGRO_KEY_UP) || (al_key_down(subject.GetKeyState(), ALLEGRO_KEY_W)) && (ctrlManager.GetLastKeyPressed() != (int)ALLEGRO_KEY_UP))) {
		ctrlManager.GetCurrentCtrl()->Up();
		ctrlManager.SetLastKeyPressed((int)ALLEGRO_KEY_UP);
		return true;
	}
	return false;
}

SGDownObserver::SGDownObserver(SGSubject& subj, SGCtrlManager& manager) : subject(subj), ctrlManager(manager) {
	subject.AddChild(this);
}
SGDownObserver::~SGDownObserver() {}
bool SGDownObserver::Update() {
	if ((al_key_down(subject.GetKeyState(), ALLEGRO_KEY_DOWN) || (al_key_down(subject.GetKeyState(), ALLEGRO_KEY_S)) && (ctrlManager.GetLastKeyPressed() != (int)ALLEGRO_KEY_DOWN))) {
		ctrlManager.GetCurrentCtrl()->Down();
		ctrlManager.SetLastKeyPressed((int)ALLEGRO_KEY_DOWN);
		return true;
	}
	return false;
}

SGLeftObserver::SGLeftObserver(SGSubject& subj, SGCtrlManager& manager) : subject(subj), ctrlManager(manager) {
	subject.AddChild(this);
}
SGLeftObserver::~SGLeftObserver() {}
bool SGLeftObserver::Update() {
	if ((al_key_down(subject.GetKeyState(), ALLEGRO_KEY_LEFT) || (al_key_down(subject.GetKeyState(), ALLEGRO_KEY_A)) && (ctrlManager.GetLastKeyPressed() != (int)ALLEGRO_KEY_LEFT))) {
		ctrlManager.GetCurrentCtrl()->Left();
		ctrlManager.SetLastKeyPressed((int)ALLEGRO_KEY_LEFT);
		return true;
	}
	return false;
}

SGRightObserver::SGRightObserver(SGSubject& subj, SGCtrlManager& manager) : subject(subj), ctrlManager(manager) {
	subject.AddChild(this);
}
SGRightObserver::~SGRightObserver() {}
bool SGRightObserver::Update() {
	if ((al_key_down(subject.GetKeyState(), ALLEGRO_KEY_RIGHT) || (al_key_down(subject.GetKeyState(), ALLEGRO_KEY_D)) && (ctrlManager.GetLastKeyPressed() != (int)ALLEGRO_KEY_RIGHT))) {
		ctrlManager.GetCurrentCtrl()->Right();
		ctrlManager.SetLastKeyPressed((int)ALLEGRO_KEY_RIGHT);
		return true;
	}
	return false;
}

SGRKeyObserver::SGRKeyObserver(SGSubject& subj, SGCtrlManager& manager) : subject(subj), ctrlManager(manager) {
	subject.AddChild(this);
}
SGRKeyObserver::~SGRKeyObserver() {}
bool SGRKeyObserver::Update() {
	if (al_key_down(subject.GetKeyState(), ALLEGRO_KEY_R) && ctrlManager.GetCurrentCtrl()->GetGameOver()) {
		ctrlManager.RestartCurrentMode();
		return true;
	}
	return false;
}