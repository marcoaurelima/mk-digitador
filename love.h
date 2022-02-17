#ifndef LOVE_H
#define LOVE_H

//(*Headers(love)
#include <wx/panel.h>
//*)

class love: public wxPanel
{
	public:

		love(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~love();

		//(*Declarations(love)
		//*)

	protected:

		//(*Identifiers(love)
		//*)

	private:

		//(*Handlers(love)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
