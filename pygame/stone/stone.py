# Copyright (c) 2024 Oliver Tzeng. All Rights Reserved.
# created: 24/03/06 13/38

from random import randint
from screeninfo import get_monitors
import pygame

pygame.init()

width = get_monitors()[0].width
height = get_monitors()[0].height

screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("stone")

clock = pygame.time.Clock()
stones = []
last_spawn_stone = pygame.time.get_ticks()


class rabbit:
    def __init__(self):
        self.pos_x = width * 0.45
        self.pos_y = height * 0.75
        self.speed_x = 50
        self.direction_x = 0
        self.irabbit = pygame.image.load('src/rabbit.png')

    def update(self, keys):
        if keys[pygame.K_LEFT]:
            self.direction_x = -1
        elif keys[pygame.K_RIGHT]:
            self.direction_x = 1
        else:
            self.direction_x = 0

        self.pos_x += self.direction_x * self.speed_x
        if self.pos_x <= 0:
            self.pos_x = 0
        elif self.pos_x >= width - 100:
            self.pos_x = width - 100

    def draw(self):
        screen.blit(self.irabbit, (self.pos_x, self.pos_y))


class stone:
    def __init__(self):
        self.pos_x = randint(0, width)
        self.pos_y = -50
        self.speed_y = 0
        self.acceleration_y = 9.8 / pygame.time.Clock.get_fps(clock)
        self.istone = pygame.image.load('src/stone.png')

    def update(self):
        self.speed_y += self.acceleration_y
        self.pos_y += self.speed_y

    def draw(self):
        screen.blit(self.istone, (self.pos_x, self.pos_y))


playing = True
player = rabbit()
while playing:
    for event in pygame.event.get():
        match event.type:
            case pygame.QUIT:
                playing = False

    # stone
    if pygame.time.get_ticks() - last_spawn_stone >= 1000:
        stones.append(stone())
        last_spawn_stone = pygame.time.get_ticks()

    for s in stones:
        s.update()
        if s.pos_y >= height:
            stones.remove(s)
        s.draw()

    # player
    player.update(pygame.key.get_pressed())
    player.draw()

    screen.fill("white")
    pygame.display.update()
    clock.tick(60)
pygame.quit()
quit()
