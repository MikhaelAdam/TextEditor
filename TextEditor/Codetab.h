#pragma once
#include <wx/wx.h>
#include <wx/stc/stc.h>
class Codetab : public wxPanel
{
public:
	Codetab(wxWindow* m_parent);
	wxStyledTextCtrl* stc_tab;
};

