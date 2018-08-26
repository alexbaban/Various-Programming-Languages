# Web Services

To build a web service in ColdFusion, all we need to do is to write a ColdFusion component (CFC).

We can create or reuse a prebuilt CFC with the operations we want to expose as functions and make the CFC accessible to remote calls by specifying `access="remote"`. The CFC location then becomes the endpoint for the web service, and its remote functions become operations that can be invoked on this web service.

## Creating a Web Service
### `hello.cfc`
```coldfusion
<cfcomponent>
   <cffunction name="helloWorld" returnType="string" access="remote">
      <cfreturn "Hello World!">
   </cffunction>
</cfcomponent>

```

To quickly verify that this web service works, open `http://127.0.0.1:58711/hello.cfc?wsdl` in a browser. It should output the generated WSDL.

## Consuming a Web Service

There are several ways to invoke any web service in ColdFusion.

### Calling a Web Service with `<cfinvoke>`

```coldfusion
<cfset wsURL = "http://127.0.0.1:58711/hello.cfc?wsdl" />

<cfinvoke
	webservice = "#wsURL#"
	method = "helloWorld"
	returnVariable = "result" 
/>

<cfoutput> 
	<h1>#result#</h1>
</cfoutput>

```

### Calling a Web Service with `<cfobject>`

```coldfusion
<cfset wsURL = "http://127.0.0.1:58711/hello.cfc?wsdl">

<cfobject
	name = "ws"
	webservice= "#wsURL#"
	type = "webservice" 
/>

<cfset result = ws.helloWorld() />

<h1><cfoutput>#result#</cfoutput></h1>

```

### Calling a Web Service with CreateObject

When writing CFCs in script syntax, we can use the `createObject()` method to invoke a web service. It is the script equivalent of the `<cfobject>`

```coldfusion
<cfscript>
	wsURL = "http://127.0.0.1:58711/hello.cfc?wsdl";
	ws = createObject("webservice", wsURL);
	result = ws.helloWorld();
	writeoutput("<h1>" & result & "</h1>");
</cfscript>

```

### Refreshing Stubs

ColdFusion optimizes the creation of a web service operation significantly. ColdFusion makes a call to get the WSDL and generates the required stubs and artifacts only for the first call to the web service, using `<cfinvoke>` or `<cfobject>`.

This optimization creates a challenge in a development environment in which CFCs are being constantly modified. ColdFusion does not implicitly refresh the stubs for changed WSDL. 

The clients themselves have to refresh these stubs every time the WSDL changes. This operation can be accomplished by setting the `refreshWSDL` attribute as `true` with `<cfinvoke>` or `<cfobject>`. 

Although in a production environment `refreshWSDL` should be `false`, this is its default value, too.

```coldfusion
<cfset wsURL = "http://127.0.0.1:58711/hello.cfc?wsdl">

<cfobject
	name = "ws"
	webservice= "#wsURL#"
	type = "webservice"
	refreshWSDL = "true" 
/>

<cfset result = ws.helloWorld() />

<h1><cfoutput>#result#</cfoutput></h1>

```

### Passing Arguments

**Passing arguments with cfinvokeparam**
```coldfusion
<cfset wsURL = "http://127.0.0.1:58711/complex.cfc?wsdl" />

<cfset varStruct = {key1:"value 1", key2:"value 2"} />

<cfinvoke 
    webservice = "#wsURL#"
    method = "echoStruct"
    returnVariable = "result">
	
   <cfinvokeargument name="argStruct" value="#varStruct#" />
   
</cfinvoke>

<cfdump var="#result#" />

```

**Passing arguments inline as key value pair**
```coldfusion
<cfset varQuery = queryNew( "column1, column2, column3" ) />
<cfset queryAddRow( varQuery, ["row 1", "row 2", "row 3"] ) />

<cfinvoke 
    webservice = "#wsURL#"
    method = "echoQuery"
    argQuery = "#varQuery#"
    returnVariable = "result">
/>

<cfdump var="#result#" />

```
   
**Passing arguments as argument collection**
```coldfusion
<cfinvoke 
    webservice = "#wsURL#"
    method = "echoAny"
    argumentCollection = "#{ argAny: 'passing a string' }#"
    returnVariable = "result"
/>

<cfdump var="#result#" />

```

### Working with multiple arguments

When our function has more than one argument, we may want to make a few arguments required and the rest optional. However, the `<cffunction>` attribute `required` is ignored when a CFC is called as a web service. 

For a web service, all arguments are required. ColdFusion doesn’t support method overloading, so in in cases in which we want to pass only a few arguments, we need to use either of two approaches:

- We can make the function private and define different public methods for all parameter combinations. These methods will internally invoke this private function within the CFC, which performs the actual processing and also honors the defaults.

- Use a special value for arguments that we don’t want to pass: for example, `NULL`. Then within the function body, we can check IsNull() and place default values instead. If we use `<cfinvoke>`, then we can set the `<cfinvokeargument>` tag’s attribute `omit` as `true`. If we are using a proxy object created with `<cfobject>` or the `createObject()` method, we can simply pass `NULL`.

### Create NULL in ColdFusion
To create NULL in ColdFusion, we can either use `javaCast( "null", 0 )` or call a function that returns nothing, for example, `function null() {}`.

