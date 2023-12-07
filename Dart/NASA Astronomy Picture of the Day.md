# NASA Astronomy Picture of the Day

HTTP GET request to `https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY`
- it will return JSON
- (https://www.dartlang.org/tutorials/language/streams)

Open "Command Prompt" and
- `cd /apps/dart-hello && touch nasa.dart`
- `code .`

## Using async/await

```dart
// nasa.dart
// https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY

import 'dart:async';
import 'dart:io';
import 'dart:convert' show utf8;

Future main() async {
  HttpClient aHttpClient = new HttpClient();
  String aString = "https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY";

  HttpClientRequest request = await aHttpClient.getUrl(Uri.parse(aString));
  HttpClientResponse response = await request.close();
  await response.transform(utf8.decoder).forEach(print);
  
}

```

## Using then

``` dart
// nasa.dart
// https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY

import 'dart:async';
import 'dart:io';
import 'dart:convert' show utf8;

Future main() async {

HttpClient client = new HttpClient();
String aString = "https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY";

client.getUrl(Uri.parse(aString))
    .then((HttpClientRequest request) {
      // Optionally set up headers...
      // Optionally write to the request object...
      // Then call close.

      return request.close();
    })
    .then((HttpClientResponse response) {
      // Process the response.
      response.transform(utf8.decoder).listen((contents){
        print(contents);
      });
    })
    .catchError((error) {
      print(error);
    });

}

```
