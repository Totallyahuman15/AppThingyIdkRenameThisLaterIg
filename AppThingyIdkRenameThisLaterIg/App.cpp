#include "App.h"

bool App::OnInit()
{
	wxInitAllImageHandlers();

	HubWindow* hub = new HubWindow("Gamer's Hub", wxSize(800, 600));
	hub->Show();

	return true;
}
