/***************************************************************
 * Name:      DigitadorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Marco Aurelio Lima (bymarcosoftware@outlook.com)
 * Created:   2020-09-29
 * Copyright: Marco Aurelio Lima ()
 * License:
 **************************************************************/

#include "DigitadorApp.h"

//(*AppHeaders
#include "DigitadorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(DigitadorApp);

bool DigitadorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	DigitadorFrame* Frame = new DigitadorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
