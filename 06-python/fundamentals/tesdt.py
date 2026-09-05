import yt_dlp

url = "https://www.youtube.com/watch?v=zoSMu08rmQY"

options = {
    "format": "bestvideo+bestaudio/best",
    "outtmpl": "%(title)s.%(ext)s"
}

with yt_dlp.YoutubeDL(options) as ydl:
    ydl.download([url])