from tkinter import *
import random
import time

class Ball:
    def __init__(self, canvas, color): # рисование мяча
        self.canvas = canvas
        self.id = canvas.create_oval(10, 10, 25, 25, fill=color)
        self.canvas.move(self.id, 245, 100)
        starts = [-3, -2, -1, 1, 2, 3]
        random.shuffle(starts)
        self.x = starts[0]
        self.y = -3
        self.canvas_height = self.canvas.winfo_height()
        self.canvas_width = self.canvas.winfo_width()

    def draw(self): # перемещение мяча
        self.canvas.move(self.id, self.x, self.y)
        pos = self.canvas.coords(self.id)
        if pos[1] <= 0:
            self.y = 3
        if pos[3] >= self.canvas_height:
            self.y = -3
        if pos[0] <= 0:
            self.x = 3
        if pos[2] >= self.canvas_width:
            self.x = -3
class Paddle:
    def __init__(self, canvas, color): # рисование ракетки
        self.canvas = canvas
        self.id = canvas.create_rectangle(0, 0, 100, 10, fill=color)
        self.canvas.move(self.id, 200, 300)
    def draw(self):
        pass

tk = Tk()
tk.title("Игра") # заголовок игрового окна
tk.resizable(0, 0) # фиксированный размер окна
tk.wm_attributes("-topmost", 1) # поверх остальных окон
canvas = Canvas(tk, width=500, height=400, bd=0, highlightthickness=0)
canvas.pack()
tk.update()
paddle = Paddle(canvas, 'blue') # объект класса Paddle
ball = Ball(canvas, 'red') # объект класса Ball

while 1:
    ball.draw() # вызов функции объекта-мяча
    paddle.draw() # вызов функции объекта-ракетки
    tk.update_idletasks()
    tk.update()
    time.sleep(0.01) # приостановление выполнения кода
