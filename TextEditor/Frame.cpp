#include "Frame.h"
#include<wx\wx.h>

Frame::Frame(const wxString &title): wxFrame(nullptr, wxID_ANY, title)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* sizer;
	sizer = new wxBoxSizer(wxVERTICAL);

	main_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* panel_sizer;
	panel_sizer = new wxBoxSizer(wxHORIZONTAL);

	m_splitter3 = new wxSplitterWindow(main_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D | wxSP_LIVE_UPDATE);
	m_splitter3->SetSashPosition(100);

	m_panel5 = new wxPanel(m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel3 = new wxPanel(m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxVERTICAL);

	textCtrl = new wxStyledTextCtrl(m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString);
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


	bSizer3->Add(textCtrl, 1, wxEXPAND | wxALL, 5);


	m_panel3->SetSizer(bSizer3);
	m_panel3->Layout();
	bSizer3->Fit(m_panel3);
	m_splitter3->SplitVertically(m_panel5, m_panel3, 0);
	panel_sizer->Add(m_splitter3, 1, wxEXPAND, 5);


	main_panel->SetSizer(panel_sizer);
	main_panel->Layout();
	panel_sizer->Fit(main_panel);
	sizer->Add(main_panel, 1, wxEXPAND | wxALL, 5);


	this->SetSizer(sizer);
	this->Layout();

	this->Centre(wxBOTH);
}
