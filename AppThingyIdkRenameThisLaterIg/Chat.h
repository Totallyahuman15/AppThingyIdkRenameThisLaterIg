#pragma once

#include <wx/wx.h>
#include <wx/webview.h>

class ChatWindow : public wxFrame
{
public:
	ChatWindow(const wxString& title, const wxSize& windowSize);
};
