import spotipy
from spotipy import util

SPOTIPY_CLIENT_ID='14ce4b67e0b2428dae507299d614fbcd'
SPOTIPY_CLIENT_SECRET = 'f8ab0d254059496890bd1faa9e3c9119'
SPOTIPY_REDIRECT_URI = 'https://open.spotify.com/playlist/5HH7GFYghEl6vIi3wnjeDY'
USERNAME = "aiden_holm11@outlook.com"
PLAYLIST_URI = 'spotify:playlist:5fNyIqrmURfbtRvsZks4RP'

# Authenticate with Spotify
#sp = spotipy.Spotify(auth_manager=SpotifyOAuth(client_id=SPOTIPY_CLIENT_ID,
#                                               client_secret=SPOTIPY_CLIENT_SECRET,
#                                               redirect_uri=SPOTIPY_REDIRECT_URI,
#                                               scope='user-modify-playback-state'))

# Get the user's access token
token = util.prompt_for_user_token(USERNAME, scope='user-library-read,user-modify-playback-state')

# Create a Spotipy object with the user's access token
sp = spotipy.Spotify(auth=token)

# Start playing the playlist on the user's device
sp.start_playback(context_uri=PLAYLIST_URI)



