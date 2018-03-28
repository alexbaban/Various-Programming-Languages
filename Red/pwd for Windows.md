# pwd for Windows

## pwd.red (new file)
``` red
Red [
    title: "pwd for Windows"
    author: "Alex Baban"
    version: 1.0.0
    purpose {
        just like the Unix command-line program 'pwd' 
        but for Windows (compiled as native)
    }
]

print [get-current-dir] 

```

## how to build
Read the "Getting Started" instructions in this ("/Various-Programming-Languages/Red/") folder.   
`red -c -t MSDOS pwd.red`
