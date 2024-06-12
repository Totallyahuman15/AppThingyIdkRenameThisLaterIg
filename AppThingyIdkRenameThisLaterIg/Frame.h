#pragma once

#include <wx/wx.h>

enum
{
	ID_Hello = 1
};

class Frame : public wxFrame
{
public:
	Frame(const wxString& title);
private:
	void OnHello(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
};
