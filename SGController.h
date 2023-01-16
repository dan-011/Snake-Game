#ifndef __SGCONTROLLER_H
#define __SGCONTROLLER_H

#include "SGModel.h"
#include "SGView.h"

class SGAbstractCtrl {
public:
	virtual ~SGAbstractCtrl();
	virtual void StartMode() = 0;
	virtual void EndMode() = 0;
	virtual SGAbstractModel* GetModel() = 0;
	virtual SGAbstractView* GetView() = 0;
	virtual bool GetGameOver();
	virtual void Tick();
	virtual void Up();
	virtual void Down();
	virtual void Left();
	virtual void Right();
};

class SGStartupCtrl : public SGAbstractCtrl {
public:
	SGStartupCtrl();
	virtual ~SGStartupCtrl();
	virtual void StartMode() override;
	virtual void EndMode() override;
	virtual SGAbstractModel* GetModel() override;
	virtual SGAbstractView* GetView() override;

private:
	SGStartupModel* model;
	SGStaticView* view;
};

class SGFirstGameCtrl : public SGAbstractCtrl {
public:
	SGFirstGameCtrl();
	virtual ~SGFirstGameCtrl();
	virtual void StartMode() override;
	virtual void EndMode() override;
	virtual SGAbstractModel* GetModel() override;
	virtual SGAbstractView* GetView() override;
	virtual bool GetGameOver() override;
	virtual void Tick() override;
	virtual void Up() override;
	virtual void Down() override;
	virtual void Left() override;
	virtual void Right() override;

private:
	SGFirstGameModel* model;
	SGStaticView* view;
	int addingCells;
};

#endif // !__SGCONTROLLER_H
