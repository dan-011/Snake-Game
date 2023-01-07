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
};

class SGStartupCtrl : public SGAbstractCtrl {
public:
	SGStartupCtrl();
	virtual ~SGStartupCtrl();
	virtual void StartMode() override;
	virtual void EndMode() override;
	virtual SGAbstractModel* GetModel();
	virtual SGAbstractView* GetView();

private:
	SGStartupModel* model;
	SGStaticView* view;
};

#endif // !__SGCONTROLLER_H
