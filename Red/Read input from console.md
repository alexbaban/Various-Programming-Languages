# Read Input from Console

`read.red`

```red
Red [
    Title: "Read input from console"
]

#include %environment/console/CLI/input.red

print "Enter a name: "
name: input
print [name "is" length? name "characters long"]

```

This needs the lates build and needs to be compiled `-r`  
(https://github.com/red/red/wiki/%5BNOTES%5D-Compiling-with-console-functions)
