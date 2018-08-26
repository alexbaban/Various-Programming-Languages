# Test

### `test.cfm`
```coldfusion
<cfscript>

	writeOutput(now());
	writeOutput('<hr />');
	
	// Simple Config
	config = new logbox.system.logging.config.LogBoxConfig();
	
	props = {
		filePath=expandPath( "/logging/tmp" ),
		autoExpand=false,
		fileMaxArchives=1,
		fileMaxSize=3000,
		async=true
	};
	
	config.appender(
		name="MyAsyncFile",
		class="logbox.system.logging.appenders.RollingFileAppender",
		properties=props
	);

	// Create logbox instance
	logBox = new logbox.system.logging.LogBox( config );
	
	writeDump(logBox.getCurrentAppenders());
	writeDump(logBox.getCurrentLoggers());
	// writeDump(logBox.getLogger());
	
	logEvent = new logbox.system.logging.LogEvent(
		message = 'More testing...', 
		severity = 3,
		extraInfo = '',
		category = 'SOME CATEGORY'
	);
	
	writeDump(logBox.getRootLogger().getAppender('MyAsyncFile').logMessage(logEvent));

</cfscript>

```
