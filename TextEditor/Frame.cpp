#include "Frame.h"
#include<wx\wx.h>

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

	main_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* panel_sizer;
	panel_sizer = new wxBoxSizer(wxHORIZONTAL);

	splitter = new wxSplitterWindow(main_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_LIVE_UPDATE);
	

	file_panel = new wxPanel(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	code_panel = new wxPanel(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* code_sizer;
	code_sizer = new wxBoxSizer(wxVERTICAL);

	notebook = new wxAuiNotebook(code_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_DEFAULT_STYLE);
	page_panel = new wxPanel(notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* text_sizer;
	text_sizer = new wxBoxSizer(wxVERTICAL);

	textCtrl = new wxStyledTextCtrl(page_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString);
	textCtrl->SetUseTabs(true);
	textCtrl->SetTabWidth(4);
	textCtrl->SetIndent(4);
	textCtrl->SetTabIndents(true);
	textCtrl->SetBackSpaceUnIndents(true);
	textCtrl->SetViewEOL(false);
	textCtrl->SetViewWhiteSpace(false);
	textCtrl->SetMarginWidth(2, 0);
	textCtrl->SetIndentationGuides(true);
	textCtrl->SetMarginType(1, wxSTC_MARGIN_SYMBOL);
	textCtrl->SetMarginMask(1, wxSTC_MASK_FOLDERS);
	textCtrl->SetMarginWidth(1, 16);
	textCtrl->SetMarginSensitive(1, true);
	textCtrl->SetProperty(wxT("fold"), wxT("1"));
	textCtrl->SetFoldFlags(wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED);
	textCtrl->SetMarginType(0, wxSTC_MARGIN_NUMBER);
	textCtrl->SetMarginWidth(0, textCtrl->TextWidth(wxSTC_STYLE_LINENUMBER, wxT("_99999")));
	textCtrl->MarkerDefine(wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS);
	textCtrl->MarkerSetBackground(wxSTC_MARKNUM_FOLDER, wxColour(wxT("BLACK")));
	textCtrl->MarkerSetForeground(wxSTC_MARKNUM_FOLDER, wxColour(wxT("WHITE")));
	textCtrl->MarkerDefine(wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_BOXMINUS);
	textCtrl->MarkerSetBackground(wxSTC_MARKNUM_FOLDEROPEN, wxColour(wxT("BLACK")));
	textCtrl->MarkerSetForeground(wxSTC_MARKNUM_FOLDEROPEN, wxColour(wxT("WHITE")));
	textCtrl->MarkerDefine(wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY);
	textCtrl->MarkerDefine(wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_BOXPLUS);
	textCtrl->MarkerSetBackground(wxSTC_MARKNUM_FOLDEREND, wxColour(wxT("BLACK")));
	textCtrl->MarkerSetForeground(wxSTC_MARKNUM_FOLDEREND, wxColour(wxT("WHITE")));
	textCtrl->MarkerDefine(wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUS);
	textCtrl->MarkerSetBackground(wxSTC_MARKNUM_FOLDEROPENMID, wxColour(wxT("BLACK")));
	textCtrl->MarkerSetForeground(wxSTC_MARKNUM_FOLDEROPENMID, wxColour(wxT("WHITE")));
	textCtrl->MarkerDefine(wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY);
	textCtrl->MarkerDefine(wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY);
	textCtrl->SetSelBackground(true, wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
	textCtrl->SetSelForeground(true, wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));

	text_sizer->Add(textCtrl, 1, wxEXPAND | wxALL, 5);


	page_panel->SetSizer(text_sizer);
	page_panel->Layout();
	text_sizer->Fit(page_panel);
	notebook->AddPage(page_panel, wxT("a page"), true, wxNullBitmap);

	code_sizer->Add(notebook, 1, wxEXPAND | wxALL, 5);


	code_panel->SetSizer(code_sizer);
	code_panel->Layout();
	code_sizer->Fit(code_panel);
	splitter->SplitVertically(file_panel, code_panel, 167);
	panel_sizer->Add(splitter, 1, wxEXPAND, 5);


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
	wxMessageBox("Create file");
}

void Frame::OnSaveAs(wxCommandEvent& e)
{
	wxMessageBox("Save ass");
}
