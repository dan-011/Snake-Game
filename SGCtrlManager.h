#ifndef __SGCTRLMANAGER_H
#define __SGCTRLMANAGER_H

#include "SGController.h"
#include <vector>

class SGCtrlManager {
public:
	SGCtrlManager();
	~SGCtrlManager();
	int GetDisplayWidth() const;
	int GetDisplayHeight() const;
	void NextMode();
	void PrevMode();
	void End();

private:
	int currentCtrlIndex;
	ALLEGRO_DISPLAY* display;
	std::vector<SGAbstractCtrl*> sequenceCtrls;
};

#endif