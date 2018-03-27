; CopyPath, utility program
; It takes as argument a file or a folder, puts the path of it into clipboard
; It can be a great time saver if included into "Send to" menu
; This program is written in PureBasic, go to http://purebasic.com/ for the compiler/IDE
; It works similar to "Copy as path" feature from Windows 7
; It works on Windows XP or later

; Author: Alex Baban
; Date: 2013-03-15
; Version: 1.0.1



; make this a console program
OpenConsole()

; get the first argument (full path to file or folder)
argPath$ = ProgramParameter(0)

; put the path in clipboard as text
SetClipboardText(argPath$)

; show the path in a console window to give user feedback
PrintN(argPath$)
Delay(1000)

; end program
End
