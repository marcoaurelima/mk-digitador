#include "FrameLove.h"
#include <sstream>
//(*InternalHeaders(FrameLove)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(FrameLove)
const long FrameLove::ID_STATICTEXT1 = wxNewId();
const long FrameLove::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(FrameLove,wxFrame)
	//(*EventTable(FrameLove)
	//*)
END_EVENT_TABLE()

FrameLove::FrameLove(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(FrameLove)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(720,720));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(320,280), wxSize(1366,496), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Label"), wxPoint(0,0), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(7,wxFONTFAMILY_MODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Consolas"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	Center();

	Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&FrameLove::OnPanel1Paint,0,this);
	Panel1->Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&FrameLove::OnPanel1KeyDown,0,this);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&FrameLove::OnClose);
	Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&FrameLove::OnKeyDown);
	Connect(wxEVT_CHAR,(wxObjectEventFunction)&FrameLove::OnChar);
	Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&FrameLove::OnLeftDown);
	//*)
}

FrameLove::~FrameLove()
{
	//(*Destroy(FrameLove)
	//*)
}


void FrameLove::OnPanel1Paint(wxPaintEvent& event)
{
    this->SetIcon( wxICON(aaaa) );

    std::stringstream ss;

/*

ss <<
":....................-:+syddddddddyo/-./shdddddddddddddhhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyssssssssssssssooooooo/  -.`   ```                        \n" <<
".................-/oyhddddddddyo:...../dddddddddddddhhhhhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyysyssssssssssssssssooooo:  `                                \n" <<
".............:+syddddddddys+:.....----oddddddddddddddddhhhhhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyssssssssssssssssssooooo.``                                 \n" <<
"........-/oshdmmmmmmdyo/-...-------./ohddddddddddddddddhhhhhhhhhhhhhhhhhhhhyyyyyyyyyysosssysssosssssssssssssso+oo+.``                                 \n" <<
"...-:+shdmmmmmmdhyo:------::----...+osddddddddddddddddhdhhhhhhhhhhhhhhhhhhhhyyyyys+:::///+sssso++osssssssssssoo+/:-.`   ```````                       \n" <<
"/oyddmmmmmmdys+-----:::::::---.....shdddddddddddddddddhdhhhhhhhhhhhhhhhhhhhhyy++:....---:::::+ossssssssssssssoooo:.```.+++/:--`                       \n" <<
"mmmmmmmhyo/--.------------........-yddddddddddddddddddddhhhhhhhhhhhhhhhhhhhhyy/-``````....--//osoooossssssssoooo/-.````.```` ``                       \n" <<
"mmmhs+:--..----------.............:dddddddddddddddddddddhhhhhhhhhhhhhhhhhhhhy/.`   ```....-::::-..--+sssssosoooo+-.  `..`     `                       \n" <<
"ho:-..---::---.--.................:dddddddddddddddddddddhhhhhhhhhhhhhhhhhyso/.`       ````....``` ``-::/+++o//oo+-`    `.`                            \n" <<
"yyso/------......................:+dddddddddddddddddddddhhhhhhhhhhhhhysoo:...             ``         ``..-:/+///+/-                  ``               \n" <<
"ymmmy/-........................`.:sdddddddddddddddddddddhhhhhhhsosoo+::/:.``                            ```.-://+o/.                 .:               \n" <<
"ossh:-..`................``..`..-:odddddddddddddddddddddhhhhhhs:::.......`                                 `....---.`                `:.              \n" <<
"/:--+-.``.................``...-:/ohddddddddddddddddddddhhhhho/-.```````                                     ```.....`             `` `-.             \n" <<
"-...-/-................`.`.....:/sydddddddddddddddddddddhhhhs/-.`````                                           `.---..```  ``````--`   ``            \n" <<
"-...../:........```.`..`..-:///::oddddddddddddddddddddhhhhhy+-..``                                               `-:..--...``.///++:`     `           \n" <<
".......::............-:/osssso//:oddddddddddddddddddddhhhhho/-.```  ` ````                                        `----/:-:.``.://:.                  \n" <<
"/-......:+-.....--/oyhddddddddddddddddddddddddddddddhddhhhh+:..``````````            `.-//-.````````              ``..:++/:--.`````                   \n" <<
"os-......:o:-:+oyhdddddddddddddddddddddddddddddddddddhhhhhs/-....````````        `.:/osyyo/:--....``               ``..:/o++/-..``                    \n" <<
"/++/-...--:oohddddddddddddddddddddddddddddddddddddddhddhhho/---....``````      `-+syyyyss+:-......``                ``.-:+++++/:.```                  \n" <<
"-:+ds/:--:+yddddddddddddddddddddddddddddddddddddddhhhhhhhyo/::---...````    ``-+syyyss+:-...---..```                 ``.-:/+++++:--.`                 \n" <<
"--+y/-`./yddddddddddddddddddddddddddddddddddddddddhhhhhhhyo+/::---...```  ``-+syyyyo:-....-/:..`````                 ```.-///++++/+:.`                \n" <<
"-:-.``:sddddddddddddddddddddddddddhsosyhddddhdddddhdhhhhhhyso+/:--...`````-/yyyyyyo:-:/:-:os-....``                  ```...-:/++++++/:.`            ``\n" <<
"`   .oddddddddddddddddddddddddddhh+:.--:/++++oyhhhhhhhhhhhhhyso/:-....```/syyyyyyyo+o+++ssso/:-```                  ``.----.-:/+++++++:`              \n" <<
"   .sdddddddddddddddddddddddddddo:-.```````....-:+shhhhhhhhhhho/:-.....-+yyyyyyyyyyysssysssss+.```                 `.-/+///-.-/++/++++/``             \n" <<
"  -yddddddddddddddddddddddddhhyo:..``````````````.-:/oyhhhhhhho//:-...-oyyyyyyyyyyyyyyyyssss/-..```               ``..-:/++--/+++/++++/.`             \n" <<
" -hddddddddddddddddddddddddy+:-.`               ```.-:/+yhhhhhyo//:---:syyyyyyysssssyysssso/...```               ```.`.-::--/+++++++++/-```           \n" <<
".hddddddddddddddddddddddhs/-.`                    ````.-:oyhhhhyssoo+++syyyyo/-.```-+oo++:.`````                ```.-``.````.:/+++++++/.```           \n" <<
"yddddddddddddddddddddddh+.`                         `````.:shhhhhhyyyyyyyys/.`      ```````````                  ```.`.:```.:+++++++++/.````          \n" <<
"dddddddddddddddddddddyo:`                                ``-+yhhhhyyyyyyyyyo.             ``````                 ``.......-:++++++++++:...```         \n" <<
"dddddddddddddddddddh+-``                                   ``:oyyyyyyyyyyyyy:`           ``...`````             ``.:--::/:///++++++++/:...````        \n" <<
"dddddddddddddddddhs:.`                                    `.--/syyyyyyyyyyyyo`             `.--..`````          ``.--/:--..-:+++++++///--.```         \n" <<
"dddddddddddddddh/-`                                    `-+o/:-:/+o/oyyyyyyyyy/`             `....-...```````` ```.-:////://+++++++////---.```         \n" <<
"dddddddddddddddo.`                                   `-oyo-````.-//::+syyyyyys.              .`````...````````````-:++++++++++++++/////-.```          \n" <<
"ddddddddddddddd/.`                                  .oyy:` ``.:+++/-..:oyyyyyy+            `--`````..--.....`````.-///+++++++++++/////:..```          \n" <<
"ddddddddddddhhd+.``                               `:yyo.  ./syyyyy:.```-+syysso`        `-/+/```.://+oo+++//::....-:-:/+++++++++//////.````           \n" <<
"hhdhhhhhhhhhhhhy-```                             `-+o+.`:syyy+yys+.`  ``-/sssos:      `/sss:-::/oooooooooooooo++///+//+++++++++//////-`````           \n" <<
"hhhhhhhhhhhhhhhy:.````                           `-/:-:syyyyy++-..`    ``.:sssso.`   `:osssosoooo//ooooooooooo+++++++++++++++++/////:`````            \n" <<
"hhhhhhhhhhhhhhhh+-..```                         ``-::/yysyo:--..``      ``.:sssso+//++ossoooooo/--/o+:--..-:/+++++++++++++++/++/////.`````            \n" <<
"hhhhhhhhhhhhhhhhs:--.```                         ``.--/+-.`````           `-/ssssssssssssooo////+o+-```` ````.+++++++++++++/+//////-``````            \n" <<
"hhhhhhhhhhhhhhhhho-..```            ````````      ``.`                     `-sssssssssssso++oooo+-```.``````.-+++++++++++++///////-``````             \n" <<
"hhhhhhhhhhhhhhhhhh+-```         `.:/ooo+/:-.`       ``                     `.+sssssssssooooooo+-.....--....-:+++++++++++++////////-````````````````   \n" <<
"hhhhhhhhhhhhhhhhhhy/-.``    `./osyyysssoo+/-.`                            ``.+ssssssosoooooooo+::://++o+:-:++++++++++++///////////:-..``....````````` \n" <<
"hhhhhhhhhhhhhhhhhhhy+-.```./sso+/-.-:+oo+/-..``                      ``  ``.:ossssssoooooooooooooooooo+++++++++++++++++////////////::::://::--........\n" <<
"hhhhhhhhhhhhhhhhhhhhys:..+so:``` ./sysoss+.  ```             ````.........-://++ooooooooooooooooooooo++++++++++++++++++///////////////::----::::::::::\n" <<
"hhhhhhhhhhhhhhhhhyyyyys+os-````:oyyyy/::.``                 `  `````.--:///::--/+oooooooooooooooooo+++++++++++++++++++/////////////:-.```..-::::::::::\n" <<
"yysyyyyyyyyyyyyyyyyyyyyyy+-.-:oyyyyyo:-```                           ``.-:-.`..:+oooooooooooooooo+++++++++++++++++++/////////////::---:::::/::::::::::\n" <<
"yyosyyyyyyyyyyyyyyyyyyyyysoosyyyyyyo:````                       `-    `.//.``..-+oooooooooooooo+++++++++++++++++++/////////////////////////:::::::::::\n" <<
":yyyyyyyyyyyyyyyyyyyyyyyyyyyysooo/-.```          ````         `.+:    `//.````.-+oooooooooooooo++++++++++++++++/+///////////////////////::::::::::::::\n" <<
"`+yyyyyyyyyyyyyyyyyyyyyyyyyy/.````              ``` ``        .oo`  `.+o.`  ``.-/oooooooooooo++++++++++++++++++////////////////////////:::::::::::::::\n" <<
" `+yysyyyyyyyyyyyyyyyyyyyyyy/`                 `..`  ```    `-+s- `.:oo:``` ```./oooooooooo++++++++++++++++++//////////////////////////:::::::::::::::\n" <<
"  `+ys+syyyyyyyyyyyyyyyyyyyy+``                ````...-::///+os+`.:+++:..``````.+ooooooo++++++++++++++++++++////////////////////////::::::::::::::::::\n" <<
"   ./sssyyyyyyyyyyyyyyysssss+````             ```  .:++ooooooso--//:..`...`````.+oooooo++++++++++++++++++/++///////////////////////:::::::::::::::::::\n" <<
"    `-+syyssssssssssssssssss+.````           ```     ```...-//++/.`````--``````.+oo+++++++++++++++++++++/////////////////////////:::::::::::::::::::::\n" <<
"     `./sssssssssssssssssssss/-.`````      `````  ```   `-:/++:.``````-:.``````-++++++++++++++++++++++///////////////////////////::::::::::::::::::::-\n" <<
"       `:ssssssssssssssssssssso:-....```````..`````...-/+oo///.`````.-:-```  ``-+++++++++++++++++++++//////////////////////////:::::::::::::::::::::-:\n" <<
"   ``..-:+sssssssssssssssssssssso+:---.........``./+++++:-..`````..-//-``     `:+++++++++++++++++////////////////////////////:::::::::::::::::::::-::-\n" <<
" ``.--:::+sssssssssssssssssssssssso/------........-.`````...----:///:``       .+++++++++++++++////////////////////////////:/:::::::::::::::::::::::::-\n" <<
"`.------:/osssssssssssssssssssssssso+:.......``````````````.......``          -+++++++++++++++////////////////////////////::::::::::::::::::::::::::--\n" <<
"------:::+osssssssssssssssosssoosooooo+:..........``````````````             `/++++++++++++///////////////////////////://::::::::::::::::::::::::-----\n" <<
"::--::://ossssssosssoooosooooooooooooooo++/:::------..```````              `.:++++++++++//////////////////////////////::::::::::::::::::::::-:::::----\n" <<
"::--://+ooooooooooooooooooo+oooooooooooooooooo++//:::---..````           `.-/+++++++++//////////////////////////////:::::::::::::::::::::::::::-------\n" <<
"::::/ooooooooooooooooooooo+ooooooooooooooooooooooo++////+//:--..``````..-//+++++++++///////////////////////////////::::::::::::::::::::::::::-:-------\n" <<
"::/+oooooooooooooooooooooo/o+++//++oooooooooooooooooo++++++++++++/////+++++++++////////////////////////////////:::::::::::::::::::::::::-::::---------\n" <<
"::+ooooooooooooooooooooooo+/:++///::+ooooooooo++++++++++++++++++++++++++++++++///////////////////////////////:/::::::::::::::::::::::::::-:-----------\n" <<
"//+oooooooooooooooooooooooo/:.---://:/++o++++++++++++++++++++++++++++++++++//////.`:///////////////////////::::::::::::::::::::::::--::::-------------\n" <<
"/+ooooooooooooooooooooooooo+:..:.-.://::+++++++++++++++++++++++++++++++////////:.` `:////////////////////::::-:::::::::::::::::::--:::----------------\n" <<
"o+oooooooooooooooooooooo++++++++::/-`.`./+++++++++++++++++++++++++//////////:-.`    `//////////////////::::::``::::::::::::::::--:::------------------\n" <<
"+++++++++++++++++++++++++++++++++++/::--://++++++++++++++++++++/////////////.        ./////////////:::::::::.  `:::::::::::::-::::-::-----------------\n" <<
"++++++++++++++++++++++++++++++++++++++++++++++++++++++++////////////////////:.        ://///////::::::::::::    `:::::::::::::::-:--------------------\n" <<
"++++++++++++++++++++++++++++++++++++++++++++++++++////////////////////////////.       `///////:::::::::::::.     .::::::::::::------------------------\n" <<
"+++++++++++++++++++++++++++++++++++++++++++++/+////////////////////////////////-`      :///:::::::::::::::-       .:::::::::-:------------------------\n" <<
"+++++++++++++++++++++++++++++++++++++///////////////////////////////////////////:.`    .:/::::::::::::::::`        -::::::----------------------------\n" <<
"++++++++++++++++++++++++++++++++++///////////////////////////////////////////////:-.   `:::::::::::::::::-         `-:---:----------------------------\n" <<
"+++++++++++++++////++//++///////////////////////////////////////////////////////::::-.  :::::::::::::::::.          `---------------------------------\n" <<
"/////////////////////////////////////////////////////////////////////////////::::::::::.-::::::::::::::::.           `--------------------------------\n" <<
"//////:-://////////////////////////////////////////////////////////////::::::::::::::::::::::::::::::::::`            `-------------------------------\n";


*/

ss <<
"ysssssooosssssssssssyyyhddmmmmmmmmdhyssddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmh-.yo:...://:.``````````````````````\n" <<
"ssssoosssssssssssyhhdmmmmmmmmmdhyssssyhmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmy-::``   ```.:.`````````````..``````\n" <<
"ssssssssssyssyhddmmmmmmmmddhysssyyhhhydmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmms+/:.` `    ``-.````````.```````````\n" <<
"sssssssyyhdddmmmmmmmmdhyysyyyhhhhhhyddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmyo+:.``````````-.`````.`````````````\n" <<
"syyyyhddmmmmmmmmmdhyyyyyyhddhhhhysshmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdhhdmmmmmmmmmmmmmmmmmmmmmmmmmmdhhs+-`./+ooo+:.`.-```````````````.```\n" <<
"hdddmmmmmmmmddhyyyyhdhdddddhyyssoosmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdmhsssyhhhdddddmmmmmmmmmmmmmmmmmmmmdyo+/odddddhyo:``-.``````````````.```\n" <<
"mmmmmmmmdhhyyyyhyhyhyhhyyyyssoooooymmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdy+/+++ossyyyhdmmmdddmmmmmmmmmmmmmdyy+/++o:----:+:``..``````````````.```\n" <<
"mmmmdhyyyyyyhhhhhhhhyyysssoooooooshmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdo::-::/+oosyhdhdhyssyhdmmmmmmmmmmmdhs:-/oo/-```.:.``..`..```````````````\n" <<
"mdhyyyyyhhhhyyyyyysssssssoooooossshmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdhs/--...-::/+ooooo++:-:+yhhdmmmmmmmmmy+-.`./o/.` `-`` ```.-..``.``````````\n" <<
"mdddhhhyhhyyssssssssssoooooooossshdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmhsoo:..`.```.--:::::-.`````.-+syhdmmmmdmmy:.````````-.```` `:/.`.``````....``\n" <<
"mmmmddyyssssssssssssssooooosooooshmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddho/:-.````````````````     ````-:/oyyhddmmds:-.--.-..-.```` `+h-````..........\n" <<
"mmmmhyso+ssssssssoosssoooo+oooosyhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmddhsssooso/--.....`````     ```    ``````.-:+ossyhyhs/-.--...`````  `-+ho...........```\n" <<
"dhyyhys+:ossssooooooooooooooooshdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdhso+/////:------....```  ``````````````````.--/++oysys/:-...```````.:/:/yo..........`..\n" <<
"hyssyhysosssooooooooooooooooooshdmmmmmmmmmmmmmmmmmmmmmmmmmmmmdhso++//::----------..```   `````````````````...--:/shhyys+/:--:/:::/sh/--:+:-...........\n" <<
"yysssshysooooooooooooooooosyyhyyydmmmmmmmmmmmmmmmmmmmmmmmmmmmhso+/:::::--:::-----..```     ```````...`````.....-:+ydysyhyys/:sddddmh:..--:/.``........\n" <<
"yysssssyysooooooooosssyyhdddddysodmmmmmmmmmmmmmmmmmmmmmmmmmmmys+//::::::::::-------.`` ``..---.------.```..-...--:+yyyhdhddso+ohddh+.`...---..........\n" <<
"hyssssooyhyoooosyyyhddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdyo++////////::::----...`-/+shyyo++++++/:.````...-.--:/osyhmmdddyo//++:.``....----........\n" <<
"mdyssssosydysyhdddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmhysooo+++///::::-----:+yydmmmmmdhyyysso/:.`  ``..-----:/osydmmmmdhso//:-.......----.......\n" <<
"dmdhyssssyhddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmhhysssoo++//::----:+sdmmmmmmmddhyysyso+/:.`   ``..----:::+ohdmmmmmdhs++/:.......-----.....\n" <<
"ydmmmhhyyyhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddhhyyso++//::--:+shmmmmmmdhysooyyhsso+/-.`    ``.-----::/+shddmmmmmdyys+--..`...---::--..\n" <<
"yyddhyoohdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdhyysso+//::/+ydmmmmmmdhssssydhsoooo+/-.`   ``....---::/+oshddmmmmmmmds/:-...`..---:::::\n" <<
"hys+:+sdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdhyysso+//+yhmmmmmmmdhhhhyydmysssoo/:.`   ````...---::/+osyyhdmmmmmmmdhs/-..``..---::/:\n" <<
"-..-+hmmmmmmmmmmmmmmmmmmmmmmmmmmmmdhyyhyyhddddddmmmmmmmmmmmmmmmmdyyysoo++ymmmmmmmmmmmmmdmmmmddyo++:-.```````...---::/+oyyhhyhdmmmmmmmmh+:-..`....--:::\n" <<
"`.-odmmmmmmmmmmmmmmmmmmmmmmmmmmmmdho++++ooosssssydmmmmmmmmmmmmmmdhyysssydmmmmmmmmmmmmmmmmmmmmdso++:-.```````...--::/oydmdddysydmmdmmmmdo/--......---::\n" <<
"..odmmmmmmmmmmmmmmmmmmmmmmmmmmmdhso+++://://+++++syhdmmmmmmmmmmmmdhyyyhdmmmmmmmmmmmmmmmmmmmmdysoo+:--```````...--:+osshdmmmhhdmmmdmmmmds/:--.....-----\n" <<
".+dmmmmmmmmmmmmmmmmmmmmmmmmmdhyo/-----....----:::/osyhdmmmmmmmmmmmdhyydmmmmmmmmddddmmmmmmmddysoo+/:-.`` `````.--://oyosyhhhhdmmmmmmmmmmy+/:----...----\n" <<
"/dmmmmmmmmmmmmmmmmmmmmmmmdhso/-.````````````..---:/+oooyhdmmmmmmmmmdddmmmmmmdho+//+sdddddyso++//::-..`` `````..-//+syooso/+oshdmmmmmmmmy++/::---------\n" <<
"dmmmmmmmmmmmmmmmmmmmmmmmdo:-.``            ``...--::////+ohdmmmmmmmmmmmmmmmds:```..:::::///////:---.````` ```.--:/+osoyh++oshmmmmmmmmmdyoo+/::--------\n" <<
"mmmmmmmmmmmmmmmmmmmmmmhy+:.`                ``....-----::/+ydmmmmmmmmmmmmmmms:`  ```````-:/+++//::--..``````.---:/+ossssssyhmmmmmmmmmmdysso//::-------\n" <<
"mmmmmmmmmmmmmmmmmmmmdy+:.`                 ```````.....---:/ohdmmmmmmmmmmmmmh/.        `-/+ssso+///:---..`..---:/+ydhhhhddddmmmmmmmmmmdyyso+//:-------\n" <<
"mmmmmmmmmmmmmmmmmmdho:.``                  ````````````..-+ssydmmmmmmmmmmmmmd+-`       `..-/syyyso++/:::------::/+syhddhhsyhdmmmmmmmmmdhyso+/::-------\n" <<
"mmmmmmmmmmmmmmmmdy+-.``                         ``````.:ohddysyhdmmdmmmmmmmmmh:.`     ````../ossyyysoo+++///::///ohdmmmddddmmmmmmmmmmmhhyso+/:---..---\n" <<
"mmmmmmmmmmmmmmmdy+:-.``                        ````..:odmdo/:/+yhmmdhdmmmmmmmms-`   ````  `.:so//+ossoooo++++////oydmmmmmmmmmmmmmmmmmmdyso+/:---....--\n" <<
"mmmmmmmmmmmmmmmdo+:...``                      ```..:odmmy/-:+shdmmmhsshdmmmmmmh:`` ```````-/sy+///+oyyyssysso+++oshdddmmmmmmmmmmmmmmmmdso+/::--......-\n" <<
"mmmmmmmmmmmmmmmds+:--..`````                 ``..-/ymmds--+ydmmmmmds++oydmmmmmd/.`` ``--/shdho+osyhddmmmdddddhssyyhdhddmmmmmmmmmmmmmmdyo+//::--......-\n" <<
"mmmmmmmmmmmmmmmmh+/::--....``              ````.-/ymmds+sdmmmdmmmdo/::/oydmmmdms-````-/hmmmhyhhdmmmmmmmmmmmmmmmddddmdmmmmmmmmmmmmmmmmyo++//:------...-\n" <<
"mmmmmmmmmmmmmmmmhso+/::---.``         ````````.-:+hmdhhdmmmmmddhys:-..-/oydmmmmdo/--:/hmmmmmmmmmmddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdo+++/:----------.\n" <<
"mmmmmmmmmmmmmmmmmhso++/:--.``     ``````......--/+yddmmmmmdyyyss+:.```.-:+sdmmmmmdhhddmmmmmmmmmhhydmdhysooshdmmmmmmmmmmmmmmmmmmmmmmdyo+///::-:--------\n" <<
"mmmmmmmmmmmmmmmmmdhys+/::-..````````....----..--:/oyhhydsoo+++/-.``  ``.-:+ymmmmmmmmmmmmmmmmdmdddmds+++/:/+ooydmmmmmmmmmmmmmmmmmmmdyo++///:::::::-----\n" <<
"mmmmmmmmmmmmmmmmmmhyo+//:-..````..-://+++///:--..-:+o/--`.-..```      `..-:+hmmmmmmmmmmmmmmdmmmmdyo+ooo/+++oohmmmmmmmmmmmmmmmmmmmmyo++++/::::::::::---\n" <<
"mmmmmmmmmmmmmmmmmmdyo+/:--..`...:+sydddddhys+:.```.-//:-.`           `.---:/smmmmmmmmmmmmmmmmmdyyyssyyyysoshddmmmmmmmmmmmmmmmmmmmmyo++++//////////::::\n" <<
"mmmmmmmmmmmmmmmmmmmdyo+/:-..:+shdmmmmmmmmmmdy+:`   `.-:--.``        ``..-::+smmmmmmmmmmmmmmmmmdddddddmmmdhdmmmmmmmmmmmmmmmmmmmmmmmdyssooosyoo++++++//:\n" <<
"mmmmmmmmmmmmmmmmmmmmdys+//ohdddhyssshdmmmdysoo/-``  ``----..``````..-//::/+shmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddmmmdyyyssssooo\n" <<
"mmmmmmmmmmmmmmmmmmmmmmhsodmhs/:::/ydmddmmh+::///-.`` ``.-----//++ossssooosydmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdhhhhhddmmdddddd\n" <<
"mmmmmmmmmmmmmmmmmmmmmmmddmy+//+shdmmmhyho/:---:::-.``  `.--::::/o++osyhdmmmddhhmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddys++osyhdmmmmmmmdd\n" <<
"mmdmmmmmmmmmmmmmmmmmmmmmmdysyydmmmmmdhy//+:```.-::--.`  `.---..-:::::/oyhdhsosydmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdhhyhhdddmmmmmmmmdddd\n" <<
"mmdmmmmmmmmmmmmmmmmmmmmmmmmdmmmmmmmdho///-`  `.--:::-.`  ``.----+s---:/sdds+/oyhmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddd\n" <<
"ymmmmmmmmmmmmmmmmmmmmmmmmmmmmddddhyso+/-.`    `.:////:.`   ``-:ody-.-:+dho+//+shmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddd\n" <<
"/dmmmmmmmmmmmmmmmmmmmmmmmmmmds++/::--.``      `-oo/://-.`````-odd:.-:ohds/:://oydmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddddd\n" <<
"-+dmmmmmmmmmmmmmmmmmmmmmmmmmdo:-..```        `./ys/--//:----:sdmo.:ohmmyo+:://oydmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddddd\n" <<
"-:+dmmdmmmmmmmmmmmmmmmmmmmmmd+::-..``````  ``.:++:/ooosyyhyhdmmh-ohdddhsso////+sdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddddddd\n" <<
"--:+dmmmmmmmmmmmmmmmmmmmmmmmdo//::-...``````.-/+:.-+yhdddmmmmmmyyddyooosyo+/+//smmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddddddd\n" <<
"----/ydmmmmmmmmmmmmmmmmmmmmmdy+///:--......-:/++:--:::///+oydmmdh+/o+/ohho+////smmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddddddddd\n" <<
"-----:ohmmmmmmmmmmmmmmmmmmmmmdyoo++//::::::/+oo+::://::::ohdmmho//+:/oydy+/////ymmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddddddddddd\n" <<
"-----::+hmmmmmmmmmmmmmmmmmmmmmmhhyysoo+++++ooso+//ossssydmmdhhs+///+shdho/:::/+ymmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddddddddddhd\n" <<
"--::/osydmmmmmmmmmmmmmmmmmmmmmmmmddhhyysssssssooosdddddhhyss++++osyyddy+/:--::+hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddddddddddddddh\n" <<
":/+shddmmmmmmmmmmmmmmmmmmmmmmmmmmmmdhyyyyyyssooossyo//++oosyyhhhddddy+:-...--:ommmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddddddddddddddh\n" <<
"oyhddhhddmmmmmmmmmmmmmmmmmmmmmmmmmmmdhyssssooooooo++/////+oossssso+/-...`..-::ymmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddddddddddddddhh\n" <<
"hhhhdhdddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdhssssssssooo++++++++++///:-.......--::+dmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddddddddddddddddhhhh\n" <<
"ddhhddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddhhhhdhhhyysoo++++/::--......---:/+hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddddddddddddhdddhhhhhh\n" <<
"mdhddmmmmmmmmmmmmmmmmmmmmmdmmmmmmmmmmmmmmmmmmmmmmmmdddhysoo++/:---....--:/oydmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddddddddddddddhhhhhhh\n" <<
"mdddmmmmmmmmmmmmmmmmmmmmmmdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddhhysso++///++oyhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddddddddddddddddhhhhhhhhh\n" <<
"mmmmmmmmmmmmmmmmmmmmmmmmmmhmmdmddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdmddddddddddddddddddhhhhhhhhhhh\n" <<
"dmmmmmmmmmmmmmmmmmmmmmmmmmddhdddhhhhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddddddddddddddddhhhhhhhhhhhhh\n" <<
"mmmmmmmmmmmmmmmmmmmmmmmmmmmdysyssyhdhddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmds/hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddddddddddddddhdddhhhhhhhhhhhhhhh\n" <<
"mmmmmmmmmmmmmmmmmmmmmmmmmmmms+syoyshddhhmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmds/-:dmmmmmmmmmmmmmmmmmmmmmmmmhdmmmmddddddddddddddddddhhhhhhhhhhhhhhhhh\n" <<
"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddyhho:o/odmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmhys/:---/dmmmmmmmmmmmmmmmmmmmmmmd-/ddddddddddddddddhdddhhhhhhhhhhhhhhhhhhh\n" <<
"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmhyssohddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmo:--....-ommmmmmmmmmmmmmmmmmmmmmo``:dddddddddddddddhdhhhhhhhhhhhhhhhhhhhhh\n" <<
"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdo-......-hmmmmmmmmmmmmmmmmmmmmd-```/ddddddddddddddhhhhhhhhhhhhhhhhhhhhyyy\n" <<
"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdo:-..---/mmmmmmmmmmmmmmmmddddo`` ``+ddddddddddddhhhhhhhhhhhhhhhhhhhyyyyy\n" <<
"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmy+----..hmmmmmmmmmmmmmmddddh-`  ``.sdddddddddhhhhhhhhhhhhhhhhhhhyyyyyyy\n" <<
"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmds/-...ommmmmmmmmmmddddddd+.`` ``.-yddddddhhhhhhhhhhhhhhhhhhhyhyyyyyyy\n" <<
"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdyo:-.:mmmmmmmmdddddddddy-``   ``./hdhhhhhhhhhhhhhhhhhhhhhhyyyyyyyyyy\n" <<
"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmho-.dmmmmdddddddddddds.`    ``.-/hhhhhhhhhhhhhhhhhhhyyyhyyyyyyyyyy\n" <<
"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdohmmddddddddddddddo.`   ```..-:yhhhhhhhhhhhhhhhhhyyyyyyyyyyyyyy\n" <<
"mmmmmmdyhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddddddddddddddddddd+.`    ``..--/yhhhhhhhhhhhhyhyyyyyyyyyyyyyyyy\n";

    StaticText1->SetLabel(ss.str());
}





void FrameLove::OnKeyDown(wxKeyEvent& event)
{
}

void FrameLove::OnClose(wxCloseEvent& event)
{
    event.Skip(true);
}

void FrameLove::OnLeftDown(wxMouseEvent& event)
{
}

void FrameLove::OnChar(wxKeyEvent& event)
{
}

void FrameLove::OnPanel1KeyDown(wxKeyEvent& event)
{
    Close();
}
