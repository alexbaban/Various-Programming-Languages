# Dart
Dart is a general-purpose programming language originally developed by Google and later approved as a standard by Ecma (ECMA-408). It is used to build web, server, and mobile applications.
- (https://www.dartlang.org/tutorials/dart-vm/cmdline)

## Dart SDK Archive
Use this archive to download specific versions of the Dart SDK and the Dart API documentation.
- (https://www.dartlang.org/tools/sdk/archive)
- Extract to (C:\Portable\dart-sdk\)
- Add (C:\Portable\dart-sdk\bin\) to PATH
- Open "Command Prompt" and run `dart --version`

## Visual Studio Code Extension
- (https://marketplace.visualstudio.com/items?itemName=Dart-Code.dart-code)

## Dart Hello World
Open "Command Prompt" and

- `cd /apps && mkdir dart-hello`
- `cd dart-hello`
- `touch hello.dart && code .`

```dart
// hello.dart

void main() {
  print('Hello, World!');
}

```

- run `dart hello.dart`

## dart2native
- (https://dart.dev/tools/dart2native) 

Use the dart2native command to AOT (ahead-of-time) compile a Dart program to native x64 machine code. The dart2native command is supported on Windows, macOS, and Linux.

The default output of dart2native is a standalone executable. A standalone executable is native machine code that’s compiled from the specified Dart file and its dependencies, plus a small Dart runtime that handles type checking and garbage collection.

- run `dart2native hello.dart` or `dart2native hello.dart -o hello.exe`
