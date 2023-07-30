import pycaw
from pycaw.pycaw import AudioUtilities, ISimpleAudioVolume

# Define the name of the output device to switch to
device_name = "Speakers (High Definition Audio Device)"

# Get a list of all audio endpoints (devices)
devices = AudioUtilities.GetSpeakers()
if isinstance(devices, list):
    # Multiple devices found
    device_id = None
    for dev in devices:
        if dev.DeviceFriendlyName == device_name:
            device_id = dev.DeviceId
            break
else:
    # Single device found
    device_id = devices.DeviceId

# If the device was found, switch the default audio output to it
if device_id is not None:
    sessions = AudioUtilities.GetAllSessions()
    for session in sessions:
        volume = session.SimpleAudioVolume
        if session._ctl.QueryInterface(ISimpleAudioVolume).GetDisplayName() == "System Sounds":
            volume.SetMute(1, None)
        elif session._ctl.QueryInterface(ISimpleAudioVolume).GetDisplayName() == "Spotify":
            volume.SetMute(1, None)
        else:
            volume.SetMute(0, None)
            volume.SetMasterVolume(1, None)
            volume.SetEndpointVolume(1, device_id)
    print(f"Audio output switched to '{device_name}'.")
else:
    print(f"Device '{device_name}' not found.")
