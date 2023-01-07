#include "SGController.h"

SGAbstractCtrl::~SGAbstractCtrl() {}

SGStartupCtrl::SGStartupCtrl() : model(new SGStartupModel), view(new SGStaticView(*model)) {}
SGStartupCtrl::~SGStartupCtrl() {
	delete view;
	delete model;
}
void SGStartupCtrl::StartMode() {
	view->Show();
}
#include <iostream>
void SGStartupCtrl::EndMode() {
	view->SetIsActive(false);
	// have the view send a status to indicate when it is done
	//while(view->GetStatus()){
	//	std::cout << view->GetStatus() << std::endl;
		// wait for the view to finish
	//}
}
SGAbstractModel* SGStartupCtrl::GetModel() {
	return model;
}
SGAbstractView* SGStartupCtrl::GetView() {
	return view;
}