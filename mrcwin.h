
 /* -------------------------------------------------------------------------------------- *                                                                                     *
  *                                  mrcwin.h                                              *
  *                          Autor: Marco Aurélio Lima                                     *
  *                            Ver. 1.4   22-02-2020                                       *                                                           *
  * -------------------------------------------------------------------------------------- */

#ifndef MRCWIN_H_INCLUDED
#define MRCWIN_H_INCLUDED


//#define _WIN32_WINNT 0x0601
#include <windows.h>
#include <cwchar>
#include <vector>
#include <sstream>
#include <stdio.h>




/* -------------------------------------------------------------------------------------- *
 *    O arquivo Wincon.h que vem na instalação do compilador MinGW do CodeBlocks veio     *
 *  sem a definição da função SetCurrentConsoleFontEx( ) e a struct CONSOLE_FONT_INFOEX.  *
 *  por isso tive que declarar aqui mesmo para poder usar.                                *
 * -------------------------------------------------------------------------------------- */
/*
typedef struct _CONSOLE_FONT_INFOEX
{
    ULONG cbSize;
    DWORD nFont;
    COORD dwFontSize;
    UINT  FontFamily;
    UINT  FontWeight;
    WCHAR FaceName[LF_FACESIZE];
}CONSOLE_FONT_INFOEX, *PCONSOLE_FONT_INFOEX;

#ifdef __cplusplus
extern "C" {
#endif
BOOL WINAPI SetCurrentConsoleFontEx(HANDLE hConsoleOutput, BOOL bMaximumWindow, PCONSOLE_FONT_INFOEX
lpConsoleCurrentFontEx);
#ifdef __cplusplus
}
#endif
*/



namespace mrcwin{
    namespace virtkeyboard{
        void keyPress(int);
        void keySequence(std::string, int);

        /// Pressiona 1 Tecla por vez.
        /// O keycode recebe o valor do Virtual Key Code padrão da Microsoft
        void keyPress(int keyCode){
            INPUT input;
            ZeroMemory(&input,sizeof(input));

            input.ki.wVk = keyCode;
            input.type = INPUT_KEYBOARD;
            SendInput(1,&input,sizeof(input));

            input.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1,&input,sizeof(input));
        }

        /// Pressiona 2 Teclas por vez.
        /// O keycode recebe o valor do Virtual Key Code padrão da Microsoft
        void keyPress2bt(int keyCode1, int keyCode2){
            INPUT input1, input2;
            ZeroMemory(&input1,sizeof(input1));
            ZeroMemory(&input2,sizeof(input2));

            input1.ki.wVk = keyCode1;
            input1.type = INPUT_KEYBOARD;
            SendInput(1,&input1,sizeof(input1));

            input2.ki.wVk = keyCode2;
            input2.type = INPUT_KEYBOARD;
            SendInput(1,&input2,sizeof(input2));

            input2.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1,&input2,sizeof(input2));

