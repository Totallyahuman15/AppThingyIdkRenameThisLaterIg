#pragma once

#include <wx/wx.h>
#include <wx/webview.h>
#include <string>

class WebViewWindow : public wxFrame
{
public:
	WebViewWindow(const wxString& title, const wxSize& size, const std::string URL);
private:
	virtual void InitWebView(const std::string URL);
};
