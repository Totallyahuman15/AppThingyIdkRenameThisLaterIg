#pragma once

#include <wx/wx.h> 

#include "MainFrame.h"

class App : public wxApp
{
public:
	virtual bool OnInit();
};

wxIMPLEMENT_APP(App);
