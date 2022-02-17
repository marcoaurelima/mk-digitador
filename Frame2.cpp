#include "Frame2.h"

//(*InternalHeaders(Frame2)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Frame2)
const long Frame2::ID_BUTTON1 = wxNewId();
const long Frame2::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Frame2,wxFrame)
	//(*EventTable(Frame2)
	//*)
END_EVENT_TABLE()

Frame2::Frame2(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Frame2)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxPoint(104,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, ID_BUTTON2, _("Label"), wxPoint(120,392), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	//*)
}

Frame2::~Frame2()
{
	//(*Destroy(Frame2)
	//*)
}

