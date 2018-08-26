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

   
   
