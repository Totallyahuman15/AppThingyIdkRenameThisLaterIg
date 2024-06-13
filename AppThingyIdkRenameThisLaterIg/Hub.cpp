#include "Hub.h"

HubWindow::HubWindow(const wxString& title, const wxSize& windowSize)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, windowSize)
{
	wxMenu* menuFile = new wxMenu();
	menuFile->Append(wxID_EXIT);

	wxMenu* menuView = new wxMenu();
	menuView->Append(ID_ChatButton, "&Open Chat");

	wxMenu* menuHelp = new wxMenu();
	menuHelp->Append(wxID_ABOUT);

	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuView, "&View");
	menuBar->Append(menuHelp, "&Help");

	SetMenuBar(menuBar);

	Bind(wxEVT_MENU, [=](const wxCommandEvent&) { Close(true); }, wxID_EXIT);
	Bind(wxEVT_MENU, &HubWindow::OnAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &HubWindow::OpenChat, this, ID_ChatButton);

	InitWebView();
}

void HubWindow::InitWebView()
{
	wxWebView* webView = wxWebView::New(this, wxID_ANY, "https://www.127.0.0.1.com/", wxDefaultPosition, this->GetSize());

	webView->LoadURL("Https://www.google.com/");
}

void HubWindow::OnAbout(const wxCommandEvent& event)
{
	wxMessageBox("Gamer's Hub by Totallyahuman15, Lucidblu, and the other guy", "About", wxOK_DEFAULT);
}

void HubWindow::OpenChat(const wxCommandEvent& event)
{
	ChatWindow* frame = new ChatWindow("Gamer's Chat", this->GetSize());
	frame->Show();
}
