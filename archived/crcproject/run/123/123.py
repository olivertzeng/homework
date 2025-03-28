import os
import random

import pygame as pg
from pygame.locals import *

CREDIT = "2xDx25x2E3"
CURRENTPATH = os.path.dirname(__file__)


class enemy(pg.sprite.Sprite):
    def __init__(self, pos_y):
        super(enemy, self).__init__()
        self.images = []
        self.images.append(
            pg.transform.scale(
                pg.image.load("123/123/1.png"),
                (int(170 * screen_radio), int(170 * screen_radio)),
            )
        )
        self.images.append(
            pg.transform.scale(
                pg.image.load("123/123/2.png"),
                (int(170 * screen_radio), int(170 * screen_radio)),
            )
        )
        self.image = self.images[0]
        self.image.set_colorkey((255, 255, 255), RLEACCEL)
        self.num = random.randint(1, 3)
        self.pos_x = [0, int(170 * screen_radio), int(340 * screen_radio)]
        self.rect = self.image.get_rect(topleft=(self.pos_x[self.num - 1], pos_y))
        self.jumpCount = 6
        self.neg = 1
        self.jumpFinish = True

    def check(self, key):
        if self.rect.top == int(680 * screen_radio):
            if key == self.num:
                global generate, moveCount
                generate = True
                moveCount += 2
                if self.num == 1:
                    hand1.isSlap = True
                elif self.num == 2:
                    hand2.isSlap = True
                elif self.num == 3:
                    hand3.isSlap = True
                self.kill()
                pg.event.post(scored)
                return True
            elif key in [1, 2, 3] and key != self.num:
                pg.event.post(miss)
        return False

    def update(self):
        self.rect.move_ip(0, int(85 * screen_radio))

    def jump(self):
        if self.rect.bottom > int(680 * screen_radio):
            if self.jumpCount >= -6:
                self.rect.bottom = int(
                    (850 - 1.8 * (36 - (self.jumpCount**2))) * screen_radio
                )
                self.jumpCount -= 1
                pg.event.post(miss)
                self.jumpFinish = False
            else:
                self.jumpCount = 6
                self.jumpFinish = True
            return True
        return False


class hand(pg.sprite.Sprite):
    def __init__(self, pos_x):
        super(hand, self).__init__()
        self.images = []
        self.images.append(
            pg.transform.scale(
                pg.image.load("123/hand/1.png"),
                (int(91 * screen_radio), int(132 * screen_radio)),
            )
        )
        self.images.append(
            pg.transform.scale(
                pg.image.load("123/hand/2.png"),
                (int(126 * screen_radio), int(154 * screen_radio)),
            )
        )
        self.images.append(
            pg.transform.scale(
                pg.image.load("123/hand/3.png"),
                (int(139 * screen_radio), int(144 * screen_radio)),
            )
        )
        self.index = 2
        self.image = self.images[self.index]
        self.image.set_colorkey((255, 255, 255), RLEACCEL)
        self.rect = self.image.get_rect(bottomright=(pos_x, int(1020 * screen_radio)))
        self.isSlap = False
        self.count = 0
        self.slapHz = 3

    def update(self):
        self.index += 1
        if self.index >= len(self.images):
            self.index = 0
        self.image = self.images[self.index]


class timer(pg.sprite.Sprite):
    def __init__(self):
        super(timer, self).__init__()
        self.surf = pg.Surface((int(40 * screen_radio), int(30 * screen_radio)))
        self.rect = self.surf.get_rect(topleft=(0, 0))
        self.font = pg.font.SysFont(fontPath, int(30 * screen_radio), True)
        self.timeCount = 20
        self.text = self.font.render("TIME:" + str(self.timeCount), True, (0, 0, 0))

    def update(self):
        self.timeCount -= 1
        if self.timeCount <= 0:
            self.timeCount = 0
        self.text = self.font.render("TIME:" + str(self.timeCount), True, (0, 0, 0))


class scoreboard(pg.sprite.Sprite):
    def __init__(self):
        super(scoreboard, self).__init__()
        self.surf = pg.Surface((int(40 * screen_radio), int(30 * screen_radio)))
        self.rect = self.surf.get_rect(topleft=(0, int(30 * screen_radio)))
        self.font = pg.font.SysFont(fontPath, int(30 * screen_radio), True)
        self.score = 0
        self.text = self.font.render("SCORE:" + str(self.score), True, (0, 0, 0))

    def update(self):
        self.text = self.font.render("SCORE:" + str(self.score), True, (0, 0, 0))


