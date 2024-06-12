#include "App.h"

// Using the introduction documentation (See https://docs.wxwidgets.org/3.2/overview_helloworld.html for the explanation)
bool App::OnInit()
{
	// Opening C++ Window (See Frame.cpp)
	Frame* frame = new Frame("Hello, world!");
	frame->Show(true);

	// Opening a XRC file (See https://docs.wxwidgets.org/3.2/overview_xrc.html for more info)
	wxXmlResource::Get()->InitAllHandlers();
	wxXmlResource::Get()->Load("Data\\RC\\DialogTest.xrc");

	wxDialog dlg;
	if (wxXmlResource::Get()->LoadDialog(&dlg, NULL, "MyDialog1"))
	{
		dlg.ShowModal();
	}

	XRCCTRL(dlg, "m_button1", wxButton)->Bind(wxEVT_BUTTON, wxCommandEventHandler(App::OnClick), this, XRCID("m_button1"));

	return true;
}

void App::OnClick(wxCommandEvent& event)
{
}
