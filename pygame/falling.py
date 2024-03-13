import pygame

pygame.init()

gameDisplay = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Ball Dropping")

ball_x = 400
ball_y = 0
direction = 1

clock = pygame.time.Clock()
playing = True
while playing:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            playing = False
    ball_y += 10 * direction
    if ball_y <= 25:
        direction = 1
    elif ball_y >= 575:
        direction = -1
    gameDisplay.fill((0, 0, 0))
    pygame.draw.circle(gameDisplay, (255, 0, 255), (ball_x, ball_y), 25)
    pygame.display.update()
    clock.tick(30)
pygame.quit()
quit()
