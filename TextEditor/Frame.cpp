#include "Frame.h"
#include "Codetab.h"

Frame::Frame(const wxString &title): wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition ,wxSize(1920,1080))
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	wxMenuBar *menu = new wxMenuBar();

	wxMenu* filemenu = new wxMenu();
	filemenu->Append(wxID_NEW, "&New\tCtrl+N");
	filemenu->Append(wxID_OPEN,"&Open\tCtrl+O");
	filemenu->AppendSeparator();
	filemenu->Append(wxID_SAVE, "&Save\tCtrl+S");
	filemenu->Append(wxID_SAVEAS, "&Save As\tCtrl+Shift+S");
	filemenu->Append(wxID_EXIT, "&Quit\tCtrl+Q");
	
	wxMenu* editmenu = new wxMenu();
	editmenu->Append(wxID_UNDO);
	editmenu->Append(wxID_REDO);
	editmenu->Append(wxID_FIND);
	editmenu->Append(wxID_REPLACE);
	menu->Append(filemenu, "File");
	menu->Append(editmenu, "Edit");
	this->SetMenuBar(menu);
	wxBoxSizer* sizer;
	sizer = new wxBoxSizer(wxVERTICAL);

	wxPanel *main_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* panel_sizer;
	panel_sizer = new wxBoxSizer(wxHORIZONTAL);

	wxSplitterWindow *splitter = new wxSplitterWindow(main_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_LIVE_UPDATE);
	

	wxPanel *file_panel = new wxPanel(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxPanel *code_panel = new wxPanel(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* code_sizer = new wxBoxSizer(wxVERTICAL);

	notebook = new wxAuiNotebook(code_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_DEFAULT_STYLE| wxAUI_NB_TAB_MOVE| wxAUI_NB_SCROLL_BUTTONS);

	wxBoxSizer* text_sizer = new wxBoxSizer(wxVERTICAL);

	//Create a codetab and add it to the notebook
	Codetab* codetab = new Codetab(notebook);
	notebook->AddPage(codetab, wxT("cpp"));
	code_sizer->Add(notebook, 1, wxEXPAND | wxALL, 5);

	//Organize the panels in sizers
	code_panel->SetSizer(code_sizer);
	code_panel->Layout();
	code_sizer->Fit(code_panel);
	splitter->SplitVertically(file_panel, code_panel, 167);
	panel_sizer->Add(splitter, 1, wxEXPAND, 5);
	file_panel->SetBackgroundColour(*wxBLUE);
	code_panel->SetBackgroundColour(*wxRED);

	main_panel->SetSizer(panel_sizer);
	main_panel->Layout();
	panel_sizer->Fit(main_panel);

	this->Centre(wxBOTH);
	this->Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnQuit));
	this->Connect(wxID_SAVEAS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnSaveAs));
	this->Connect(wxID_SAVE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnSave));
	this->Connect(wxID_NEW, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnNew));
	this->Connect(wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnOpen));

}

void Frame::OnQuit(wxCommandEvent& e)
{
	this->Close();
}

void Frame::OnSave(wxCommandEvent& e)
{
	wxMessageBox("Simple Save");
}

void Frame::OnOpen(wxCommandEvent& e)
{
	wxMessageBox("Open a file");
}

void Frame::OnNew(wxCommandEvent& e)
{
	Codetab* codetab = new Codetab(notebook);
	notebook->AddPage(codetab, wxT("cpp"));
	
}

void Frame::OnSaveAs(wxCommandEvent& e)
{
	wxMessageBox("Save ass");
}
