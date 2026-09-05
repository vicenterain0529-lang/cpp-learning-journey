import yt_dlp

print("==========================YOUTUBE VIDEO DOWNLOADER==============================")

options = {
    "format": "bestvideo+bestaudio/best",
    "outtmpl": r"C:\Users\Windows\Videos\%(title)s.%(ext)s"
}

while True:
    url = input("Enter the URL (or type 'exit' to quit): ")

    if url.lower() == "exit":
        break

    with yt_dlp.YoutubeDL(options) as ydl:
        ydl.download([url])

    print("Download Completed!!\n")