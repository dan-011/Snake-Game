#ifndef __SGOBSERVERS_H
#define __SGOBSERVERS_H

#include "SGSubject.h"
#include "SGCtrlManager.h"

class SGEnterObserver : public SGAbstractObserver {
public:
	SGEnterObserver(SGSubject& subj, SGCtrlManager& manager);
	virtual ~SGEnterObserver();
	virtual bool Update() override;

private:
	SGSubject& subject;
	SGCtrlManager& ctrlManager;
};

class SGEscapeObserver : public SGAbstractObserver {
public:
	SGEscapeObserver(SGSubject& subj, SGCtrlManager& manager);
	virtual ~SGEscapeObserver();
	virtual bool Update() override;

private:
	SGSubject& subject;
	SGCtrlManager& ctrlManager;
};

#endif // !__SGOBSERVERS_H