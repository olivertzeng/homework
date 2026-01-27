t = []
for i in range(3):
    t.append(int(input()))

if len(t) == len(list(dict.fromkeys(t))):
    print(0)
else:
    print(len(t) - len(list(dict.fromkeys(t))) + 1)
