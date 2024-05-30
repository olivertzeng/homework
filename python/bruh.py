import turtle
from colorsys import hsv_to_rgb


screen = turtle.Screen()
screen.setup(width=600, height=600)


t = turtle.Turtle()
t.speed(0)


def rounded_square(size, radius):
    t.penup()
    t.goto(-size // 2, radius)
    t.pendown()

    for i in ("red", "blue", "green"):
        t.color(i)
        t.begin_fill()
        t.forward(size - radius * 2)
        t.circle(radius, 90)
        t.end_fill()
        t.forward(size - radius * 2)
        t.left(90)


for i in range(1, 10):
    rounded_square(100, 20)
    t.left(40)


screen.mainloop()