class endScore(pg.sprite.Sprite):
    def __init__(self, score=0):
        super(endScore, self).__init__()
        self.surf = pg.Surface((int(100 * screen_radio), int(100 * screen_radio)))
        self.score = score
        self.font = pg.font.SysFont(fontPath, int(73 * screen_radio), True)
        self.rect = self.surf.get_rect(
            center=(int(335 * screen_radio), int(295 * screen_radio))
        )
        self.count = 0
        self.images = []
        self.images.append(
            pg.transform.scale(
                pg.image.load("123/bg/endbg1.png"),
                (int(510 * screen_radio), int(1020 * screen_radio)),
            )
        )
        self.images.append(
            pg.transform.scale(
                pg.image.load("123/bg/endbg2.png"),
                (int(510 * screen_radio), int(1020 * screen_radio)),
            )
        )
        self.image = self.images[self.count]
        self.image.set_colorkey((255, 255, 255), RLEACCEL)
        self.text = self.font.render(str(self.score), True, (0, 0, 0))

    def update(self, score):
        self.count += 1
        self.count %= 2
        if self.count == 0:
            self.text = self.font.render(str(score), True, (0, 0, 0))
        else:
            self.text = self.font.render("", False, (0, 0, 0))
        self.image = self.images[self.count]


class explosion(pg.sprite.Sprite):
    def __init__(self):
        super(explosion, self).__init__()
        global showingCredit
        self.surf = pg.Surface((int(450 * screen_radio), int(641 * screen_radio)))
        self.images = []
        self.index = 0
        self.path = os.path.join(CURRENTPATH, "explosion")
        for i in range(1, 18):
            self.images.append(
                pg.transform.scale(
                    pg.image.load(os.path.join(self.path, "%d.png" % i)),
                    (int(400 * screen_radio), int(570 * screen_radio)),
                )
            )
        self.image = self.images[self.index]
        self.image.set_colorkey((255, 255, 255), RLEACCEL)
        self.rect = self.image.get_rect(
            topleft=(int(55 * screen_radio), int(100 * screen_radio))
        )

    def update(self):
        self.index += 1
        if self.index >= len(self.images):
            self.index = 0
        self.image = self.images[self.index]


class ricardo(pg.sprite.Sprite):
    def __init__(self):
        super(ricardo, self).__init__()
        self.surf = pg.Surface((int(450 * screen_radio), int(641 * screen_radio)))
        self.images = []
        self.index = 0
        for i in range(1, 19):
            self.images.append(
                pg.transform.scale2x(pg.image.load("123/ricardo/%d.png" % i))
            )
        self.image = pg.transform.scale(
            self.images[self.index],
            (
                int(self.images[self.index].get_width() * screen_radio),
                int(self.images[self.index].get_height() * screen_radio),
            ),
        )
        self.image.set_colorkey((255, 255, 255), RLEACCEL)
        self.rect = self.image.get_rect(
            center=(int(255 * screen_radio), int(510 * screen_radio))
        )

    def update(self):
        self.index += 1
        if self.index >= len(self.images):
            pg.event.post(start)
            self.index = 0
        if self.index % 6 == 0:
            pg.event.post(countdown)
        self.image = pg.transform.scale2x(self.images[self.index])
        self.image = pg.transform.scale(
            self.images[self.index],
            (
                int(self.images[self.index].get_width() * screen_radio),
                int(self.images[self.index].get_height() * screen_radio),
            ),
        )


class mountainDew(pg.sprite.Sprite):
    def __init__(self):
        super(mountainDew, self).__init__()
        self.images = []
        self.index = 0
        for i in range(1, 9):
            self.images.append(pg.image.load("123/mountaindew/%d.png" % i))
        self.image = pg.transform.scale(
            self.images[self.index], (int(150 * screen_radio), int(150 * screen_radio))
        )
        self.move_speed = random.randint(int(30 * screen_radio), int(70 * screen_radio))
        self.image.set_colorkey((255, 255, 255), RLEACCEL)
        self.rect = self.image.get_rect(
            center=(
                random.randint(int(100 * screen_radio), int(410 * screen_radio)),
                random.randint(int(100 * screen_radio), int(920 * screen_radio)),
            )
        )
        self.x_dir = random.choice([1, -1])
        self.y_dir = random.choice([1, -1])

    def update(self):
        self.move_speed = random.randint(int(30 * screen_radio), int(70 * screen_radio))
        self.index += 1
        if self.index >= len(self.images):
            self.index = 0
        self.image = pg.transform.scale(
            self.images[self.index], (int(150 * screen_radio), int(150 * screen_radio))
        )
        self.rect.move_ip(self.x_dir * self.move_speed, self.y_dir * self.move_speed)
        if self.rect.top <= int(-40 * screen_radio):
            self.rect.top = int(-40 * screen_radio)
            self.y_dir *= -1
        elif self.rect.bottom >= int(1060 * screen_radio):
            self.rect.bottom = int(1060 * screen_radio)
            self.y_dir *= -1
        elif self.rect.left <= int(-40 * screen_radio):
            self.rect.left = int(-40 * screen_radio)
            self.x_dir *= -1
        elif self.rect.right >= int(550 * screen_radio):
            self.rect.right = int(550 * screen_radio)
            self.x_dir *= -1


