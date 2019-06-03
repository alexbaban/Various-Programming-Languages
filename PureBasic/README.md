# PureBasic

Programs written in the PureBasic programming language.   
PureBasic website: (http://www.purebasic.com/)

## Hello World

Download and unzip to some "temp" folder then install to `C:\Program Files\PureBasic`
Launch PureBasic

```lisp

; Description: Hello World in PureBasic
; Author: Alex Baban

; make this a console program
OpenConsole()

; assign string to variable
foo$ = "Hello World!"

; show output
PrintN(foo$)

; pause for one second
Delay(1000)

; end program
End

```

Click "File" > "Save As..." then save (source code) to `C:\apps\purebasic-hello\hello.pb`  
Click "Compiler" > "Compile/Run" to test  
Click "Compiler" > "Create Executable..." then save (executable) to `hello.exe`  
Run `C:\apps\purebasic-hello\hello.exe`

