#include "Frame.h"

// Using the introduction documentation (See https://docs.wxwidgets.org/3.2/overview_helloworld.html for the explanation)
Frame::Frame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title)
{
	wxMenu* menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl+H", "Help String idk");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);

	wxMenu* menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);

	wxMenuBar* menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");

	SetMenuBar(menuBar);

	Bind(wxEVT_MENU, &Frame::OnHello, this, ID_Hello);
	Bind(wxEVT_MENU, &Frame::OnAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, [=](wxCommandEvent&) { Close(true); }, wxID_EXIT);
}

void Frame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello, world!");
}

void Frame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("This is just an example of an application created by wxWidgets!", "About Application", wxOK | wxICON_INFORMATION);
}
