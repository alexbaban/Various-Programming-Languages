# Twilio Reply to SMS

- Flask app
- Ngrok running on your localhost port
- configure Twilio phone number to call the webhook URL 

## Code

`run.py`

```python
# /usr/bin/env python
# Download the twilio-python library from twilio.com/docs/libraries/python

from flask import Flask, request
from twilio.twiml.messaging_response import MessagingResponse

app = Flask(__name__)

@app.route("/sms", methods=['GET', 'POST'])
def sms_ahoy_reply():
    """Respond to incoming messages with a friendly SMS."""
    # Start our response
    resp = MessagingResponse()

    # Add a message
    resp.message("Ahoy! Thanks so much for your message.")

    return str(resp)

if __name__ == "__main__":
    app.run(debug=True)
    
```
