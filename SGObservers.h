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

class SGTickObserver : public SGAbstractObserver {
public:
	SGTickObserver(SGSubject& subj, SGCtrlManager& manager);
	virtual ~SGTickObserver();
	virtual bool Update() override;

private:
	SGSubject& subject;
	SGCtrlManager& ctrlManager;
	double time;
};

class SGUpObserver : public SGAbstractObserver {
public:
	SGUpObserver(SGSubject& subj, SGCtrlManager& manager);
	virtual ~SGUpObserver();
	virtual bool Update() override;

private:
	SGSubject& subject;
	SGCtrlManager& ctrlManager;
};

class SGDownObserver : public SGAbstractObserver {
public:
	SGDownObserver(SGSubject& subj, SGCtrlManager& manager);
	virtual ~SGDownObserver();
	virtual bool Update() override;

private:
	SGSubject& subject;
	SGCtrlManager& ctrlManager;
};

class SGLeftObserver : public SGAbstractObserver {
public:
	SGLeftObserver(SGSubject& subj, SGCtrlManager& manager);
	virtual ~SGLeftObserver();
	virtual bool Update() override;

private:
	SGSubject& subject;
	SGCtrlManager& ctrlManager;
};

class SGRightObserver : public SGAbstractObserver {
public:
	SGRightObserver(SGSubject& subj, SGCtrlManager& manager);
	virtual ~SGRightObserver();
	virtual bool Update() override;

private:
	SGSubject& subject;
	SGCtrlManager& ctrlManager;
};

class SGRKeyObserver : public SGAbstractObserver {
public:
	SGRKeyObserver(SGSubject& subj, SGCtrlManager& manager);
	virtual ~SGRKeyObserver();
	virtual bool Update() override;

private:
	SGSubject& subject;
	SGCtrlManager& ctrlManager;
};
#endif // !__SGOBSERVERS_H