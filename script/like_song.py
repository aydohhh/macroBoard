import spotipy
from spotipy.oauth2 import SpotifyOAuth

# Spotify app credentials
client_id = '14ce4b67e0b2428dae507299d614fbcd'
client_secret = 'f8ab0d254059496890bd1faa9e3c9119'
redirect_uri = 'https://open.spotify.com/playlist/5HH7GFYghEl6vIi3wnjeDY'

# Authenticate the app and get an access token
sp = spotipy.Spotify(auth_manager=SpotifyOAuth(client_id=client_id, client_secret=client_secret, redirect_uri=redirect_uri, scope='user-library-modify user-read-playback-state'))

# Check if there is an active playback session
playback_state = sp.current_playback()
if playback_state is None:
    print("No active playback session.")
else:
    # Get the current track ID
    track_id = playback_state['item']['id']
    
    # Like the track
    sp.current_user_saved_tracks_add([track_id])
    print("Liked the current track!")
