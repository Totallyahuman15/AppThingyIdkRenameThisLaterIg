#pragma once

#include <wx/wx.h>
#include <wx/wxhtml.h>
#include <wx/webview.h>
#include <iostream>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title, const wxSize& size);
private:
	void InitializeMenu();
	void InitializeWebView(const wxSize& size);

	void OnExit(const wxCommandEvent& event);
	void OnForward(const wxCommandEvent& event);
	void OnBackward(const wxCommandEvent& event);
	void OnRefresh(const wxCommandEvent& event);

	wxWebView* webView;
};
