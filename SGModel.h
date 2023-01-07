#ifndef __SGMODEL_H
#define __SGMODEL_H

#include "SGVisualComponent.h"
#include <vector>

class SGAbstractModel {
public:
	virtual ~SGAbstractModel();
	SGVisualComponent* GetVisualComponentAt(int index);
	void AddVisualComponent(SGVisualComponent* component);
	int GetNumComponents() const;

private:
	std::vector<SGVisualComponent*> visualComponents;
};

class SGStartupModel : public SGAbstractModel {
public:
	SGStartupModel();
	virtual ~SGStartupModel();

};

/*class SGTransition : public SGAbstractModel {
public:
	SGTransition();
	virtual ~SGTransition();
	void Play();
};*/

#endif // !__SGMODEL_H
