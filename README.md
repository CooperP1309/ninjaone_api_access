# NinjaOne API Access

### Usage

#### Usage Prerequisites
To use APIs in NinjaOne, you must create a 'Client App' in the NinjaOne settings. Link for doing this will be provided, but it doesn't 
explain the exact details required, so apply the below settings first, then follow the link if you're stuck.

- Client app must be of type: 'API Services':

<img width="918" height="424" alt="image" src="https://github.com/user-attachments/assets/b9806436-50d3-4835-b768-8d43069f6903" />

- When making client app, 'Client Credentials' must be enabled:

<img width="894" height="218" alt="image" src="https://github.com/user-attachments/assets/f6f3178f-d2c7-4032-ab1a-5e66089e8d72" />

NinjaOne Guide: https://ninjarmm.zendesk.com/hc/en-us/articles/4403617211277-API-OAuth-Token-Configuration

#### Steps

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

4. Run app.exe
On success, your api access token will be printed. The source code has been left as to allow for a base to build off.  

### Extra Notes
- This is an implementation for Windows devices as that's what most IT companies use (as far as I'm aware) 
- I built this using MSYS2 MINGW (Install here: https://github.com/orlp/dev-on-windows/wiki/Installing-GCC--&-MSYS2)
- Developing with this repo requires libcurl (Easy install: https://everything.curl.dev/install/windows/win-msys2.html)
