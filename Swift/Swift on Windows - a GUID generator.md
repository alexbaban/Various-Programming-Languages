# Swift on Windows - a GUID generator

A universally unique identifier (UUID) is a 128-bit number used to identify information in computer systems. The term globally unique identifier (GUID) is also used.

## guid.exe 
A native Windows command line executable built with Swift which can be used to generate a GUID   
  
Will make use of the **Guid** class of the **Elements RTL** library (https://docs.elementscompiler.com/API/ElementsRTL/Classes/Guid/)

`cd C:\Apps\`  
`mkdir SwiftGUID`  
`cd SwiftGUID`  
`code .`  

### guid.elements (new file)
``` xml
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Project xmlns="http://schemas.microsoft.com/developer/msbuild/2003" DefaultTargets="Build" ToolsVersion="4.0">
  <PropertyGroup>
    <RootNamespace>com.alexbaban.swiftguid</RootNamespace>
    <ProjectGuid>{81d53a1b-aa02-4b4b-b794-602f0f4836b8}</ProjectGuid>
    <OutputType>Exe</OutputType>
    <AssemblyName>guid</AssemblyName>
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
    <Reference Include="Elements">
      <Private>True</Private>
    </Reference>    
  </ItemGroup>
  <ItemGroup>
    <Compile Include="guid.swift" />
  </ItemGroup>
  <Import Project="$(MSBuildExtensionsPath)\RemObjects Software\Elements\RemObjects.Elements.Echoes.targets" />
</Project>
```

### guid.swift (new file)
``` swift
import RemObjects.Elements.RTL

 // using the Guid class of the "Elements RTL" library 
let theGUID: Guid = Guid.NewGuid()

let theGUIDString: String = theGUID.ToString().ToLower()
writeLn(theGUIDString)

writeLn("Press the Enter key to continue ...")
readLine()
```

## Build
`ebuild guid.elements`    
  
The folder (.\bin\Release) will contain ***guid.exe***  
(native command line Windows executable (depends on .NET runtime))
