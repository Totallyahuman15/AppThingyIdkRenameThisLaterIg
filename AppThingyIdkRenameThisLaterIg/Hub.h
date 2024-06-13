#pragma once

#include <wx/wx.h>

#include "Chat.h"

enum
{
	ID_ChatButton = 1
};

class HubWindow : public wxFrame
{
public:
	HubWindow(const wxString& title, const wxSize& windowSize);
private:
	void InitWebView();

	void OnAbout(const wxCommandEvent& event);
	void OpenChat(const wxCommandEvent& event);
};
