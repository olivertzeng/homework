import pygame, random
from screeninfo import get_monitors
from math import pi

pygame.init()

width = get_monitors()[0].width
height = get_monitors()[0].height
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("DVD ScreenSaver")

colors = ("green", "red", "violet", "blue", "white", "cyan")
color = colors[random.randint(0, len(colors) - 1)]


def randcol(current):
    buf = colors[random.randint(0, len(colors) - 1)]
    while buf == current:
        buf = colors[random.randint(0, len(colors) - 1)]
    return buf


dvd_x = dvd_y = 0
direction_x = direction_y = 1

clock = pygame.time.Clock()
playing = True
while playing:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            playing = False
    dvd_x += 10 * direction_x
    dvd_y += 10 * direction_y
    if dvd_x <= 0:
        direction_x = 1
        color = randcol(color)
    elif dvd_x >= width - 20:
        direction_x = -1
        color = randcol(color)
    if dvd_y <= 0:
        direction_y = 1
        color = randcol(color)
    elif dvd_y >= height - 60:
        direction_y = -1
        color = randcol(color)
    screen.fill("black")
    pygame.draw.ellipse(screen, color, [dvd_x, dvd_y, 120, 60])
    pygame.display.update()
    clock.tick(30)
pygame.quit()
quit()
