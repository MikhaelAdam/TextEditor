#include "Codetab.h"

Codetab::Codetab(wxWindow* m_parent) : wxPanel(m_parent , wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
	stc_tab = new wxStyledTextCtrl(this, wxID_ANY);
	wxFont font(10, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	stc_tab->SetLexer(wxSTC_LEX_CPP);
	stc_tab->StyleSetFont(wxSTC_STYLE_DEFAULT, font);
	stc_tab->SetViewEOL(false);
	stc_tab->SetMarginWidth(1, 0);
	stc_tab->SetUseTabs(true);
	stc_tab->SetTabWidth(4);
	stc_tab->SetIndent(4);
	stc_tab->SetTabIndents(true);
	stc_tab->SetBackSpaceUnIndents(true);
	stc_tab->SetViewWhiteSpace(false);
	stc_tab->SetMarginWidth(2, 0);
	stc_tab->SetIndentationGuides(true);
	stc_tab->SetMarginType(1, wxSTC_MARGIN_SYMBOL);
	stc_tab->SetMarginMask(1, wxSTC_MASK_FOLDERS);
	stc_tab->SetMarginWidth(1, 16);
	stc_tab->SetMarginSensitive(1, true);
	stc_tab->SetProperty(wxT("fold"), wxT("1"));
	stc_tab->SetFoldFlags(wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED);
	stc_tab->SetMarginType(0, wxSTC_MARGIN_NUMBER);
	stc_tab->SetMarginWidth(0, stc_tab->TextWidth(wxSTC_STYLE_LINENUMBER, wxT("_99999")));
	stc_tab->MarkerDefine(wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS);
	stc_tab->MarkerSetBackground(wxSTC_MARKNUM_FOLDER, wxColour(wxT("BLACK")));
	stc_tab->MarkerSetForeground(wxSTC_MARKNUM_FOLDER, wxColour(wxT("WHITE")));
	stc_tab->MarkerDefine(wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_BOXMINUS);
	stc_tab->MarkerSetBackground(wxSTC_MARKNUM_FOLDEROPEN, wxColour(wxT("BLACK")));
	stc_tab->MarkerSetForeground(wxSTC_MARKNUM_FOLDEROPEN, wxColour(wxT("WHITE")));
	stc_tab->MarkerDefine(wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY);
	stc_tab->MarkerDefine(wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_BOXPLUS);
	stc_tab->MarkerSetBackground(wxSTC_MARKNUM_FOLDEREND, wxColour(wxT("BLACK")));
	stc_tab->MarkerSetForeground(wxSTC_MARKNUM_FOLDEREND, wxColour(wxT("WHITE")));
	stc_tab->MarkerDefine(wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUS);
	stc_tab->MarkerSetBackground(wxSTC_MARKNUM_FOLDEROPENMID, wxColour(wxT("BLACK")));
	stc_tab->MarkerSetForeground(wxSTC_MARKNUM_FOLDEROPENMID, wxColour(wxT("WHITE")));
	stc_tab->MarkerDefine(wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY);
	stc_tab->MarkerDefine(wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY);
	stc_tab->SetSelBackground(true, wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
	stc_tab->SetSelForeground(true, wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));
	stc_tab->SetKeyWords(0, "int string char bool float double");
	stc_tab->StyleSetForeground(wxSTC_C_WORD, wxColour(0, 0, 225));
	
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(stc_tab, 1, wxEXPAND);
	SetSizer(sizer);
}
