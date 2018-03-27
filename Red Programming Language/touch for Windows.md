# touch for Windows

> Note: this is `Alpha` version

``` red
Red [
    title: "touch for Windows"
    author: "Alex Baban"
    version: 0.1.1
    purpose {
        just like the Unix command-line program 'touch' 
        but for Windows (compiled as native)
    }
]

args: system/script/args

either not none? args [
    args-list: split to string! args " "
    ;print ["arguments: " args]
    foreach arg args-list [
        if ((length? arg) > 0) [
            write/append to file! to string! arg ""
        ]
    ]  
][
    ; // when no arguments
    print "touch (lite): missing file operand" 
    print "Try 'touch FILE...'"   
] 

```

## how to build
Read the "Getting Started" instructions in this folder.
