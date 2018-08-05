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

## Flask (web framework)

Flask is a micro web framework written in Python.
- Open "Command Prompt" as administrator then run `pip install Flask`

The following code shows a simple web application that prints "Hello World!":

```python
from flask import Flask
app = Flask(__name__)

@app.route("/")
def hello():
    return "Hello World!"

if __name__ == "__main__":
    app.run()

```

