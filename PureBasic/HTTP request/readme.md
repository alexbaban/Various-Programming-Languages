# HTTP request
For example using NASA's picture of the day API   
(https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY)

## Make new file `nasapb.pb`

```
; make this a console program
OpenConsole()

PrintN("Executing request...")
PrintN("")

; InitNetwork() has to be called before using ReceiveHTTPMemory()
InitNetwork()

*Buffer = ReceiveHTTPMemory("https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY")

If *Buffer
  Size = MemorySize(*Buffer)
  PrintN("Response was: " + PeekS(*Buffer, Size, #PB_UTF8|#PB_ByteLength))
  FreeMemory(*Buffer)
  
Else
  Debug "Failed"
  
EndIf

If OpenConsole()
  PrintN("Press the Enter key to continue...")
  Input()
  
EndIf

; end program
End

```

## Build
Use the PureBasic IDE to compile to `nasapb.exe` Windows command line native exe
