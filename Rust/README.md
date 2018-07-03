# Rust

> Rust is a systems programming language that runs blazingly fast, prevents segfaults, and guarantees thread safety.

- Install Rust (https://www.rust-lang.org/en-US/)
- Check **PATH** for **C:\Users\John\.cargo\bin;** 
- Verify install (open new command prompt) `rustup --version`
- Update Rust `rustup update`
- Verify toolchain `rustup toolchain list`

## Cargo

> Cargo is the build system and package manager for Rust

- Cargo is installed by default when installing Rust
- Verify Cargo `cargo --version`

## "Hello, world!"
- `cd C:\apps`
- `cargo new rust-hello --bin` (**"--bin"** because we want to make an executable with Cargo)
- `cd rust-hello`
- `cargo build` (this creates an executable **"\target\debug\rust-hello.exe"**)
- Run with `.\target\debug\rust-hello.exe` (will print **"Hello, world!"**)  
(The program is portable but depends on **"Microsoft Visual C++ 2015 Redistributable"**)
