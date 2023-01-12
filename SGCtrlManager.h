#ifndef __SGCTRLMANAGER_H
#define __SGCTRLMANAGER_H

#include "SGController.h"
#include <vector>

class SGCtrlManager {
public:
	SGCtrlManager();
	~SGCtrlManager();
	SGAbstractCtrl* GetCurrentCtrl();
	int GetDisplayWidth() const;
	int GetDisplayHeight() const;
	void NextMode();
	void PrevMode();
	void End();
	int GetLastKeyPressed() const;
	void SetLastKeyPressed(int key);

private:
	int currentCtrlIndex;
	ALLEGRO_DISPLAY* display;
	std::vector<SGAbstractCtrl*> sequenceCtrls;
	int lastKeyPressed;
};

#endif