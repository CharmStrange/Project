import tkinter as tk

Window=tk.Tk()
Window.geometry('447x682')
Window.title("명부작성")
tk.Label(Window ,text="명부 작성", bg='white', font="Helvetica 32 bold").pack()
Lists=[]
def write():
    window=tk.Tk()
    window.geometry('440x180')
    window.title('명부작성')    
    tk.Label(window, text='순서대로 기입해주세요.', font="Helvetica 16 bold").pack()
    a=tk.Entry(window, width=30, relief='solid', highlightcolor='yellow', highlightthickness=1, textvariable=tk.StringVar());a.place(x=110, y=26)
    b=tk.Entry(window, width=30, relief='solid', highlightcolor='yellow', highlightthickness=1, textvariable=tk.StringVar());b.place(x=110, y=47)
    c=tk.Entry(window, width=30, relief='solid', highlightcolor='yellow', highlightthickness=1, textvariable=tk.StringVar());c.place(x=110, y=68)
    d=tk.Entry(window, width=30, relief='solid', highlightcolor='yellow', highlightthickness=1, textvariable=tk.StringVar());d.place(x=110, y=89)
    a1=tk.Button(window, text="확인", font="Helvetica 8 bold", activebackground='yellow', command=lambda:click1(), state="normal");a1.place(x=330, y=26)
    b1=tk.Button(window, text="확인", font="Helvetica 8 bold", activebackground='yellow', command=lambda:click2(), state="normal");b1.place(x=330, y=47)
    c1=tk.Button(window, text="확인", font="Helvetica 8 bold", activebackground='yellow', command=lambda:click3(), state="normal");c1.place(x=330, y=68)
    d1=tk.Button(window, text="확인", font="Helvetica 8 bold", activebackground='yellow', command=lambda:click4(), state="normal");d1.place(x=330, y=89)
    tk.Button(window, text="저장", font="Helvetica 8 bold", width=30, activebackground='yellow', command=lambda:save()).place(x=110, y=119)
    tk.Button(window, text="기입 완료", font="Helvetica 8 bold", width=30, activebackground='yellow', command=lambda:window.destroy()).place(x=110, y=149)
    tk.Label(window, text="성명").place(x=75, y=29)
    tk.Label(window, text="연락처").place(x=65, y=50)
    tk.Label(window, text="방문날짜").place(x=57, y=71)
    tk.Label(window, text="고유번호").place(x=57, y=92)
    
    def click1():
        Lists.append(a.get())
        print(Lists)

    def click2():
        Lists.append(b.get())
        print(Lists)    

    def click3():
        Lists.append(c.get())
        print(Lists)

    def click4():
        Lists.append(d.get())
        global le
        le=len(Lists)
        print(Lists)
        print(le)

    def save():
        with open("C:/Users/이건희/OneDrive/바탕 화면/작업용/학교 수업/방학/개인 프로젝트/List.txt", 'a') as F: 
            F.write(str(Lists)+'\n');Lists.clear();F.close()

def see():
    window=tk.Tk()
    window.geometry('440x680')
    window.title('명부 보기')    
    tk.Label(window, text='명부 리스트', font="Helvetica 16 bold").pack()
    tk.Label(window, text=[text.split('\n')[0]+'\n' for text in open("List.txt", 'r').readlines()]).place(x=79, y=30);open("List.txt", 'r').close()
    tk.Label(window, text='명부 검색', font="Helvetica 16 bold").place(x=169, y=250)
    a=tk.Entry(window, width=20, relief='solid', highlightcolor='yellow', highlightthickness=1, textvariable=tk.StringVar());a.place(x=145, y=280)
    a1=tk.Button(window, text="검색", command=lambda:search(),font="Helvetica 8 bold", activebackground='yellow', state="normal");a1.place(x=290, y=278)

    def search():
        if a.get() in open("List.txt", 'r').readlines(): # 미완성
            tk.Label(window, text="있음").place(x=160, y=300)
        else:
            # 미완성 print([ls.rstrip('\n') for ls in open("List.txt", 'r').readlines()])
            tk.Label(window, text="없음").place(x=160, y=300)

   
tk.Button(Window, text="작성하기", font="Helvetica 16 bold", bg='white', command=lambda:write()).pack(ipadx=40, ipady=20, expand=True)
tk.Button(Window, text="명부 보기", font="Helvetica 16 bold", bg='white', command=lambda:see()).pack(ipadx=40, ipady=20, expand=True)

Window.mainloop()
