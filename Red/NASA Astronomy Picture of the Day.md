# NASA’s Astronomy Picture of the Day

Downloading a file from the internet, currently, `read` can do this using the HTTP protocol...

## new file nasa.red

``` red 

Red [
    title: "NASA’s Astronomy Picture of the Day"
    author: "Alex Baban"
    version: 1.0.0
    purpose {
        using NASA’s Astronomy Picture of the Day API 
        (https://api.nasa.gov/api.html#apod) 
        as the JSON API that we are interacting with
    }
]

data: read https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY

print data 

```

## build
run `red -c -t MSDOS nasa.red`  
(this will create a native Windows command line executable `nasa.exe`)
