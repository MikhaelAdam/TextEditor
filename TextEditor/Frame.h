#pragma once
#include<wx/wx.h>
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stc/stc.h>
#include <wx/sizer.h>
#include <wx/splitter.h>
#include <wx/frame.h>
class Frame: public wxFrame
{
private:

protected:
	wxPanel* main_panel;
	wxSplitterWindow* splitter;
	wxPanel* file_panel;
	wxPanel* code_panel;
	wxStyledTextCtrl* textCtrl;

public:

	Frame(const wxString& title = wxEmptyString);
};

