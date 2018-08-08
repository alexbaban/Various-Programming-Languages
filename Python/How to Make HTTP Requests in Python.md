How to Make HTTP Requests in Python

`nasa.py`

```python
import urllib.request


def main():

    url = "https://api.nasa.gov/planetary/apod"

    args = {
        "api_key": "DEMO_KEY" 
    }

    data = urllib.parse.urlencode(args)

    result = urllib.request.urlopen(url + "?" + data)

    print("Result code: {0}".format(result.status))

    print("Headers: -------------------------------")
    print(result.getheaders())

    print("Data: ----------------------------------")
    print(result.read().decode('utf-8'))


if __name__ == "__main__":
    main()

```
