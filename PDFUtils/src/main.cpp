#include "Core/Log.h"

#include "UI.h"

#include <iostream>

int onClosing(uiWindow *w, void *data)
{
	LOG_INFO("Closing window");
	uiQuit();
	return 1;
}

void saySomething(uiButton *b, void *data)
{
	LOG_INFO("We were clicked");
}

int main(int argc, char* argv[])
{
	Log::Init();
	LOG_INFO("Hello World!");

	uiInitOptions o;
	uiWindow *w;
	uiBox *b;
	uiButton *btn;

	memset(&o, 0, sizeof(uiInitOptions));
	if (uiInit(&o) != NULL) {
		LOG_ERROR("Could not initialized window, aborting!");
		abort();
	}
	
	w = uiNewWindow("Hello", 320, 240, 0);
	uiWindowSetMargined(w, 1);

	b = uiNewVerticalBox();
	uiBoxSetPadded(b, 1);
	uiWindowSetChild(w, uiControl(b));

	//e = uiNewMultilineEntry();
	//uiMultilineEntrySetReadOnly(e, 1);

	btn = uiNewButton("Say Something");
	uiButtonOnClicked(btn, saySomething, NULL);
	uiBoxAppend(b, uiControl(btn), 0);

	uiWindowOnClosing(w, onClosing, NULL);
	uiControlShow(uiControl(w));
	uiMain();

	return 0;
}