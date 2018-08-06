# Variables and basic Python data types

## Basic Arithmetic Operators

- `addition: +`
- `substraction: -`
- `multiplication: *`
- `division: /`
- `integer division: //`
- `remainder: %`
- `exponentiation: **`

### Unlimited size

Python puts no limit on the size of an integer.
- at "Command Prompt" run `python`
- type `27 ** 1000`
- quit the "Python interactive command shell" with `quit()`
- exit "Command Prompt" with `exit`

### Floats overflow
`500.0 ** 1000`

### Limited precision
`1 - (2 / 3)`

### Complex numbers

In Python `1j` denotes the square root of -1
`1j`

## Other Math Functions

Python comes with modules of prewritten code, like the **math** module

```python
# math.py

import math
foo = math.sqrt(25)
print(foo) # prints 5.0

```

## Strings

```python
# strings.py

foo = "It's great..."
bar = 'Hello...'

print(foo)
print(bar)

print(bar + foo)

print(len(bar))

```

You can concatenate strings by adding them `+`  
There is a shortcut for concatenating the same string multiple times 
```python
print( 5 * foo)
# prints "It's great...It's great...It's great...It's great...It's great..."

```

## Listing Functions in a Module

```
# dir.py

import math

foo = dir(math)

print(foo)

```






