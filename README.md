# NinjaOne API Access

## Usage

### Usage Prerequisites
- Must make client app on NinjaOne
- Client app must be of type: 'API Services':

<img width="918" height="424" alt="image" src="https://github.com/user-attachments/assets/b9806436-50d3-4835-b768-8d43069f6903" />

- When making client app, 'Client Credentials' must be enabled:

<img width="894" height="218" alt="image" src="https://github.com/user-attachments/assets/f6f3178f-d2c7-4032-ab1a-5e66089e8d72" />

### Steps

1. Clone this directory
```
git clone https://github.com/CooperP1309/ninjaone_api_access
```

2. Change into the root of the repo and make a 'client_credentials.txt'
```
cd ninjaone_api_access
touch client_credentials.txt
```

3. Populate the txt file with the following fields from your client app in NinjaOne
```
client_id= 'sPTeCnjWeziCkZmfqFSBOyiSVWN'
client_secret= 'fYWOyOBBYQcThlGdPMYtesEPQRdfYWOyOBBYQcThlGdPMYtesEPQRd'
scope= 'monitoring'
host= 'https://jimothy-it.rmmservice.com'
```
NOTE: The layout of your file must match the above example. Including use of apostrophes.
NOTE: Your ninjaOne host might be generic like 'app.ninjarmm.com' or 'eu.ninjarmm.com' or api.ninjarmm.com
ANOTHER NOTE: As of writing this, only one scope at a time is supported.

