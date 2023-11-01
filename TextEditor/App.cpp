#include "App.h"
#include "Frame.h"


wxIMPLEMENT_APP(App);
bool App::OnInit()
{

	Frame* frame = new Frame("Editor");
	frame->Show();
	frame->Maximize();
	
    return true;
}
