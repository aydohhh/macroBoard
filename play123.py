import spotipy
from spotipy.oauth2 import SpotifyOAuth

# Replace with your own values
SPOTIPY_CLIENT_ID = '14ce4b67e0b2428dae507299d614fbcd'
SPOTIPY_CLIENT_SECRET = 'f8ab0d254059496890bd1faa9e3c9119'
SPOTIPY_REDIRECT_URI = 'https://open.spotify.com/playlist/5HH7GFYghEl6vIi3wnjeDY'
PLAYLIST_URI = 'spotify:playlist:5HH7GFYghEl6vIi3wnjeDY'

# Authenticate with Spotify
sp = spotipy.Spotify(auth_manager=SpotifyOAuth(client_id=SPOTIPY_CLIENT_ID,
                                               client_secret=SPOTIPY_CLIENT_SECRET,
                                               redirect_uri=SPOTIPY_REDIRECT_URI,
                                               scope='user-modify-playback-state'))

# Play the specified playlist
sp.start_playback(context_uri=PLAYLIST_URI)
