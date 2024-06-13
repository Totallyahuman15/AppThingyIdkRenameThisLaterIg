#include "App.h"

bool App::OnInit()
{
	wxInitAllImageHandlers();

	HubWindow* frame = new HubWindow("Gamer's Hub", wxSize(800, 600), "https://www.google.com/");
	frame->Show();

	return true;
}
