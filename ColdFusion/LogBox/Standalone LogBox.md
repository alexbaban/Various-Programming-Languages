# Standalone LogBox

## Installation
Install LogBox (https://logbox.ortusbooks.com/getting-started/installation)

## Application Structure
```
\box-log
    logbox\
    Application.cfc
    index.cfm
    aLogBoxConfig.cfc

```

### `Application.cfc`
```coldfusion
<cfcomponent>

	<cfset this.name = "MyLogBoxApp" />
	<cfset this.mappings['/logbox'] = expandPath('logbox') />

	<cffunction name = "onApplicationStart" returnType = "boolean" output = "false" >
		<cfscript>
			var config = createObject("component", "logbox.system.logging.config.LogBoxConfig")
				.init(CFCConfigPath = "aLogBoxConfig");
				
			application.logBox = createObject("component", "logbox.system.logging.LogBox")
				.init(config);
			
			return true;
		</cfscript>
	
	</cffunction>

	<cffunction name = "onRequestStart" returnType = "boolean" output = "true" >
	
		<cfargument name = "targetPage" type = "string" required = "true" />
		
		<cfif isDefined("url.reinit") and isBoolean(url.reinit) and url.reinit >
			<cfset onApplicationStart() />
			
		</cfif>
		
		<cfreturn true />
	
	</cffunction>
	
</cfcomponent>

```

### `aLogBoxConfig.cfc`
```coldfusion
<cfcomponent>

	<!--- // name of method needs to be "configure" --->
	<cffunction name = "configure">
	
		<cfscript>
		
			logBox = {
				appenders = {
					aTracerAppender = {
						class = "logbox.system.logging.appenders.tracerAppender"
					}
				},
				root = {
					levelMin = "FATAL",
					levelMax = "DEBUG",
					appenders = "*"				
				}			
			
			};
		
		</cfscript>

	</cffunction>

</cfcomponent>

```

### `index.cfm`
```coldfusion
<cfset application.logBox.getRootLogger().info("The index page has started to load!") />

<h1>This is the index page</h1>

<cfset application.logBox.getRootLogger().info("The index page has finished loading!") />

```
