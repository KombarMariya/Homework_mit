from tkinter import *
import random
import time

class Ball:
    def __init__(self, canvas, paddle, color): # рисование мяча
        self.canvas = canvas
        self.paddle = paddle
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
        if self.hit_paddle(pos) == True:
            self.y = -3
        if pos[0] <= 0:
            self.x = 3
        if pos[2] >= self.canvas_width:
            self.x = -3

    def hit_paddle(self, pos): # столкновение ракетки и мяча
        paddle_pos = self.canvas.coords(self.paddle.id)
        if pos[2] >= paddle_pos[0] and pos[0] <= paddle_pos[2]:
            if pos[3] >= paddle_pos[1] and pos[3] <= paddle_pos[3]:
                return True
            return False
class Paddle:
    def __init__(self, canvas, color): # рисование ракетки
        self.canvas = canvas
        self.id = canvas.create_rectangle(0, 0, 100, 10, fill=color)
        self.canvas.move(self.id, 200, 300)
        self.x = 0
        self.canvas_width = self.canvas.winfo_width()
        self.canvas.bind_all('<KeyPress-Left>', self.turn_left)
        self.canvas.bind_all('<KeyPress-Right>', self.turn_right)
    def draw(self): # перемещение ракетки
        self.canvas.move(self.id, self.x, 0)
        pos = self.canvas.coords(self.id)
        if pos[0] <= 0:
            self.x = 0
        elif pos[2] >= self.canvas_width:
            self.x = 0

    # смена направления
    def turn_left(self, evt):
        self.x = -2
    def turn_right(self, evt):
        self.x = 2


tk = Tk()
tk.title("Игра") # заголовок игрового окна
tk.resizable(0, 0) # фиксированный размер окна
tk.wm_attributes("-topmost", 1) # поверх остальных окон
canvas = Canvas(tk, width=500, height=400, bd=0, highlightthickness=0)
canvas.pack()
tk.update()
paddle = Paddle(canvas, 'blue') # объект класса Paddle
ball = Ball(canvas, paddle, 'red') # объект класса Ball

while 1:
    ball.draw() # вызов функции объекта-мяча
    paddle.draw() # вызов функции объекта-ракетки
    tk.update_idletasks()
    tk.update()
    time.sleep(0.01) # приостановление выполнения кода