            input1.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1,&input1,sizeof(input1));
        }

        /// Pressiona 3 Teclas por vez.
        /// O keycode recebe o valor do Virtual Key Code padrão da Microsoft
        void keyPress3bt(int keyCode1, int keyCode2, int keyCode3){
            INPUT input1, input2, input3;
            ZeroMemory(&input1,sizeof(input1));
            ZeroMemory(&input2,sizeof(input2));
            ZeroMemory(&input3,sizeof(input3));

            /* Press */
            input1.ki.wVk = keyCode1;
            input1.type = INPUT_KEYBOARD;
            SendInput(1,&input1,sizeof(input1));

            input2.ki.wVk = keyCode2;
            input2.type = INPUT_KEYBOARD;
            SendInput(1,&input2,sizeof(input2));

            input3.ki.wVk = keyCode3;
            input3.type = INPUT_KEYBOARD;
            SendInput(1,&input3,sizeof(input3));

            /* Releas */
            input3.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1,&input3,sizeof(input3));

            input2.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1,&input2,sizeof(input2));

            input1.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1,&input1,sizeof(input1));


        }


        /// Pressiona sequencia de Teclas.
        /// Usar letras maiúsculas nas teclas digitáveis( A, B, etc). Nas não digitáveis usar o padrao: "/nome_da_tecla". Ex.: "/enter" .
        void keySequence(std::string sequence, int delay = 50){
            std::vector<std::string> words;

            /* O final da sequencia sempre tem que ter um ESPACO*/
            if(sequence[sequence.size()-1] != ' '){
                sequence = sequence + " ";
            }

            /* Separando as palavras individualmente e guardando em um VECTOR*/
            std::stringstream ss;
            for(size_t i=0;i<sequence.size();i++){
                if(sequence[i] != ' '){
                    ss << sequence[i];
                } else {
                    //ss << sequence[i];
                    words.push_back(ss.str());
                    ss.str("");
                }

            }


            /* Percorrendo todas as palavras; as que tem uma barra "/" são botões especiais ex.: F1, Enter, Shift, etc. */
            for(size_t i=0;i<words.size();i++){
                if(words[i][0] == '/'){
                    /* Teclas não digitáveis por strings           */
                    /* O caractere / corresponde a tecla de espaço */
                    if(!words[i].compare("/"))         {keyPress(0x20);} else
                    if(!words[i].compare("/tab"))      {keyPress(0x09);} else
                    if(!words[i].compare("/caps"))     {keyPress(0x14);} else
                    if(!words[i].compare("/shift"))    {keyPress(0xA0);} else
                    if(!words[i].compare("/alt"))      {keyPress(0x12);} else
                    if(!words[i].compare("/control"))  {keyPress(0xA2);} else
                    if(!words[i].compare("/enter"))    {keyPress(0x0D);} else
                    if(!words[i].compare("/del"))      {keyPress(0x2E);} else
                    if(!words[i].compare("/backs"))    {keyPress(0x08);} else
                    if(!words[i].compare("/esc"))      {keyPress(0x1B);} else
                    if(!words[i].compare("/delete"))   {keyPress(0x2E);} else
                    if(!words[i].compare("/pageup"))   {keyPress(0x21);} else
                    if(!words[i].compare("/pagedown")) {keyPress(0x22);} else
                    if(!words[i].compare("/up"))       {keyPress(0x26);} else
                    if(!words[i].compare("/down"))     {keyPress(0x28);} else
                    if(!words[i].compare("/left"))     {keyPress(0x25);} else
                    if(!words[i].compare("/right"))    {keyPress(0x27);} else
                    if(!words[i].compare("/windows"))  {keyPress(0x5B);} else


                    if(!words[i].compare("/["))    {keyPress(0xDD);} else
                    if(!words[i].compare("/]"))  {keyPress(0xDC);} else
                    if(!words[i].compare("/´")){keyPress(0xDB);} else
                    if(!words[i].compare("/~")){keyPress(0xDE);} else

                    if(!words[i].compare("/!")){keyPress2bt(0x10 , 0x31);} else
                    if(!words[i].compare("/@")){keyPress2bt(0x10 , 0x32);} else
                    if(!words[i].compare("/#")){keyPress2bt(0x10 , 0x33);} else
                    if(!words[i].compare("/$")){keyPress2bt(0x10 , 0x34);} else
                    if(!words[i].compare("/%")){keyPress2bt(0x10 , 0x35);} else
                    if(!words[i].compare("/&")){keyPress2bt(0x10 , 0x37);} else
                    if(!words[i].compare("/(")){keyPress2bt(0x10 , 0x39);} else
                    if(!words[i].compare("/)")){keyPress2bt(0x10 , 0x30);} else
                    if(!words[i].compare("/_")){keyPress2bt(0x10 , 0xBD);} else
                    if(!words[i].compare("/:")){keyPress2bt(0x10 , 0xBF);} else
                    if(!words[i].compare("/{")){keyPress2bt(0xA0, 0xDD);} else
                    if(!words[i].compare("/}")){keyPress2bt(0xA0, 0xDC);} else

                    if(!words[i].compare("/\\")){keyPress(0xE2);} else
                    if(!words[i].compare("/|")){keyPress2bt(0xA0, 0xE2);} else

                    if(!words[i].compare("/`")){keyPress2bt(0xA0, 0xDB);} else
                    if(!words[i].compare("/^")){keyPress2bt(0xA0, 0xDE);} else

                    if(!words[i].compare("/<")){keyPress2bt(0xA0, 0xBC);} else
                    if(!words[i].compare("/>")){keyPress2bt(0xA0, 0xBE);} else

                    if(!words[i].compare("/aspas")) {keyPress2bt(0x10 , 0xC0)      ;} else  /* caractere aspas "" */
                    if(!words[i].compare("/?"))     {keyPress3bt(0x11 , 0x12, 0x57);} else
                    if(!words[i].compare("/°"))     {keyPress3bt(0x11 , 0x12, 0xC1);} else
                    if(!words[i].compare("/ª"))     {keyPress3bt(0x11 , 0x12, 0xDC);} else
                    if(!words[i].compare("/º"))     {keyPress3bt(0x11 , 0x12, 0xDD);} else
                    if(!words[i].compare("/§"))     {keyPress3bt(0x11 , 0x12, 0xBB);} else

                    if(!words[i].compare("/,")){keyPress(0xBC);} else
                    if(!words[i].compare("/.")){keyPress(0xBE);} else
                    if(!words[i].compare("/;")){keyPress(0xBF);} else
                    if(!words[i].compare("/=")){keyPress(0xBB);} else
                    if(!words[i].compare("/+")){keyPress(0x6B);} else
                    if(!words[i].compare("/-")){keyPress(0x6D);} else
                    if(!words[i].compare("/*")){keyPress(0x6A);} else
                    if(!words[i].compare("//")){keyPress(0x6F);} else
                    if(!words[i].compare("/'")){keyPress(0xC0);} else

                    /* F1  -  F12*/
                    if(!words[i].compare("/f1")){keyPress(0x70);}  else
                    if(!words[i].compare("/f2")){keyPress(0x71);}  else
                    if(!words[i].compare("/f3")){keyPress(0x72);}  else
                    if(!words[i].compare("/f4")){keyPress(0x73);}  else
                    if(!words[i].compare("/f5")){keyPress(0x74);}  else
                    if(!words[i].compare("/f6")){keyPress(0x75);}  else
                    if(!words[i].compare("/f7")){keyPress(0x76);}  else
                    if(!words[i].compare("/f8")){keyPress(0x77);}  else
                    if(!words[i].compare("/f9")){keyPress(0x78);}  else
                    if(!words[i].compare("/f10")){keyPress(0x79);} else
                    if(!words[i].compare("/f11")){keyPress(0x7A);} else
                    if(!words[i].compare("/f12")){keyPress(0x7B);} else

                     /* Multimídia */
                    if(!words[i].compare("/play"))  {keyPress(0xB3);} else
                    if(!words[i].compare("/pause")) {keyPress(0xB3);} else
                    if(!words[i].compare("/next"))  {keyPress(0xB0);} else
                    if(!words[i].compare("/prev"))  {keyPress(0xB1);} else
                    if(!words[i].compare("/stop"))  {keyPress(0xB2);} else

                    if(!words[i].compare("/mute"))  {keyPress(0xAD);} else
                    if(!words[i].compare("/vol+"))  {keyPress(0xAF);} else
                    if(!words[i].compare("/vol-"))  {keyPress(0xAE);} else
                    if(!words[i].compare("/sleep")) {keyPress(0x5F);}

                    if(GetAsyncKeyState(VK_F9)){
                        wxMessageBox( _("    A digitação foi cancelada."), wxT("    "), wxICON_EXCLAMATION);
                        return;
                    }

                    wxMilliSleep(delay);
                     //Sleep(delay);

                } else {
                    /* Teclas digitaveis por strings */
                    for(size_t j=0;j<words[i].size();j++){
                        if(words[i][j] == 'Ç'){
                            keyPress(0xBA);
                            wxMilliSleep(delay);
                            //Sleep(delay);
                        } else {
                            keyPress(words[i][j]);
                            wxMilliSleep(delay);
                            //Sleep(delay);
                        }
                    }
                }
            }
        }


        /// converte um caractere em uma string correspondente na linguagem do mrcwin
        /// EX.: se o caractere for 'Á', a seuqnecia é: caps > acento circunflexo > A > caps
        std::string convertChar(char c){
            if(c == ' '){ return " / "; } else
            if(c == '\t'){ return " /tab "; }  else
            if(c == '\n'){ return " /enter "; } else
            if(c == '!'){ return " /! "; } else
            if(c == '@'){ return " /@ "; } else
            if(c == '#'){ return " /# "; } else
            if(c == '$'){ return " /$ "; } else
            if(c == '%'){ return " /% "; } else
            if(c == '&'){ return " /& "; } else
            if(c == '('){ return " /( "; } else
            if(c == ')'){ return " /) "; } else
            if(c == '_'){ return " /_ "; } else
            if(c == ':'){ return " /: "; } else


            if(c == '\\'){ return " /\\ "; } else
            if(c == '|'){ return " /| "; } else

            if(c == '\"'){ return " /aspas "; } else
            if(c == '\''){ return " /' "; } else

            if(c == '?'){ return " /? "; } else
            if(c == ','){ return " /, "; } else
            if(c == '.'){ return " /. "; } else
            if(c == ';'){ return " /; "; } else
            if(c == '='){ return " /= "; } else
            if(c == '+'){ return " /+ "; } else
            if(c == '-'){ return " /- "; } else
            if(c == '*'){ return " /* "; } else
            if(c == '/'){ return " // "; }

            if(c == '<'){ return " /< "; } else
            if(c == '>'){ return " /> "; } else

            if(c == '°'){ return " /° "; } else
            if(c == 'ª'){ return " /ª "; } else
            if(c == 'º'){ return " /º "; } else
            if(c == '§'){ return " /§ "; } else
            if(c == '['){ return " /[ "; } else
            if(c == ']'){ return " /] "; } else
            if(c == '{'){ return " /{ "; } else
            if(c == '}'){ return " /} "; } else

            if(c == 'ç'){ return " Ç "; } else
            if(c == 'Ç'){ return " /caps Ç /caps "; } else

            if(c == 'á'){ return " /´ A "; } else
            if(c == 'é'){ return " /´ E "; } else
            if(c == 'í'){ return " /´ I "; } else
            if(c == 'ó'){ return " /´ O "; } else
            if(c == 'ú'){ return " /´ U "; } else
            if(c == 'Á'){ return " /caps /´ A /caps ";} else
            if(c == 'É'){ return " /caps /´ E /caps ";} else
            if(c == 'Í'){ return " /caps /´ I /caps ";} else
            if(c == 'Ó'){ return " /caps /´ O /caps ";} else
            if(c == 'Ú'){ return " /caps /´ U /caps ";} else

            if(c == 'à'){ return " /` A "; } else
            if(c == 'è'){ return " /` E "; } else
            if(c == 'ì'){ return " /` I "; } else
            if(c == 'ò'){ return " /` O "; } else
            if(c == 'ù'){ return " /` U "; } else
            if(c == 'À'){ return " /caps /` A /caps ";} else
            if(c == 'È'){ return " /caps /` E /caps ";} else
            if(c == 'Ì'){ return " /caps /` I /caps ";} else
            if(c == 'Ò'){ return " /caps /` O /caps ";} else
            if(c == 'Ù'){ return " /caps /` U /caps ";} else

            if(c == 'â'){ return " /^ A "; } else
            if(c == 'ê'){ return " /^ E "; } else
            if(c == 'î'){ return " /^ I "; } else
            if(c == 'ô'){ return " /^ O "; } else
            if(c == 'û'){ return " /^ U "; } else
            if(c == 'Â'){ return " /caps /^ A /caps ";} else
            if(c == 'Ê'){ return " /caps /^ E /caps ";} else
            if(c == 'Î'){ return " /caps /^ I /caps ";} else
            if(c == 'Ô'){ return " /caps /^ O /caps ";} else
            if(c == 'Û'){ return " /caps /^ U /caps ";} else

            if(c == 'ã'){ return " /~ A "; } else
            if(c == 'õ'){ return " /~ O "; } else
            if(c == 'Ã'){ return " /caps /~ A /caps ";} else
            if(c == 'Õ'){ return " /caps /~ O /caps ";}

            /// SE CHEGOU AQUI, ELE TEM QUE SER ALFANUMERICO, PQ OS SIMBOLOS
            /// POSSIVEIS JÁ FORAMCHECADOS. SE NÃO FOR ALFANUMERICO, VAI RETORNAR.
            /// fiz essa alteração depois que ele teve um compotamento estranho depois
            /// de digitado. acho que pode resolver - 30-10-2020
            if(!isalnum(c)){
                return "";
            }

            std::stringstream ss;
            if(isupper(c) != 0){
                ss << " /caps " << c << " /caps ";
            } else {
                ss << (char)toupper(c);
            }

            return ss.str();
        }


        /// converte um texto de liguagem natural em um texto na linguagem do mrcwin
        std::string convertText(std::string text){
            std::stringstream ss;
            for(unsigned i=0;i<text.size();i++){
                ss << convertChar(text[i]);
            }
            return ss.str();
        }


        /// Digita um texto
        void typeText(std::string text = "Este é o teste de digitação padrão.", int delay=50){
            keySequence(convertText(text), delay);
        }




    } /* Fim do namespace virtkeyboard*/




    namespace virtmouse{
        void PressRight();
        void ReleaseRight();
        void PressLeft();
        void ReleaseLeft();

        /// Pressiona o botao DIREITO do mouse
        void PressRight(){
            INPUT input;
            ZeroMemory(&input,sizeof(input));
            input.type = INPUT_MOUSE;

            input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
            SendInput(1,&input,sizeof(INPUT));

            ZeroMemory(&input,sizeof(INPUT));
        }

        /// Solta o botao DIREITO do mouse
        void ReleaseRight(){
            INPUT input;
            ZeroMemory(&input,sizeof(input));
            input.type = INPUT_MOUSE;

            input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
            SendInput(1,&input,sizeof(INPUT));

            ZeroMemory(&input,sizeof(INPUT));
        }

        /// Pressiona o botao ESQUERDO do mouse
        void PressLeft(){
            INPUT input;
            ZeroMemory(&input,sizeof(input));
            input.type = INPUT_MOUSE;

            input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            SendInput(1,&input,sizeof(INPUT));

            ZeroMemory(&input,sizeof(INPUT));
        }

        /// Solta o botao ESQUERDO do mouse
        void ReleaseLeft(){
            INPUT input;
            ZeroMemory(&input,sizeof(input));
            input.type = INPUT_MOUSE;

            input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            SendInput(1,&input,sizeof(INPUT));

            ZeroMemory(&input,sizeof(INPUT));
        }

    } /* Fim do namespace virtkeyboard*/



    namespace prompt{
        enum{
            COLOR_BLACK,
            COLOR_BLUE,
            COLOR_GREEN,
            COLOR_BLUE_L2,
            COLOR_RED,
            COLOR_PURPLE,
            COLOR_YELLOW,
            COLOR_GRIZ_L1,
            COLOR_GRIZ,
            COLOR_BLUE_L1,
            COLOR_GREEN_L1,
            COLOR_BLUE_L3,
            COLOR_RED_L1,
            COLOR_PURPLE_L1,
            COLOR_YELLOW_L1,
            COLOR_WHITE
        };

        /// Muda a quantidade de caracteres maxima permitido no eixo X ( linha ).
        void changeBufferX(int bufferSize){
            HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);

            CONSOLE_SCREEN_BUFFER_INFO scrBuffer;
            GetConsoleScreenBufferInfo(handler, &scrBuffer);

            scrBuffer.dwSize.X = bufferSize;

            SetConsoleScreenBufferSize(handler, scrBuffer.dwSize);

        }

        /// Muda a quantidade de colunas maxima permitido no eixo Y ( coluna ).
        void changeBufferY(int bufferSize){
            HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);

            CONSOLE_SCREEN_BUFFER_INFO scrBuffer;
            GetConsoleScreenBufferInfo(handler, &scrBuffer);

            scrBuffer.dwSize.Y = bufferSize;

            SetConsoleScreenBufferSize(handler, scrBuffer.dwSize);

        }

        /// Muda a quantidade de caracteres e colunas maxima permitido respectivamente.
        void changeBufferXY(int bufferSizeX, int bufferSizeY){
            HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);

            CONSOLE_SCREEN_BUFFER_INFO scrBuffer;
            GetConsoleScreenBufferInfo(handler, &scrBuffer);

            scrBuffer.dwSize.X = bufferSizeX;
            scrBuffer.dwSize.Y = bufferSizeY;

            SetConsoleScreenBufferSize(handler, scrBuffer.dwSize);

        }

        /// Muda o estilo do console para FULLSCREEN
        void changeToFullScreenMode(){
            HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleDisplayMode(handler, CONSOLE_FULLSCREEN_MODE,NULL);
        }


        /// Muda o tamanho da jenela de Console e centraliza no monitor. Tamanho em PIXELS.
        void changeSize(int sizeX, int sizeY){

            int scrSizeX = GetSystemMetrics(SM_CXMAXIMIZED);
            int scrSizeY = GetSystemMetrics(SM_CYMAXIMIZED);

            int posX = (scrSizeX - sizeX)/2;
            int posY = (scrSizeY - sizeY)/2;

            HWND hd = GetConsoleWindow();

            SetWindowPos(hd, HWND_TOP, posX, posY, sizeX, sizeY, SWP_NOZORDER);
        }

        /// Muda a cor das letras mostradas na janela de Console. Use as constantes (ex.: mrcwin::prompt::COLOR_RED) definidas ou tipos inteiros.
        /// As cores mudarão sempre que essa função for chamada. Isso significa que é possivel colorir separadamente cada letra.
        void changeFontColor(int code){

            HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handler, code);

        }

        /// Muda o tamanho da fonte da janela de Console.
        /// OBS.: Se for mudar a fonte e o tamanho da janela ao mesmo tempo, mude o tamanho da fonte primeiro.
        void changeFontSize(int size, bool bold = false){
            CONSOLE_FONT_INFOEX fontInfo;
            fontInfo.cbSize = sizeof(fontInfo);
            fontInfo.nFont = 0;
            fontInfo.dwFontSize.X = 0;
            fontInfo.dwFontSize.Y = size;
            fontInfo.FontFamily = FF_DONTCARE;
            wcscpy(fontInfo.FaceName , L"Consolas");

            if(bold){ fontInfo.FontWeight = FW_BOLD; }
            else    { fontInfo.FontWeight = FW_NORMAL;}


            HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);

            SetCurrentConsoleFontEx(handler, false, &fontInfo);
        }

    } /* Fim namespace prompt */





} /* Fim namespace mrcwin */





#endif // MRCWIN_H_INCLUDED
