N = int(input())
data = []
for i in range(N):
    a = int(input())
    b = int(input())
    data.append(abs(a - b))

data.sort(reverse=True)
print(data[0])
