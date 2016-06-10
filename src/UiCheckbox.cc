#include "../libui/ui.h"
#include "nbind/api.h"
#include "nbind/nbind.h"
#include "ui-node.h"


UiCheckbox::UiCheckbox(const char *text) : UiControl( (uiControl*) uiNewCheckbox(text) ) {}

INHERITS_CONTROL_METHODS(UiCheckbox)

void UiCheckbox::setText(const char * text) {
	uiCheckboxSetText((uiCheckbox *) getHandle(), text);
}

const char * UiCheckbox::getText() {
	return uiCheckboxText((uiCheckbox *) getHandle());
}

void UiCheckbox::setChecked(int checked) {
	uiCheckboxSetChecked((uiCheckbox *) getHandle(), checked);
}

int UiCheckbox::getChecked() {
	return uiCheckboxChecked((uiCheckbox *) getHandle());
}


NBIND_CLASS(UiCheckbox) {
	construct<const char *>();
	DECLARE_CONTROL_METHODS()
	getset(getChecked, setChecked);
	getset(getText, setText);
}
