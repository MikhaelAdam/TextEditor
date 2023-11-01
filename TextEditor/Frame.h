#pragma once
#include<wx/wx.h>
#include<wx/splitter.h>
#include<wx/stc/stc.h>
#include <wx/aui/aui.h>
#include <wx/filedlg.h>	
#include <wx/file.h>	
#include <fstream>
#include "Codetab.h"
class Frame: public wxFrame
{
protected:
	wxAuiNotebook* notebook;
	wxFont font;
public:

	Frame(const wxString& title = wxEmptyString);

	void OnQuit(wxCommandEvent& e);
	void OnSave(wxCommandEvent& e);
	void OnOpen(wxCommandEvent& e);
	void OnNew(wxCommandEvent& e);
	void OnSaveAs(wxCommandEvent& e);
};

