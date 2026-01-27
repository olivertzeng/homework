usr = int(input())
t = 0

while usr != 1:
    if usr % 2:
        usr = 3 * usr + 1
    else:
        usr //= 2
    t += 1

print(t)
