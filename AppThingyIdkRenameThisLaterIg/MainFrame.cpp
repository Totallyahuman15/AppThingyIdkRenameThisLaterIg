#include "MainFrame.h"
#include <filesystem>

MainFrame::MainFrame(const wxString& title, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, size)
{
	InitializeWebView(size);
	InitializeMenu();
}

void MainFrame::InitializeMenu()
{
	wxMenu* menuFile = new wxMenu;
	menuFile->Append(wxID_EXIT);

	wxMenu* menuTools = new wxMenu();
	menuTools->Append(wxID_BACKWARD);
	menuTools->Append(wxID_FORWARD);
	menuTools->AppendSeparator();
	menuTools->Append(wxID_REFRESH);

	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuTools, "&Tools");

	SetMenuBar(menuBar);

	Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_MENU, &MainFrame::OnForward, this, wxID_FORWARD);
	Bind(wxEVT_MENU, &MainFrame::OnBackward, this, wxID_BACKWARD);
	Bind(wxEVT_MENU, &MainFrame::OnRefresh, this, wxID_REFRESH);
}

void MainFrame::InitializeWebView(const wxSize& size)
{
	webView = wxWebView::New(this, wxID_ANY);

	std::string index = "file:///" + std::filesystem::current_path().generic_string() + "/Data/HTML/index.html";

	webView->LoadURL(index);
	webView->Show();
}

void MainFrame::OnExit(const wxCommandEvent& event)
{
	Close(true);
}

void MainFrame::OnForward(const wxCommandEvent& event)
{
	if (webView->CanGoForward())
	{
		webView->GoForward();
	}
}

void MainFrame::OnBackward(const wxCommandEvent& event)
{
	if (webView->CanGoBack())
	{
		webView->GoBack();
	}
}

void MainFrame::OnRefresh(const wxCommandEvent& event)
{
	webView->Refresh();
	webView->Update();
}
