#include "WebViewWindow.h"

WebViewWindow::WebViewWindow(const wxString& title, const wxSize& size, const std::string URL)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, size)
{
	InitWebView(URL);
}

void WebViewWindow::InitWebView(const std::string URL)
{
	wxWebView* webView = wxWebView::New(this, wxID_ANY, URL, wxDefaultPosition, this->GetSize());
}
