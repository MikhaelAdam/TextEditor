#pragma once
#include<wx/wx.h>
#include<wx/splitter.h>
#include<wx/stc/stc.h>
#include <wx/aui/auibook.h>

class Frame: public wxFrame
{
private:

protected:
	wxPanel* main_panel;
	wxSplitterWindow* splitter;
	wxPanel* file_panel;
	wxPanel* code_panel;
	wxAuiNotebook* notebook;
	wxPanel* page_panel;
	wxStyledTextCtrl* textCtrl;

public:

	Frame(const wxString& title = wxEmptyString);
	void OnQuit(wxCommandEvent& e);
	void OnSave(wxCommandEvent& e);
	void OnOpen(wxCommandEvent& e);
	void OnNew(wxCommandEvent& e);
	void OnSaveAs(wxCommandEvent& e);
};

