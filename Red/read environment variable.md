# Read system environment variable

`read-env.red`

```red
Red [
    Title: "Read environment variables with Red lang."
]

java-home: get-env "JAVA_HOME"

either java-home = none [
    print "JAVA_HOME is not set!" 
][
    print ["JAVA_HOME:" java-home] 
]

```
