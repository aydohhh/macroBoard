import spotipy
from spotipy.oauth2 import SpotifyOAuth

# Spotify app credentials
client_id = '14ce4b67e0b2428dae507299d614fbcd'
client_secret = 'f8ab0d254059496890bd1faa9e3c9119'
redirect_uri = 'https://open.spotify.com/playlist/5HH7GFYghEl6vIi3wnjeDY'

# Authenticate the app and get an access token
sp = spotipy.Spotify(auth_manager=SpotifyOAuth(client_id=client_id, client_secret=client_secret, redirect_uri=redirect_uri, scope='user-read-playback-state user-modify-playback-state'))
# Get the current playback state
playback_state = sp.current_playback(market="US")

# Check if the shuffle state is on
shuffle_state = playback_state['shuffle_state']
print(shuffle_state)
if shuffle_state:
    # Turn shuffle off
    sp.shuffle(False)
    print("Shuffle off")
else:
    # Turn shuffle on
    sp.shuffle(True)
    print("Shuffle on")
