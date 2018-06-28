# NASA’s Astronomy Picture of the Day

## Install the Red compiler  
(https://github.com/alexbaban/Various-Programming-Languages/blob/master/Red/Getting%20Started.md)

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


# NASA’s Astronomy Picture of the Day with image download

* fetch NASA's JSON
* parse JSON and extract URL for image
* extract name for image
* download image from URL and save to disk

## new file nasa.red

``` red

Red [
    title: "NASA’s Astronomy Picture of the Day"
    author: "Alex Baban"
    version: 2.0.0
    purpose {
        using NASA’s Astronomy Picture of the Day API 
        (https://api.nasa.gov/api.html#apod) 
        as the JSON API that we are interacting with
        - download image and save to disk
    }
]

print "Executing request..."

nasa-json: read https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY
print nasa-json 

; parse NASA's JSON to get the url for the picture so we can download it
image-url: copy to url! ""
parse nasa-json [thru "url^": ^"" copy data thru ".jpg" (append image-url data) to end]

print "Downloading..."

; download image and save to disk
image-name: last split image-url "/"
write/binary to file! image-name read/binary image-url

print ["Saved to:" image-name]

```

## build
run `red -c -t MSDOS nasa.red`  
(this will create a native Windows command line executable `nasa.exe`)
