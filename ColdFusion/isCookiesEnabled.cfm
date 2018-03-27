# isCookiesEnabled()

A ColdFusion UDF. Returns a boolean to tell if browser cookies are enabled or not.

[isCookiesEnabled.cfm at cflib.org](http://www.cflib.org/udf/isCookiesEnabled)

``` javascript

/**
 * // returns true if browser cookies are enabled.
 * // requires session management enabled
 *
 * @return Returns a boolean. 
 * @author Alex Baban (alexbaban@gmail.com) 
 * @version 1, March 13, 2009 
 */
 
function isCookiesEnabled() {
    return IsBoolean(URLSessionFormat("True"));
}

```

``` coldfusion
<cfoutput>#isCookiesEnabled()#</cfoutput>
```
