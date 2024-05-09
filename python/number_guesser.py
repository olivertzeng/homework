import random

ans = random.randint(1, 10000)
times = 1
user = int(input())
while user != ans:
    if user > ans:
        print("😢 too big")
    else:
        print("😢 too small")
    user = int(input())
    times += 1
    # break

print("😃 you guessed", times)
