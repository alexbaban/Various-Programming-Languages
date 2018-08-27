# Utils

### `getEnvironment()`
```coldfusion
<cfscript>

	function getEnvironment() {
		var system = createObject( "java", "java.lang.System" );
		// var environment = system.getenv();
		var coldfusionEnvironment = system.getenv( javaCast( "string", "COLDFUSION_ENVIRONMENT" ) );
		return isDefined( 'coldfusionEnvironment' ) ? coldfusionEnvironment : "";
	}

</cfscript>

```
