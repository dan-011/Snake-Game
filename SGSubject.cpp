#include "SGSubject.h"

// ************************************************************************************************************************************************
// AbstractObserver
SGAbstractObserver::~SGAbstractObserver() {}

// ************************************************************************************************************************************************
// Subject
SGSubject::SGSubject(): keyState(new ALLEGRO_KEYBOARD_STATE) {}
SGSubject::~SGSubject() {
	for (auto observer : observers) {
		delete observer;
	}
	delete keyState;
}
void SGSubject::AddChild(SGAbstractObserver* observer) {
	observers.push_back(observer);
}
void SGSubject::RemoveChild(SGAbstractObserver* observer) {
	for (int i = 0; i < observers.size(); i++) {
		if (observers.at(i) == observer) {
			observers.erase(observers.begin() + i);
			break;
		}
	}
	delete observer;
}
ALLEGRO_KEYBOARD_STATE* SGSubject::GetKeyState() {
	al_get_keyboard_state(keyState);
	return keyState;
}
double SGSubject::GetTime() {
	return al_get_time();
}
void SGSubject::Notify() {
	for (auto observer : observers) {
		if (observer->Update()) {
			break;
		}
	}
}