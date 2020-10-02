from tkinter import *
from tkinter import filedialog
from tkinter import ttk
from tkinter import messagebox
from tkinter.scrolledtext import ScrolledText

def closeWindow(window):
    window.destroy()

def saveDialog():
    save = messagebox.askokcancel("Vizual Studio Code","Do you want to save this file?")
    if save:
        saveAs()

def newFile():
    global text
    saveDialog()
    text.delete(1.0, END)

def saveAs():
    global text
    t = text.get("1.0",'end-1c')
    saveLoc = filedialog.asksaveasfilename()
    saveFile = open(saveLoc,'w+')
    saveFile.write(t)
    saveFile.close()

def openFile():
    global text
    text.delete(1.0, END)
    filePath = filedialog.askopenfilename()
    fileToOpen = open(filePath,'r')
    fileText = fileToOpen.read()
    text.insert(END, fileText)

def cut():
    global text,clipboard
    clipboard = text.selection_get()
    content = text.get("1.0",'end-1c')
    newContent = content.replace(clipboard,"")
    text.delete(1.0,END)
    text.insert(END, newContent)

def copy():
    global text,clipboard
    clipboard = text.selection_get()

def paste():
    global text,clipboard
    text.insert(INSERT,clipboard)

def closeEditor():
    global text
    saveDialog()
    closeWindow(editor)

def assemble():
    pass

def findDialog():
    pass

def replaceDialog():
    pass

def find(string):
    pass

def replace():
    pass

def selectAll():
    global text
    text.tag_add(SEL,"1.0",END)
    text.focus_set()

def aboutBox():
    about = Tk()
    about.geometry('400x200')
    about.title("About Vizual Studio Code")
    about['bg'] = "#1e1e1e"
    textForAbout = '''
        App Name : Vizual Studio Code
        App Author : Varun Bheemaiah
        App version : 1.0.0
        App Stage : Beta
    '''
    aboutText = Label(about,text=textForAbout)
    aboutText.config(bg="#1e1e1e", fg="#b0b0b0", font=('Helvetica',16))
    aboutText.grid(row=0,column=0)

    closeButton = Button(about, text="Close", command=lambda: closeWindow(about), fg="white", bg="#b10c2d", activebackground="#b10c2d", activeforeground="white")
    closeButton.grid(row=1,column=0)
    about.mainloop()

clipboard = ""
size = 15
font = "Consolas"
editor = Tk()
editor.title("Vizual Studio Code")

menubar = Menu(editor,activebackground="#b10c2d", activeforeground="white", bg="#1e1e1e", fg="#b0b0b0")

fileMenu = Menu(menubar, tearoff=0)
fileMenu.config(activebackground="#b10c2d", activeforeground="white", bg="#1e1e1e", fg="#b0b0b0")
fileMenu.add_command(label="New", command=newFile)
fileMenu.add_command(label="Open", command=openFile)
fileMenu.add_command(label="Save", command=saveAs)
fileMenu.add_separator()
fileMenu.add_command(label="Close", command=closeEditor)
menubar.add_cascade(label="File", menu=fileMenu)

editMenu = Menu(menubar, tearoff=0)
editMenu.config(activebackground="#b10c2d", activeforeground="white", bg="#1e1e1e", fg="#b0b0b0")
editMenu.add_command(label="Cut", command=cut)
editMenu.add_command(label="Copy", command=copy)
editMenu.add_command(label="Paste", command=paste)
editMenu.add_separator()
editMenu.add_command(label="Select All", command=selectAll)
editMenu.add_separator()
editMenu.add_command(label="Find", command=findDialog)
editMenu.add_command(label="Replace", command=replaceDialog)
menubar.add_cascade(label="Edit", menu=editMenu)

toolMenu = Menu(menubar,tearoff=0)
toolMenu.config(activebackground="#b10c2d", activeforeground="white", bg="#1e1e1e", fg="#b0b0b0")
theme = Menu(toolMenu, tearoff=0)
theme.config(activebackground="#b10c2d", activeforeground="white", bg="#1e1e1e", fg="#b0b0b0")
theme.add_command(label="Dark")
theme.add_command(label="Light")
toolMenu.add_cascade(label="Theme", menu=theme)
toolMenu.add_separator()
toolMenu.add_command(label="Assemble")
menubar.add_cascade(label="Tools", menu=toolMenu)

helpMenu = Menu(menubar, tearoff=0)
helpMenu.config(activebackground="#b10c2d", activeforeground="white", bg="#1e1e1e", fg="#b0b0b0")
helpMenu.add_command(label="About", command=aboutBox)
menubar.add_cascade(label="Help", menu=helpMenu)


text = ScrolledText(editor, fg="#b0b0b0", bg="#1e1e1e", wrap=WORD, width=50, height=10)
text.config(font=(font,size), insertbackground="#b0b0b0", selectbackground="#b10c2d", selectforeground="white")
scrollBar = Scrollbar(command=text.yview)
text['yscrollcommand'] = scrollBar.set
text.pack(fill=BOTH, expand=1)


editor.config(menu=menubar)
editor.mainloop()
