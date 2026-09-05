import yt_dlp

URL = "https://www.youtube.com/watch?v=YOUR_VIDEO_ID"

options = {
    "format": "bestvideo+bestaudio/best",
    "outtmpl": "%(title)s.%(ext)s",
    "merge_output_format": "mp4",
}

with yt_dlp.YoutubeDL(options) as ydl:
    ydl.download([URL])