# Red Programming Language
Red is a next-gen programming language, strongly inspired by REBOL   
(http://www.rebol.com/docs.html)

## Getting Started
(http://www.red-lang.org/p/getting-started.html)

- download `red-[version].exe` (for example `red-063.exe`) from the website (http://www.red-lang.org)
- copy `red-063.exe` to, let's say "C:\Portable\Red"
- go to "C:\Portable\Red" and create new file `red.bat` with code `@"%~dp0red-exe.exe" %*`
- add "C:\Portable\Red" to PATH
- from "Command Prompt" as administrator execute `red.bat` for the first time (it will take some time to build)

> Note: The need for `red.bat` is explained here (https://github.com/red/red/issues/543)


## Making a "Hello World" (command line native Windows executable)
Open "Command Prompt"

``` cmd
cd /apps
mkdir RedHello
cd RedHello
code .
```

Install the `Red` extension for Visual Studio Code   
(by Fullstack Technologies Limited)
(https://marketplace.visualstudio.com/items?itemName=red-auto.red)

### `hello.red` (new file)

``` rebol
Red [Title: "Simple hello world script"]
print "Hello World!"
```

Open "View" >> "Integrated Terminal"  
run `red -c -t MSDOS hello.red` (it will take a bit to compile)   
enjoy the result, a native Windows command line executable *`hello.exe`*
