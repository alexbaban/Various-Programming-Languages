# Sending Text Messages with Red and Twilio

Red is a next-gen programming language, strongly inspired by REBOL. It is both an imperative and functional programming language. 

Red is different from other languages. With Red we'll be able to cross-compile GUI applications into stand-alone executables about 1 MB in size. 
As Gregg Irwin (Red Community Manager) puts it, we will look like superheroes, but our sidekick is the one doing all the work.

## What are we going to build

_"A picture is worth a thousand words"_, our stand-alone GUI application will look something like this:

![Red GUI](Sending%20Text%20Messages%20with%20Red%20and%20Twilio_1.png?raw=true "Sending Text Messages with Red and Twilio")

<hr />

```red
Red [
    title: "Sending Text messages with Red and Twilio"
    needs: 'view                          
]

env-contents: read/lines %.env

twilio-account-sid: skip find first env-contents " = " 3
twilio-auth-token: skip find second env-contents " = " 3
twilio-phone-number: skip find third env-contents " = " 3

either [find fourth env-contents " = "] = none [
    default-to-number: ""  
][
    default-to-number: skip find fourth env-contents " = " 3    
]

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
    to-number: field 100x30 default-to-number

    text "Message:" 
    message-body: field 500x30 

    button "Send" [send-message]

    out: text 600x150 ""                          
]

```

