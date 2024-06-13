#pragma once

#include <wx/wx.h>

#include "Hub.h"

class App : public wxApp
{
public:
	virtual bool OnInit();
};

wxIMPLEMENT_APP(App);
