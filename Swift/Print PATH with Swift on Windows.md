# Print PATH with Swift on Windows

## printpath.elements
``` xml
<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<Project xmlns="http://schemas.microsoft.com/developer/msbuild/2003" DefaultTargets="Build" ToolsVersion="4.0">
  <PropertyGroup>
    <RootNamespace>com.alexbaban.printpath</RootNamespace>
    <ProjectGuid>{52785b01-da06-4825-90ce-acdeeea5d045}</ProjectGuid>
    <OutputType>Exe</OutputType>
    <AssemblyName>printpath</AssemblyName>
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
    <Reference Include="System">
      <Private>True</Private>
    </Reference>
    <Reference Include="Swift">
      <Private>True</Private>
    </Reference>
    <Reference Include="Elements">
      <Private>True</Private>
    </Reference>    
  </ItemGroup>
  <ItemGroup>
    <Compile Include="printpath.swift" />
  </ItemGroup>
  <Import Project="$(MSBuildExtensionsPath)\RemObjects Software\Elements\RemObjects.Elements.Echoes.targets" />
</Project>

```

## printpath.swift

``` swift
import RemObjects.Elements.RTL

var paths: String = Environment.get_EnvironmentVariable("PATH")
var sortedPaths = paths.Split(";").ToSortedList()

writeLn("------------------------------------")

for item in sortedPaths {
    writeLn("\(item)")
}

writeLn("------------------------------------")

```

## build 

build with `ebuild printpath.elements`  
The folder (.\bin\Release) will contain `printpath.exe`
(native command line Windows executable (depends on .NET runtime))
