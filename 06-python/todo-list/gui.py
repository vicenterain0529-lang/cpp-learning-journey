from tkinter import *

window = Tk() # instantiate the window for us
label = Label(window, text="To Do List Program", font=("Arial", 20, "bold"), bg="White", fg="black") # create a label for the window
#label.place(x=300, y=10) # returns the text at a specific location in the window
label.pack() # returns the text at a specific location in the window
window.geometry("800x800") # set the size of the window
window.title("To Do List Program") # set the title of the window

icon = PhotoImage(file="kidlat.png")
window.iconphoto(True, icon) # set the icon of the window
window.config(bg="White") # set the background color of the window



window.mainloop() # run the window until we close it