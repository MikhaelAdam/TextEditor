#include "Frame.h"
#include<wx\wx.h>

Frame::Frame(const wxString &title): wxFrame(nullptr, wxID_ANY, title)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	wxMenuBar *menu = new wxMenuBar();

	wxMenu* filemenu = new wxMenu();
	filemenu->Append(wxID_NEW);
	filemenu->Append(wxID_OPEN);
	filemenu->AppendSeparator();
	filemenu->Append(wxID_SAVE);
	filemenu->Append(wxID_SAVEAS);
	filemenu->Append(wxID_EXIT);
	
	wxMenu* editmenu = new wxMenu();
	editmenu->Append(wxID_UNDO);
	editmenu->Append(wxID_REDO);
	editmenu->Append(wxID_FIND);
	editmenu->Append(wxID_REPLACE);
	menu->Append(filemenu, "File");
	menu->Append(editmenu, "Edit");
	this->SetMenuBar(menu);
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	main_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* panel_sizer;
	panel_sizer = new wxBoxSizer(wxHORIZONTAL);

	splitter = new wxSplitterWindow(main_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D | wxSP_LIVE_UPDATE);
	splitter->SetSashPosition(100);

	file_panel = new wxPanel(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	code_panel = new wxPanel(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxVERTICAL);

	textCtrl = new wxStyledTextCtrl(code_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString);
	wxFont font(10, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	textCtrl->StyleSetFont(wxSTC_STYLE_DEFAULT, font);

	textCtrl->SetLexer(wxSTC_LEX_CPP);
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
	textCtrl->StyleSetForeground(wxSTC_C_WORD, wxColour(0, 0, 255));
	textCtrl->StyleSetForeground(wxSTC_C_DEFAULT, wxColour(0, 255, 0));
	textCtrl->SetKeyWords(0, "if else while for int string float bool double char class private public protected struct");
	wxString sampleCode = "if (condition)\n{\n    // code\n}";
	
	textCtrl->SetText(sampleCode);

	bSizer3->Add(textCtrl, 1, wxEXPAND | wxALL, 5);

	splitter->SetBackgroundColour(wxColour(0, 0, 0));

	code_panel->SetSizer(bSizer3);
	code_panel->Layout();
	bSizer3->Fit(code_panel);
	splitter->SplitVertically(file_panel, code_panel, 0);
	panel_sizer->Add(splitter, 1, wxEXPAND, 5);

	main_panel->SetSizer(panel_sizer);
	main_panel->Layout();
	panel_sizer->Fit(main_panel);
	sizer->Add(main_panel, 1, wxEXPAND | wxALL, 5);


	this->SetSizer(sizer);
	this->Layout();

	this->Centre(wxBOTH);
}
