; kets.exe (KETS = Kml Export To Shape)
; Takes as input a .kml file (geographic data in a mapping application), exports to clipboard the coordinates as shape
; This program is written in PureBasic, go to http://purebasic.com/ for the compiler/IDE

; Author: Alex Baban
; Date: 2015-12-20
; Version: 1.0.0
 

; make this a console program
OpenConsole()

; get the first argument (full path of .kml file)
argPath$ = ProgramParameter(0)

; print path
PrintN(argPath$);
PrintN("")      ;

; if the file could be read, we continue...
If ( ReadFile(0, argPath$) )    
  coordinatesStartPosition = 0
  coordinatesEndPosition = 0
  
  ; loop as long the 'end of file' isn't reached
  While ( Eof(0) = 0 )       
    
    ; read line by line
    thisLineText$ = ReadString(0)
    
    coordinatesStartPosition = FindString(thisLineText$, "<coordinates>") + Len("<coordinates>")
    coordinatesEndPosition = FindString(thisLineText$, "</coordinates>")
    coordinatesLen = coordinatesEndPosition - coordinatesStartPosition
    
    If ( coordinatesLen > 0 ) 
      
      shapeText$ = ""      
      
      ; get the text from inside <coordinates> tag
      coordinatesText$ = Mid(thisLineText$, coordinatesStartPosition, coordinatesLen)      
      
      pointCount = CountString(coordinatesText$, " ") + 1
      
      For k = 1 To (pointCount)
        
        ; get coordinates in the proper order, format the output
        shapeText$ = shapeText$ + "(" + StringField( StringField(coordinatesText$, k, " "), 2, "," ) + "," + StringField( StringField(coordinatesText$, k, " "), 1, "," ) + ")"
        
        If (k < pointCount)
          shapeText$ = shapeText$ + ","
        EndIf        
        
      Next  
      
      ; print output coordinates
      PrintN(shapeText$)
      
      ; put shape coordinates text in clipboard
      SetClipboardText(shapeText$)
      
    EndIf    
    
  Wend
  
  CloseFile(0)
  
Else
  PrintN("Couldn't open the file!")
  
EndIf

; keep window open for a little
Delay(1000)

; end program
End

; IDE Options = PureBasic 5.31 (Windows - x86)
; ExecutableFormat = Console
; CursorPosition = 75
; EnableUnicode
; Executable = kets.exe
; DisableDebugger