class frog(pg.sprite.Sprite):
    def __init__(self, x, isFlip=False):
        super(frog, self).__init__()
        self.surf = pg.Surface((int(201 * screen_radio), int(183 * screen_radio)))
        self.images = []
        self.index = 0
        self.isFlip = False
        self.isFlip = isFlip
        for i in range(1, 11):
            self.images.append(
                pg.transform.scale(
                    pg.image.load("123/mlg_frog/frogpics/%d.png" % i),
                    (int(210 * screen_radio), int(183 * screen_radio)),
                )
            )
        self.image = pg.transform.flip(self.images[self.index], self.isFlip, False)
        self.image.set_colorkey((255, 255, 255), RLEACCEL)
        self.rect = self.image.get_rect(topleft=(x, int(450 * screen_radio)))

    def update(self):
        self.index += 1
        if self.index >= len(self.images):
            self.index = 0
        self.image = pg.transform.flip(self.images[self.index], self.isFlip, False)


class pressSpace(pg.sprite.Sprite):
    def __init__(self):
        super(pressSpace, self).__init__()
        self.surf = pg.Surface((int(450 * screen_radio), int(50 * screen_radio)))
        self.rect = self.surf.get_rect(
            topleft=(int(42 * screen_radio), int(800 * screen_radio))
        )
        self.font = pg.font.SysFont(fontPath, int(42 * screen_radio), True)
        self.count = 0
        self.text = self.font.render("PRESS SPACE TO START", True, (0, 0, 0))

    def update(self):
        self.count += 11
        self.count %= 2
        if self.count == 0:
            self.text = self.font.render("PRESS SPACE TO START", True, (0, 0, 0))
        else:
            self.text = self.font.render("", False, (0, 0, 0))


pg.init()


fontPath = "arial"

width, height = 510, 1020
SCREENSIZE = pg.display.Info()
screen_radio = SCREENSIZE.current_h * 0.9 / height
screen = pg.display.set_mode((int(width * screen_radio), int(height * screen_radio)))
pg.display.set_caption(("打淑麗"))
MISS = pg.USEREVENT + 1
TIME = pg.USEREVENT + 2
SCORE = pg.USEREVENT + 3
START = pg.USEREVENT + 4
COUNTDOWN = pg.USEREVENT + 5
TBCEREND = pg.USEREVENT + 7
SHOWCREDIT = pg.USEREVENT + 8
miss = pg.event.Event(MISS)
playTBC = pg.event.Event(TIME)
scored = pg.event.Event(SCORE)
start = pg.event.Event(START)
countdown = pg.event.Event(COUNTDOWN)
showcredit = pg.event.Event(SHOWCREDIT)

explosion = explosion()
print(explosion.path)
frog1 = frog(0)
frog2 = frog(int(309 * screen_radio), True)
mountainDew = mountainDew()
pressSpace = pressSpace()
timer = timer()
scoreboard = scoreboard()
hand1 = hand(int(155 * screen_radio))
hand2 = hand(int(325 * screen_radio))
hand3 = hand(int(495 * screen_radio))
endScore = endScore()
ricardo = ricardo()

startbg = pg.Surface(screen.get_size())
startbg.fill((255, 255, 255))
startbgHead = pg.transform.scale(
    pg.image.load("123/bg/startbg.png"), (int(291 * screen_radio), int(494 * screen_radio))
)
bg = pg.Surface(screen.get_size())
bg = pg.transform.scale(
    pg.image.load("123/bg/bg.jpg"), (int(510 * screen_radio), int(1020 * screen_radio))
)
bg = bg.convert()
startbg = startbg.convert()
game_start = False

