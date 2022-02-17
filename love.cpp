#include "love.h"

//(*InternalHeaders(love)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(love)
//*)

BEGIN_EVENT_TABLE(love,wxPanel)
	//(*EventTable(love)
	//*)
END_EVENT_TABLE()

love::love(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(love)
	Create(parent, id, wxDefaultPosition, wxSize(930,515), wxTAB_TRAVERSAL, _T("id"));
	//*)
}

love::~love()
{
	//(*Destroy(love)
	//*)
}

