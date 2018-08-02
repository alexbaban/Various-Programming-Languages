# How to Make HTTP Requests in Swift (Windows)

Making HTTP requests is core functionality for modern languages.  
We’ll be using NASA’s Astronomy Picture of the Day API (https://api.nasa.gov/api.html#apod) as the JSON API that we are interacting with.

## Getting Set up w/ Silver on Windows
(https://github.com/alexbaban/Swift/blob/master/Building%20Swift%20Code%20On%20Windows.md)

## new file `nasa.elements`

``` xml
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Project xmlns="http://schemas.microsoft.com/developer/msbuild/2003" DefaultTargets="Build" ToolsVersion="4.0">
  <PropertyGroup>
    <RootNamespace>com.alexbaban.swiftnasa</RootNamespace>
    <ProjectGuid>{7beebae2-346b-4731-b09a-576afb5a4d82}</ProjectGuid>
    <OutputType>Exe</OutputType>
    <AssemblyName>nasa</AssemblyName>
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
    <Compile Include="nasa.swift" />
  </ItemGroup>
  <Import Project="$(MSBuildExtensionsPath)\RemObjects Software\Elements\RemObjects.Elements.Echoes.targets" />
</Project>

```

## new file `nasa.swift`

``` swift
import RemObjects.Elements.RTL

writeLn("Executing request...\n")

let aUrl = Url.TryUrlWithString("https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY")
let aHttpRequest = HttpRequest(aUrl)

Http.ExecuteRequest( aHttpRequest, { response in
  
  if response.Success {
    response.GetContentAsString(nil) { content in
      if content.Success {
        writeLn("Response was: "+content.Content)
        writeLn("Press the Enter key to continue ...")
      }
    }
  }

} )

let _x = readLine()

```

## build 

run `ebuild nasa.elements`

The folder (.\bin\Release) will contain ***nasa.exe***  
(native command line Windows executable (depends on .NET runtime))

## result

![result](How%20to%20Make%20HTTP%20Requests%20in%20Swift.PNG?raw=true "How to Make HTTP Requests in Swift (Windows)")