boards = pg.sprite.Group()
enemies = pg.sprite.Group()
hands = pg.sprite.Group()
frogs = pg.sprite.Group()
all_sprites = pg.sprite.Group()
boards.add(timer, scoreboard)

hands.add(hand1, hand2, hand3)
frogs.add(frog1, frog2)
all_sprites.add(hand1, hand2, hand3)

pg.mixer.music.set_endevent(TBCEREND)

highscore = open("HighScore.txt", mode="r+")
high_score = highscore.read()

running = True
while running:
    pg.mixer.music.load("123/music/begin.mp3")
    newhigh_score = False
    pg.event.clear(TBCEREND)
    all_sprites.remove(enemies)
    enemies.empty()
    init_enemy1 = enemy(int(0 * screen_radio))
    init_enemy2 = enemy(int(170 * screen_radio))
    init_enemy3 = enemy(int(340 * screen_radio))
    init_enemy4 = enemy(int(510 * screen_radio))
    init_enemy5 = enemy(int(680 * screen_radio))
    enemies.add(init_enemy1, init_enemy2, init_enemy3, init_enemy4, init_enemy5)
    all_sprites.add(enemies)
    countdownNums = [3, 2, 1]
    countdownIndex = 0
    creditShow = (255, 255, 255)
    showingCredit = False
    countdownFont = pg.font.SysFont(fontPath, int(170 * screen_radio), True)
    creditFont = pg.font.SysFont(fontPath, int(30 * screen_radio), True)
    countdownSurface = countdownFont.render(
        str(countdownNums[countdownIndex]),
        True,
        (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255)),
    )
    creditSurface = creditFont.render(CREDIT, True, creditShow)
    game_inproccess = False
    unlocked = [True, True, True]
    slap = False
    slapIndex = 0
    timeEnd = False
    clock = pg.time.Clock()
    moveCount = 0
    timer.timeCount = 20
    scoreboard.score = 0
    scoreboard.update()
    game_start = False
    for hand in hands:
        hand.index = 2
    pg.mixer.music.play()

    while not game_inproccess:
        clock.tick(20)
        for event in pg.event.get():
            if event.type == QUIT:
                highscore.close()
                pg.quit()
                os._exit(0)
            if event.type == KEYDOWN:
                if event.key == K_SPACE:
                    game_inproccess = True
                    pg.time.set_timer(TIME, 1000)
                    break
                if event.key == K_c:
                    showingCredit = True
        pressSpace.update()
        explosion.update()
        if showingCredit:
            creditSurface = creditFont.render(
                CREDIT,
                True,
                (
                    random.randint(0, 255),
                    random.randint(0, 255),
                    random.randint(0, 255),
                ),
            )
        screen.blit(startbg, (0, 0))
        screen.blit(explosion.image, explosion.rect)
        screen.blit(pressSpace.text, pressSpace.rect)
        screen.blit(startbgHead, (int(110 * screen_radio), int(110 * screen_radio)))
        screen.blit(
            creditSurface,
            creditSurface.get_rect(
                bottomright=(int(500 * screen_radio), int(1010 * screen_radio))
            ),
        )
        pg.display.flip()

    pg.mixer.music.load("music/TBCER.mp3")

    while not game_start:
        clock.tick(6)
        for event in pg.event.get():
            if event.type == QUIT:
                highscore.close()
                pg.quit()
                os._exit(0)
            if event.type == START:
                game_start = True
            if event.type == COUNTDOWN:
                countdownIndex += 1
                if countdownIndex > 2:
                    countdownSurface = countdownFont.render(
                        "",
                        True,
                        (
                            random.randint(0, 255),
                            random.randint(0, 255),
                            random.randint(0, 255),
                        ),
                    )
                    countdownIndex = 0
                else:
                    countdownSurface = countdownFont.render(
                        str(countdownNums[countdownIndex]),
                        True,
                        (
                            random.randint(0, 255),
                            random.randint(0, 255),
                            random.randint(0, 255),
                        ),
                    )
        ricardo.update()
        screen.blit(bg, (0, 0))
        for entity in hands:
            screen.blit(entity.images[2], entity.rect)
        screen.blit(ricardo.image, ricardo.rect)
        screen.blit(
            countdownSurface, (int(215 * screen_radio), int(170 * screen_radio))
        )
        pg.display.flip()

    while game_inproccess:
        clock.tick(30)
        num = 0
        generate = False
        for event in pg.event.get():
            if event.type == QUIT:
                highscore.close()
                pg.quit()
                os._exit(0)
            if event.type == KEYUP:
                if event.key == K_1 or event.key == K_KP1:
                    unlocked[0] = True
                elif event.key == K_2 or event.key == K_KP2:
                    unlocked[1] = True
                elif event.key == K_3 or event.key == K_KP3:
                    unlocked[2] = True
            if event.type == MISS:
                for entity in enemies:
                    if entity.jump():
                        entity.image = entity.images[1]
                        if not entity.jumpFinish:
                            unlocked = [False, False, False]
                        else:
                            unlocked = [True, True, True]
                            entity.image = entity.images[0]
            if event.type == TIME:
                if timer.timeCount > 0:
                    timer.update()
                else:
                    game_inproccess = False
                    timeEnd = True
                if timer.timeCount == 3:
                    pg.event.clear(TBCEREND)
                    pg.mixer.music.play()
            if event.type == SCORE:
                scoreboard.score += 1
                scoreboard.update()

        screen.blit(bg, (0, 0))
        pressed_keys = pg.key.get_pressed()
        if (pressed_keys[K_1] or pressed_keys[K_KP1]) and unlocked[0]:
            num = 1
            unlocked[0] = False
        elif (pressed_keys[K_2] or pressed_keys[K_KP2]) and unlocked[1]:
            num = 2
            unlocked[1] = False
        elif (pressed_keys[K_3] or pressed_keys[K_KP3]) and unlocked[2]:
            num = 3
            unlocked[2] = False
        for entity in enemies:
            if entity.check(num):
                break
        if generate:
            new_enemy = enemy(int(-170 * screen_radio))
            enemies.add(new_enemy)
            all_sprites.add(new_enemy)
        for h in hands:
            if h.isSlap:
                if h.count % h.slapHz == 0:
                    h.update()
                h.count += 1
                if h.count >= len(h.images) * h.slapHz:
                    h.isSlap = False
                    h.count = 0
                    h.index = 2
        if moveCount > 0:
            moveCount -= 1
            enemies.update()

        for entity in all_sprites:
            screen.blit(entity.image, entity.rect)
        for board in boards:
            screen.blit(board.text, board.rect)
        pg.display.flip()

    pg.event.clear(TBCEREND)
    while timeEnd:
        clock.tick(30)
        for event in pg.event.get():
            if event.type == QUIT:
                highscore.close()
                pg.quit()
                os._exit(0)
            if event.type == KEYDOWN:
                if event.key == K_SPACE:
                    timeEnd = False
            if event.type == TBCEREND:
                timeEnd = False
        screen.blit(startbg, (0, 0))
        if scoreboard.score > int(high_score):
            newhigh_score = True
            high_score = str(scoreboard.score)
            highscore.seek(0)
            highscore.truncate()
            highscore.write(high_score)
            highscore.seek(0)

        highscoreFont = pg.font.SysFont(fontPath, int(42 * screen_radio), True)
        if newhigh_score:
            highscoreSurface = highscoreFont.render(
                "NEW HIGHSCORE %s !!!" % high_score,
                True,
                (
                    random.randint(0, 255),
                    random.randint(0, 255),
                    random.randint(0, 255),
                ),
            )
            screen.blit(
                highscoreSurface, (int(43 * screen_radio), int(700 * screen_radio))
            )
        else:
            highscoreSurface = highscoreFont.render(
                "HIGHSCORE: %s" % high_score, True, (0, 0, 0)
            )
            screen.blit(
                highscoreSurface, (int(105 * screen_radio), int(700 * screen_radio))
            )
        frogs.update()
        mountainDew.update()
        endScore.update(scoreboard.score)
        screen.blit(endScore.image, (0, 0))
        if scoreboard.score / 100 > 0:
            endScore.rect.left -= int(81 * screen_radio)
            screen.blit(endScore.text, endScore.rect)
            endScore.rect.left += int(81 * screen_radio)
        elif scoreboard.score == 0:
            endScore.rect.left -= int(55 * screen_radio)
            screen.blit(endScore.text, endScore.rect)
            endScore.rect.left += int(55 * screen_radio)
        else:
            screen.blit(endScore.text, endScore.rect)
        for frog in frogs:
            screen.blit(frog.image, frog.rect)
        screen.blit(mountainDew.image, mountainDew.rect)
        pg.display.flip()
highscore.close()
pg.quit()
os._exit(0)
