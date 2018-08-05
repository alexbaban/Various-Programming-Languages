# Python

Python is an interpreted high-level programming language for general-purpose programming.
- (https://en.wikipedia.org/wiki/Python_(programming_language))

## Install Python

(https://www.python.org/)
- Go to "Downloads"
- Download and run the installer as administrator (select "Customize installation")
- Select "Add Python ... to PATH"
- Select the option to install PIP
- Install to "C:\Python37"

### Verify 

- at "Command Prompt" run `python --version`
- also run `pip --version`

To upgrade PIP, at administrator "Command Prompt" run `python -m pip install --upgrade pip`

## Third party libs
> Python usually stores its library (and thereby your site-packages folder) in the installation directory. So, if you had installed Python to C:\Python\, the default library would reside in C:\Python\Lib\ and third-party modules should be stored in C:\Python\Lib\site-packages.

## Python extension for Visual Studio Code

A Visual Studio Code extension with rich support for the Python language (2.7, >=3.4), including features such as linting, debugging, IntelliSense, code navigation, code formatting, refactoring, unit tests, snippets, and more!
- (https://marketplace.visualstudio.com/items?itemName=ms-python.python)

## Flask (web framework)

Flask is a micro web framework written in Python.
- Open "Command Prompt" as administrator then run `pip install Flask`

The following code shows a simple web application that prints "Hello World!"  

```python
# // hello.py

from flask import Flask
app = Flask(__name__)

@app.route("/")
def hello():
    return "Hello World!"

if __name__ == "__main__":
    app.run()

```

