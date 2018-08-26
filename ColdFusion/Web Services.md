# Web Services

To build a web service in ColdFusion, all we need to do is to write a ColdFusion component (CFC).

We can create or reuse a prebuilt CFC with the operations we want to expose as functions and make the CFC accessible to remote calls by specifying `access="remote"`. The CFC location then becomes the endpoint for the web service, and its remote functions become operations that can be invoked on this web service.

### `hello.cfc`
```coldfusion
<cfcomponent>
   <cffunction name="helloWorld" returnType="string" access="remote">
      <cfreturn "Hello World!">
   </cffunction>
</cfcomponent>

```

