#ifndef __SGVIEW_H
#define __SGVIEW_H

#include "SGModel.h"
#include "SGSubject.h"

class SGAbstractView : public SGSubject {
public:
	SGAbstractView();
	virtual ~SGAbstractView();
	virtual void Show() = 0;
	bool GetIsActive() const;
	void SetIsActive(bool active);
	int GetStatus() const;
	void SetStatus(int newStatus);
private:
	bool isActive;
	int status;
};

class SGStaticView : public SGAbstractView {
public:
	SGStaticView(SGAbstractModel& mdl);
	virtual ~SGStaticView();
	virtual void Show() override;

private:
	SGAbstractModel& model;
};

#endif