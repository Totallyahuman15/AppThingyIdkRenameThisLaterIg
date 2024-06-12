#pragma once

#include "Frame.h"

#include <wx/xrc/xmlres.h>

#ifdef WX_PRECOMP
	#include <wx/wx.h>
#endif

class App : public wxApp
{
public:
	virtual bool OnInit();
private:
	void OnClick(wxCommandEvent& event);
};

wxIMPLEMENT_APP(App);
