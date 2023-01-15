#include "SGView.h"
#include <iostream>

SGAbstractView::SGAbstractView() : isActive(false), status(0) {}
SGAbstractView::~SGAbstractView() {}
bool SGAbstractView::GetIsActive() const {
	return isActive;
}
void SGAbstractView::SetIsActive(bool active) {
	isActive = active;
}

int SGAbstractView::GetStatus() const {
	return status;
}
void SGAbstractView::SetStatus(int newStatus) {
	status = newStatus;
}



SGStaticView::SGStaticView(SGAbstractModel& mdl) : model(mdl) {}
SGStaticView::~SGStaticView() {}
void SGStaticView::Show() {
	SetIsActive(true);
	SetStatus(1);
	while (GetIsActive()) {
		for (int i = 0; i < model.GetNumComponents(); i++) {
			SGVisualComponent* cmpnt = model.GetVisualComponentAt(i);
			cmpnt->Draw();
		}
		al_flip_display();
		Notify();
		al_clear_to_color(al_map_rgb(255, 255, 255));
	}
	// transition.Play();
	SetStatus(0);
}
