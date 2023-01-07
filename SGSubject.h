// receives signals
#ifndef __SUBJECT_H
#define __SUBJECT_H

#include <vector>
#include "allegro5/allegro.h"

// ************************************************************************************************************************************************
// AbstractObserver
class SGAbstractObserver {
public:
	virtual ~SGAbstractObserver();
	virtual bool Update() = 0;
};

// ************************************************************************************************************************************************
// Subject
class SGSubject {
public:
	SGSubject();
	virtual ~SGSubject();

	void AddChild(SGAbstractObserver* observer);
	void RemoveChild(SGAbstractObserver* observer);
	ALLEGRO_KEYBOARD_STATE* GetKeyState();
	double GetTime();
	void Notify();

private:
	ALLEGRO_KEYBOARD_STATE* keyState;
	std::vector<SGAbstractObserver*> observers;
};
#endif // !__SUBJECT_H