#include "Chat.h"

ChatWindow::ChatWindow(const wxString& title, const wxSize& windowSize)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, windowSize)
{
	wxWebView* webView = wxWebView::New(this, wxID_ANY, "https://127.0.0.1.com/", wxDefaultPosition, this->GetSize());

	webView->LoadURL("https://www.yahoo.com");
}
