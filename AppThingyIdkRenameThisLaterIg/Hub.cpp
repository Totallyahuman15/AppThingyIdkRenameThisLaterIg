#include "Hub.h"

HubWindow::HubWindow(const wxString& title, const wxSize& size, const std::string URL)
	: WebViewWindow(title, size, URL)
{
	wxMenu* menuFile = new wxMenu();
	menuFile->Append(ID_Login, "&Log in");
	menuFile->Append(ID_SignUp, "&Sign up");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);

	wxMenu* menuView = new wxMenu();
	menuView->Append(ID_Chat, "&Open chat");
	
	wxMenu* menuHelp = new wxMenu();
	menuHelp->Append(wxID_ABOUT);

	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuView, "&View");
	menuBar->Append(menuHelp, "&Help");

	this->SetMenuBar(menuBar);

	Bind(wxEVT_MENU, [=](const wxCommandEvent&) { Close(true); }, wxID_EXIT);
	Bind(wxEVT_MENU, &HubWindow::OnAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &HubWindow::OnLogin, this, ID_Login);
	Bind(wxEVT_MENU, &HubWindow::OnSignUp, this, ID_SignUp);
	Bind(wxEVT_MENU, &HubWindow::OnChat, this, ID_Chat);
}

void HubWindow::OnAbout(const wxCommandEvent& event)
{
	wxMessageBox("Gamer's Hub by Totallyahuman15, Lucidblu, and the other guy", "Credits", wxOK_DEFAULT);
}

void HubWindow::OnLogin(const wxCommandEvent& event)
{
	WebViewWindow* frame = new WebViewWindow("Log In", wxSize(600, 600), "http://lucidblu.rf.gd/Game%20Thieves/login.php?i=1");
	frame->Show();
}

void HubWindow::OnSignUp(const wxCommandEvent& event)
{
	WebViewWindow* frame = new WebViewWindow("Sign Up", wxSize(600, 600), "http://lucidblu.rf.gd/Game%20Thieves/signup.php");
	frame->Show();
}

void HubWindow::OnChat(const wxCommandEvent& event)
{
	WebViewWindow* frame = new WebViewWindow("Gamer's Chat", this->GetSize(), "https://www.google.com");
	frame->Show();
}
