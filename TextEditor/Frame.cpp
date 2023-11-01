#include "Frame.h"
#include "Codetab.h"

Frame::Frame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize)
{
	wxMenuBar* menu = new wxMenuBar();

	wxMenu* filemenu = new wxMenu();
	filemenu->Append(wxID_NEW, "&New\tCtrl+N");
	filemenu->Append(wxID_OPEN, "&Open\tCtrl+O");
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

	wxPanel* main_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* panel_sizer = new wxBoxSizer(wxHORIZONTAL);

	wxSplitterWindow* splitter = new wxSplitterWindow(main_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_NO_XP_THEME | wxSP_LIVE_UPDATE);


	wxPanel* file_panel = new wxPanel(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxPanel* code_panel = new wxPanel(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* code_sizer = new wxBoxSizer(wxVERTICAL);

	notebook = new wxAuiNotebook(code_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_DEFAULT_STYLE);


	wxBoxSizer* text_sizer = new wxBoxSizer(wxVERTICAL);

	//Create a codetab and add it to the notebook
	code_sizer->Add(notebook, 1, wxEXPAND | wxALL, 5);

	//Organize the panels in sizers
	code_panel->SetSizerAndFit(code_sizer);
	code_panel->Layout();

	splitter->SplitVertically(file_panel, code_panel, 167);
	panel_sizer->Add(splitter, 1, wxEXPAND, 5);

	main_panel->SetSizerAndFit(panel_sizer);
	main_panel->Layout();


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
	e.Skip();
}

void Frame::OnSave(wxCommandEvent& e)
{

}

void Frame::OnOpen(wxCommandEvent& e)
{
	wxFileDialog openFileDialog(this, "Open File", "", "", "C++ Files (*.cpp;*.h)|*.cpp;*.h|Text Files(*.txt)|*.txt|All Files (*.*)|*.*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (openFileDialog.ShowModal() == wxID_CANCEL) {
		return;
	}

	wxString filePath = openFileDialog.GetPath();
	wxString fileName= openFileDialog.GetFilename();

	std::ifstream file(filePath.ToStdString());
	if (!file.is_open()) {
		wxLogError("Failed to open the file.");
		return;
	}

	// Read the file content into a wxString
	wxString fileContents;
	std::string line;
	while (std::getline(file, line)) {
		fileContents += wxString::FromUTF8(line.c_str()) + "\n";
	}

	file.close();

	Codetab* codetab = new Codetab(notebook);
	codetab->stc_tab->SetText(fileContents);
	notebook->AddPage(codetab, fileName);
}
 

void Frame::OnNew(wxCommandEvent& e)
{
	Codetab* codetab = new Codetab(notebook);
	notebook->AddPage(codetab, wxT("untitled"));
	e.Skip();

}

void Frame::OnSaveAs(wxCommandEvent& e)
{
	wxMessageBox("Save ass");
	e.Skip();
}