# Twilio Send SMS

At administrator "Command Prompt"
- `pip install twilio`

## Code

`twilio_send.py`

```python
from twilio.rest import Client

# Your Account SID from twilio.com/console
account_sid = "AC9157847d72b1aa5370fdef36786863d9"
# Your Auth Token from twilio.com/console
auth_token  = "73cad721b8cad6718d469acc42ffdb1f"

client = Client(account_sid, auth_token)

message = client.messages.create(
    to="+17783335555", 
    from_="+17787779999",
    body="Hello from Python!"
)

print(message.sid)

```

## Code using environment variables

`twilio_send_env.py`

```python
import os

from twilio.rest import Client

# Your Account SID from twilio.com/console
account_sid = os.environ["TWILIO_ACCOUNT_SID"]
# Your Auth Token from twilio.com/console
auth_token  = os.environ["TWILIO_AUTH_TOKEN"]

client = Client(account_sid, auth_token)

message = client.messages.create(
    to="+17783335555", 
    from_="+17787779999",
    body="Hello from Python!"
)

print(message.sid)

```
