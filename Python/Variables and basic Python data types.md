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

### Print a module's documentation

`help(math)`

## Converting integers and floats to string

`foo = str(85)`
`bar = str(-7.25)`

## Rules for making variable names

- the characters in a variable name must be letters, numbers or the underscore character
- spaces, dashes, punctuation, quotation marks are not allowed
- the first character cannot be a number, it must be a letter or underscore
- Python is case sensitive
- you cannot use Python keywords as variable names

## More about variables 
- assignments don't copy
- numbers and strings are immutable
- multiple assignment
```python

x, y, z = 1, 'two', 3.0
print(x, y, z) 

# prints "1 two 3.0"

```

- swapping variable values

```python

a, b = 5, 9
a, b = b, a
print(a, b)

# prints "9 5"

```









