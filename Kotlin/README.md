# Kotlin


## Hello World!

```kt
// hello.kt

fun main() {
  println("Hello Kotlin/Native!");
}
```
### How to compile this and make it `hello.exe` Windows command line executable

- from `https://github.com/JetBrains/kotlin-native/releases` download the `kotlin-native-windows-x.x.x.zip` binary distribution
- next download from `https://download.jetbrains.com/kotlin/native/libffi-3.2.1-mingw-w64-x86-64.zip`
- also download from `https://download.jetbrains.com/kotlin/native/msys2-mingw-w64-x86_64-gcc-7.3.0-clang-llvm-lld-6.0.1.zip`
- in a terminal `cd %HOMEPATH%` to get to the current's user home directory
- `mkdir .konan`
- unzip `kotlin-native-windows-x.x.x.zip` to `.konan`
- add `kotlin-native-windows-x.x.x\bin\` to PATH so that `kotlinc-native hello.kt -o hello` can be run from any place
- `cd %HOMEPATH%\.konan` and then `mkdir dependencies`
- unzip `libffi-3.2.1-mingw-w64-x86-64.zip` to `libffi-3.2.1-mingw-w64-x86-64` inside `.konan`
- unzip `msys2-mingw-w64-x86_64-gcc-7.3.0-clang-llvm-lld-6.0.1.zip` to `msys2-mingw-w64-x86_64-gcc-7.3.0-clang-llvm-lld-6.0.1` inside `.konan`
