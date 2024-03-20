# Copyright (c) 2024 Oliver Tzeng. All Rights Reserved.
# created: 2024/03/06 13/38

from random import randint
from screeninfo import get_monitors
import sys, pygame

sys.path.insert(0, 'src')

import settings
import sprites

class Game:
	def __init__(self):
		pygame.init()

		self.screen = pygame.display.set_mode((width, height))
		pygame.display.set_caption(caption)

		self.clock = pygame.time.Clock()
		self.playing = True
		self.last_spawn_stone = pygame.time.get_ticks()
		self.stones = []
		self.player = rabbit(self)
	
	def events(self):
		for event in pygame.event.get():
			match event.type:
				case pygame.QUIT:
					self.playing = False

	def update(self):

		player.update(pygame.key.get_pressed())

		if pygame.time.get_ticks() - last_spawn_stone >= 1000:
			self.stones.append(stone(self))
			self.last_spawn_stone = pygame.time.get_ticks()

		for s in stones:
			s.update()
			if s.pos_y >= height:
				self.stones.remove(s)

	def draw(self):
		self.screen.fill(color)
		self.player.draw()
		for s in self.stones:
			s.draw()
		pygame.display.update()

	def run(self):
		while self.playing:
			self.events()
			self.update()
			self.draw()
			self.clock.tick(fps)

game = Game()
game.run()
pygame.quit()
quit()
