#ifndef FRAMELOVE_H
#define FRAMELOVE_H

//(*Headers(FrameLove)
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
//*)

class FrameLove: public wxFrame
{
	public:

		FrameLove(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~FrameLove();

		//(*Declarations(FrameLove)
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(FrameLove)
		static const long ID_STATICTEXT1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(FrameLove)
		void OnPanel1Paint(wxPaintEvent& event);
		void OnKeyDown(wxKeyEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnLeftDown(wxMouseEvent& event);
		void OnChar(wxKeyEvent& event);
		void OnPanel1KeyDown(wxKeyEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
