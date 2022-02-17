/***************************************************************
 * Name:      DigitadorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Marco Aurelio Lima (bymarcosoftware@outlook.com)
 * Created:   2020-09-29
 * Copyright: Marco Aurelio Lima ()
 * License:
 **************************************************************/

#ifndef DIGITADORMAIN_H
#define DIGITADORMAIN_H

//(*Headers(DigitadorFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/panel.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/spinctrl.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)

class DigitadorFrame: public wxFrame
{
    public:

        DigitadorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~DigitadorFrame();

    private:

        //(*Handlers(DigitadorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnPanel1KeyUp(wxKeyEvent& event);
        void OnRichTextCtrl1TextEnter(wxCommandEvent& event);
        void OnRichTextCtrl1RichTextContentInserted(wxRichTextEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnKeyUp(wxKeyEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnButton2Click1(wxCommandEvent& event);
        //*)

        //(*Identifiers(DigitadorFrame)
        static const long ID_RICHTEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT1;
        static const long ID_SPINCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_SPINCTRL2;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_STATICLINE1;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT8;
        static const long ID_BUTTON2;
        static const long ID_GAUGE1;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(DigitadorFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxGauge* Gauge1;
        wxPanel* Panel1;
        wxRichTextCtrl* RichTextCtrl1;
        wxSpinCtrl* SpinCtrl1;
        wxSpinCtrl* SpinCtrl2;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxStaticText* StaticText8;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DIGITADORMAIN_H
