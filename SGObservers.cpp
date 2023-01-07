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