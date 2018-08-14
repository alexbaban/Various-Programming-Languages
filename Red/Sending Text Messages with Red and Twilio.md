# Sending Text Messages with Red and Twilio

Red is a next-gen programming language, strongly inspired by REBOL. It is both an imperative and functional programming language. 

Red is different from other languages. With Red we'll be able to cross-compile GUI applications into stand-alone executables about 1 MB in size. 
As Gregg Irwin (Red Community Manager) puts it, we will look like superheroes, but our sidekick is the one doing all the work.

## What are we going to build

_"A picture is worth a thousand words"_, our stand-alone GUI application will look something like this:

![Red GUI](Sending%20Text%20Messages%20with%20Red%20and%20Twilio_1.png?raw=true "Sending Text Messages with Red and Twilio")

It contains an input field for the destination phone number, another input field for the body of the message and a "Send" button. Pretty simple. Let's build this! (Oh..., and let's do it in 50 lines of code or less, no Xcode, Visual Studio or things like that, Red has the "batteries included".)

## Setting Up for Development

To get started we need:
- A Twilio account [(sign up for a free Twilio account here)](https://www.twilio.com/try-twilio])
- A Twilio phone number [(buy a phone number)](https://www.twilio.com/console/phone-numbers/search)

Next, let's install the Red toolchain. It comes as a single one-megabyte executable file, and we'll download it from here: http://www.red-lang.org/p/download.html

The download is named red-[something], where [something] has to do with versioning, (on Windows, the file also has an .exe extension).

### Installing Red on macOS
- create a new folder named `red` on your Desktop
- move or copy the downloaded `red-[something]` to the `red` folder
- for convenience rename the file to just `red`
- in your Terminal, go to the `red` folder with `cd ~/Desktop/red/`
- do a `chmod +x red` to obtain executable rights
- now run `./red` command (when doing this for the first time the "Red console" will be built)
- after a bit of time the "Red console" will show up, and we can close it for now with `quit` + `Enter`


### Installing Red on Windows
- create a new folder named `red` on your Desktop
- move or copy the downloaded `red-[something].exe` in the `red` folder
- make a new file `red.bat` with the following content `@"%~dp0red-[something].exe" %*`, save
- in your "Command Prompt" go to the `red` folder with `cd c:\Users\[username]\Desktop\red\`
- now run `red.bat` command (when doing this for the first time the "Red console" will be built)
- after a bit of time the "Red console" will show up, and we can close it for now with `quit` + `Enter`

## The fun part, getting our hands dirty and actually write some Red code

In our `red` folder, we'll create a text file `twilio-sms.red` file with the code of our application.

### `twilio-sms.red`
```red
Red [
    title: "Sending Text messages with Red and Twilio"
    needs: 'view                          
]

twilio-account-sid: "ACe92063f2ef7820a132d7ff5a5ec2666f"
twilio-auth-token: "9d80bb08fb99cf0c2d04dc40c1c824df"
twilio-phone-number: "+19997775555"

api-url: to url! rejoin ["https://api.twilio.com/2010-04-01/Accounts/" twilio-account-sid "/Messages.json"]
auth-string: rejoin ["Basic " enbase/base rejoin [twilio-account-sid ":" twilio-auth-token] 64]

send-message: does [

    payload-data: rejoin ["From=" twilio-phone-number "&To=" to-number/text "&Body=" message-body/text]
    url: api-url

    response: write url compose/deep [
        post [
            Content-Type: "application/x-www-form-urlencoded"
            Authorization: (auth-string)
        ]
        (payload-data)
    ]

    out/text: response
]

view [ 

    title "Sending Text messages with Red and Twilio"
    below 

    text "To (phone number):" 
    to-number: field 100x30

    text "Message:" 
    message-body: field 500x30 

    button "Send" [send-message]

    out: text 600x150 ""                          
]

```

Let's examine the code.

`needs: 'view` tells the compiler that this is a GUI application 

The following lines of code, assign our Twilio credentials as well as our Twilio number to variables.

We then build the value for the `api-url:` variable by joining Twilio's API specific strings and the content of `twilio-account-sid:`, then casting the result to a `url!` data type.

The `auth-string:` is built by Base64 encoding of `twilio-account-sid ":" twilio-auth-token`.

Next, we define a function `send-message: does`, this function is executed when we press the "Send" button on the interface. The function contains code that makes a POST request to Twilio, sending the authentication values as well as values extracted from the "To (phone number):" and "Message:" fields. 

The code inside `view [...]` builds the interface and really is self-explanatory.

## The moment of truth, build and run
- in your Terminal, from inside the `red` folder run `./red -r -t macOS twilio-sms.red`
- if you're on Windows run `red.bat -r -t Windows twilio-sms.red`

On macOS a `twilio-sms.app` will be created, on Windows a `twilio-sms.exe` will be created. On macOS we might need to run `chmod +x twilio-sms.app` to make it executable.

Double-click on the executable to launch the application.

A nice thing about the Red compiler is that we can cross-compile. 

We can build the app for other operating systems if we change the argument of the `-t` (target) flag, like `./red -r -t Windows twilio-sms.red` to build for Windows on macOS and `red.bat -r -t macOS twilio-sms.red` to build for macOS on Windows.

So, there you have it, we just built a cross-platform, portable, no dependencies small in size (~1MB), GUI application that we can use to send messages via Twilio.



