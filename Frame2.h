#ifndef FRAME2_H
#define FRAME2_H

//(*Headers(Frame2)
#include <wx/button.h>
#include <wx/frame.h>
//*)

class Frame2: public wxFrame
{
	public:

		Frame2(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Frame2();

		//(*Declarations(Frame2)
		wxButton* Button1;
		wxButton* Button2;
		//*)

	protected:

		//(*Identifiers(Frame2)
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(Frame2)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
