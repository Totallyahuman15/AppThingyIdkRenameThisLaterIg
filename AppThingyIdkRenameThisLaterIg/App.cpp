#include "App.h"

bool App::OnInit()
{
	wxInitAllImageHandlers();
	MainFrame* frame = new MainFrame("WebView Test", wxSize(800, 600));
	frame->Show(true);
	return true;
}
