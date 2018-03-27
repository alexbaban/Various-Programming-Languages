; dt, utility program
; Puts the current date and time formatted as yyyymmdd_HHmm into clipboard
; This program is written in PureBasic, go to http://purebasic.com/ for the compiler/IDE

; Author: Alex Baban
; Date: 2015-05-07
; Version: 1.0.1



; make this a console program
OpenConsole()

; get a string representation of the current system date
dateTimeText$ = FormatDate("%yyyy%mm%dd_%hh%ii", Date())

; put the path in clipboard as text
SetClipboardText(dateTimeText$)

; short user feedback
PrintN(dateTimeText$)
Delay(1000)

; end program
End

; IDE Options = PureBasic 5.31 (Windows - x86)
; ExecutableFormat = Console
; CursorPosition = 25
; EnableUnicode
; EnableXP
; Executable = dt.exe
; DisableDebugger
