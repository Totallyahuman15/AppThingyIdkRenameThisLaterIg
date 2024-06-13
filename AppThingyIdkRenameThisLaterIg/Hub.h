#pragma once

#include "WebViewWindow.h"

enum
{
	ID_SignUp = 1,
	ID_Login = 2,
	ID_Chat = 3
};

class HubWindow : public WebViewWindow
{
public:
	HubWindow(const wxString& title, const wxSize& size, const std::string URL);
private:
	void OnAbout(const wxCommandEvent& event);
	void OnLogin(const wxCommandEvent& event);
	void OnSignUp(const wxCommandEvent& event);
	void OnChat(const wxCommandEvent& event);
};
