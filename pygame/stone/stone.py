#created: 24/03/06 13/38

import pygame
from random import randint
from screeninfo import get_monitors

pygame.init()

width = get_monitors()[0].width 
height = get_monitors()[0].height 

screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("stone")

clock = pygame.time.Clock()
rabbit = pygame.image.load('src/rabbit.png')
stones = []
stone_x = []
stone_y = []
stone_y_speed = []
last_spawn_stone = pygame.time.get_ticks()
x = (width * 0.45)
y = (height * 0.75)
x_direction = 0
x_speed = 15

class stone:
    def __init__(self):
        self.pos_x = randint(0, width)
        self.pos_y = -50
        self.speed_y = 0
        self.istone = pygame.image.load('src/stone.png')

    def update(self):
        self.speed_y += 0.16
        self.pos_y += self.speed_y

    def draw(self):
        screen.blit(self.stone, (self.pos_x, self.pos_y))

class rabbit:
    def __init__(self):
        self.pos_x = width * 0.45
        self.pos_y = height * 0.75
        self.vy = 0

    def update(self):
        

playing = True
while playing:
    # pygame events including keypresses and program termination
    for event in pygame.event.get():
        match event.type:
            case pygame.QUIT:
                playing = False
            case pygame.KEYUP:
                match event.key:
                    case pygame.K_LEFT | pygame.K_RIGHT:
                        x_direction = 0
            case pygame.KEYDOWN:
                match event.key:
                    case pygame.K_LEFT:
                        x_direction = -1
                    case pygame.K_RIGHT:
                        x_direction = 1

    # stone spawning
    if pygame.time.get_ticks() - last_spawn_stone >= 1000:
        stones.append(stone())
        last_spawn_stone = pygame.time.get_ticks()

    # player
    x += x_direction * x_speed
    if x <= 0:
        x = 0
    elif x >= width - 100:
        x = width - 100

    # stone
    for stone in stones:
        stone.update()
        if stone.pos_y >= height:
            stones.remove(stone)

    screen.fill("white") 
    screen.blit(rabbit, (x, y))
    for stone in stones:
        stone.draw()
    pygame.display.update()
    clock.tick(60)
pygame.quit()
quit()

