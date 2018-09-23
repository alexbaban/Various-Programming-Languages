# Use MAC address to generate a request key

## `gen-key.red`

```red

Red [
    Title: "GEN-KEY"
    Needs: 'View
]

ip-conf: ""
mac-address: ""

; Windows
call/wait/output "ipconfig/all" ip-conf
parse ip-conf [ thru "Physical Address. . . . . . . . . : " copy mac-address to newline ]

; macOS
; call/wait/output "ifconfig" ip-conf
; parse ip-conf [ thru "ether " copy mac-address to newline ] 

trim mac-address

gen-key: mold/flat checksum rejoin [ mac-address "foobarbaz" ] 'MD5
to string! gen-key

copy-key: does [    
    write-clipboard :gen-key
]

view [ 

    title "GEN-KEY"
    below 

    text "Key:"
    out: field 300x30 gen-key 
    copy-key-btn: button "Copy Key to Clipboard" [copy-key]
        
]

```
