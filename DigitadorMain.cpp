/***************************************************************
 * Name:      DigitadorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Marco Aurelio Lima (bymarcosoftware@outlook.com)
 * Created:   2020-09-29
 * Copyright: Marco Aurelio Lima ()
 * License:
 **************************************************************/

#include "DigitadorMain.h"
#include <wx/msgdlg.h>

#include "mrcwin.h"

//(*InternalHeaders(DigitadorFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(DigitadorFrame)
const long DigitadorFrame::ID_RICHTEXTCTRL1 = wxNewId();
const long DigitadorFrame::ID_BUTTON1 = wxNewId();
const long DigitadorFrame::ID_STATICTEXT1 = wxNewId();
const long DigitadorFrame::ID_SPINCTRL1 = wxNewId();
const long DigitadorFrame::ID_STATICTEXT2 = wxNewId();
const long DigitadorFrame::ID_STATICTEXT3 = wxNewId();
const long DigitadorFrame::ID_SPINCTRL2 = wxNewId();
const long DigitadorFrame::ID_STATICTEXT4 = wxNewId();
const long DigitadorFrame::ID_STATICTEXT5 = wxNewId();
const long DigitadorFrame::ID_STATICLINE1 = wxNewId();
const long DigitadorFrame::ID_STATICTEXT7 = wxNewId();
const long DigitadorFrame::ID_STATICTEXT6 = wxNewId();
const long DigitadorFrame::ID_STATICTEXT8 = wxNewId();
const long DigitadorFrame::ID_BUTTON2 = wxNewId();
const long DigitadorFrame::ID_GAUGE1 = wxNewId();
const long DigitadorFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DigitadorFrame,wxFrame)
    //(*EventTable(DigitadorFrame)
    //*)
END_EVENT_TABLE()

DigitadorFrame::DigitadorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(DigitadorFrame)
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(530,420));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(144,280), wxSize(532,424), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    RichTextCtrl1 = new wxRichTextCtrl(Panel1, ID_RICHTEXTCTRL1, wxEmptyString, wxPoint(24,72), wxSize(480,232), wxRE_MULTILINE, wxDefaultValidator, _T("ID_RICHTEXTCTRL1"));
    wxRichTextAttr rchtxtAttr_1;
    rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    wxFont Font_1(16,wxFONTFAMILY_MODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Consolas"),wxFONTENCODING_DEFAULT);
    rchtxtAttr_1.SetFontFaceName(Font_1.GetFaceName());
    rchtxtAttr_1.SetFontSize(Font_1.GetPointSize());
    rchtxtAttr_1.SetFontStyle(Font_1.GetStyle());
    rchtxtAttr_1.SetFontUnderlined(Font_1.GetUnderlined());
    rchtxtAttr_1.SetFontWeight(Font_1.GetWeight());
    RichTextCtrl1->SetBasicStyle(rchtxtAttr_1);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Iniciar"), wxPoint(392,324), wxSize(96,32), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("MK Digitador"), wxPoint(176,18), wxSize(56,16), 0, _T("ID_STATICTEXT1"));
    StaticText1->SetForegroundColour(wxColour(86,96,139));
    wxFont StaticText1Font(18,wxFONTFAMILY_MODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Courier New"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    SpinCtrl1 = new wxSpinCtrl(Panel1, ID_SPINCTRL1, _T("200"), wxPoint(112,328), wxSize(58,23), 0, 1, 1000, 200, _T("ID_SPINCTRL1"));
    SpinCtrl1->SetValue(_T("200"));
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Velocidade"), wxPoint(40,325), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("de Escrita"), wxPoint(48,340), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    SpinCtrl2 = new wxSpinCtrl(Panel1, ID_SPINCTRL2, _T("10"), wxPoint(256,328), wxSize(50,23), 0, 5, 600, 10, _T("ID_SPINCTRL2"));
    SpinCtrl2->SetValue(_T("10"));
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Esperar"), wxPoint(208,332), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("seg"), wxPoint(312,332), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(32,368), wxSize(460,2), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("bymarcosoftware@outlook.com"), wxPoint(320,376), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    StaticText7->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("v1.5"), wxPoint(368,26), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText6->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("Cole seu texto aqui..."), wxPoint(24,54), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Limpar"), wxPoint(448,48), wxSize(56,20), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Gauge1 = new wxGauge(Panel1, ID_GAUGE1, 100, wxPoint(24,308), wxSize(480,3), 0, wxDefaultValidator, _T("ID_GAUGE1"));
    Gauge1->SetValue(90);
    Gauge1->Hide();
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DigitadorFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DigitadorFrame::OnButton2Click1);
    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DigitadorFrame::OnPanel1Paint,0,this);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&DigitadorFrame::OnClose);
    //*)
}

DigitadorFrame::~DigitadorFrame()
{
    //(*Destroy(DigitadorFrame)
    //*)
}

void DigitadorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void DigitadorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void DigitadorFrame::OnButton1Click(wxCommandEvent& event)
{
    std::string text = RichTextCtrl1->GetValue().ToStdString();
    int velocity = SpinCtrl1->GetValue();
    int wait = SpinCtrl2->GetValue();

    std::stringstream ss;

    ss << "  A digitação esperará " << wait << " segundos."
       << "\n\n   Para interromper a digitação pressione F9.";

    int res = wxMessageBox( _(ss.str()), wxT("  "), wxOK | wxCANCEL );

    if(res == wxCANCEL){ return; }

    wxSleep(wait);
    mrcwin::virtkeyboard::typeText(text, 2000/velocity);
    wxMessageBox( _("  Concluído!"), wxT("     "), wxICON_INFORMATION);
}

void DigitadorFrame::OnButton2Click(wxCommandEvent& event)
{
    event.Skip();
}


void DigitadorFrame::OnClose(wxCloseEvent& event)
{
    event.Skip(true);
}

void DigitadorFrame::OnPanel1Paint(wxPaintEvent& event)
{
    this->SetIcon( wxICON(aaaa) );
}

void DigitadorFrame::OnButton2Click1(wxCommandEvent& event)
{
    int res = wxMessageBox( _("    Apagar tudo?"), _("    "), wxYES_NO );

    if(res == 2){
        this->RichTextCtrl1->Clear();
    }
}



















