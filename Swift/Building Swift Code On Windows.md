# Building Swift Code On Windows

It is possible to write, build and run Swift code on Windows.

## Silver and Elements
 
Silver is a free implementation of Apple's Swift programming language. 
With Silver, you can use Swift to write code directly against the .NET, Java, Android and Cocoa APIs.  

Elements is a compiler and development tool chain for Oxygene, C# and Swift which targets the .NET runtime, Java/Android virtual machines. Elements is developed by RemObjects Software (https://en.wikipedia.org/wiki/RemObjects_Software).   
- Elements Docs (https://docs.elementscompiler.com)
 
## Getting Started

- The Elements compiler requires Windows 7 Service Pack 1 or later, and the .NET Framework 3.5 or later
  * Download and install the .NET Framework (the runtime, not the SDK)
  
- Download Elements (http://www.elementscompiler.com)
  * Elements is free to use without limitations with the Swift Language.

- Install Elements
  * "Core Compiler Support" checked by default
  * uncheck "Visual Studio Integration" (it's not required if building from the command prompt)
  * check "Sample Projects"

- Verify
  * Open Command Prompt and type `ebuild` to show version and help information
  * If `ebuild` is not recognized, add `C:\Program Files (x86)\RemObjects Software\Elements\Bin\` to the PATH environment variable
  * The "Sample Projects" can be found at `C:\Users\Public\Documents\RemObjects Samples\`
  
## The Text Editor

- Download and install Visual Studio Code (https://code.visualstudio.com/)
  * from Visual Studio Code's "Extensions" download and install the "Swift Language" extension by "Martin Kase"

## HelloWorld.exe (Windows command line executable)

- Create a folder `mkdir C:\Apps\SwiftHello\`
- `cd C:\Apps\SwiftHello\`
- `code .`   

- new file "HelloWorld.swift"
``` swift
let greeting = "Hello World!"
print(greeting)
print("Press the Enter key to continue...")
readLine() 
```
- new file "HelloWorld.elements"
``` xml
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Project xmlns="http://schemas.microsoft.com/developer/msbuild/2003" DefaultTargets="Build" ToolsVersion="4.0">
  <PropertyGroup>
    <RootNamespace>com.somedomain.helloswift</RootNamespace>
    <ProjectGuid>{e1313427-a10c-44ee-b2c0-217be2283494}</ProjectGuid>
    <OutputType>Exe</OutputType>
    <AssemblyName>HelloWorld</AssemblyName>
    <Configuration Condition="'$(Configuration)' == ''">Release</Configuration>
  </PropertyGroup>
  <PropertyGroup Condition=" '$(Configuration)' == 'Release' ">
    <Optimize>true</Optimize>
    <OutputPath>.\bin\Release</OutputPath>
    <GenerateDebugInfo>False</GenerateDebugInfo>
    <EnableAsserts>False</EnableAsserts>
    <TreatWarningsAsErrors>False</TreatWarningsAsErrors>
    <CaptureConsoleOutput>False</CaptureConsoleOutput>
    <WarnOnCaseMismatch>True</WarnOnCaseMismatch>
  </PropertyGroup>
  <ItemGroup>
    <Reference Include="mscorlib" />
    <Reference Include="Swift">
      <Private>True</Private>
    </Reference>
  </ItemGroup>
  <ItemGroup>
    <Compile Include="HelloWorld.swift" />
  </ItemGroup>
  <Import Project="$(MSBuildExtensionsPath)\RemObjects Software\Elements\RemObjects.Elements.Echoes.targets" />
</Project>
```
- `<RootNamespace>` (use reverse domain)
- `<ProjectGuid>` use an online GUID generator (like https://www.guidgenerator.com/)   

- build with command: `ebuild HelloWorld.elements`

`<OutputPath>` (.\bin\Release) will contain the resulting Windows executable "HelloWorld.exe" 
