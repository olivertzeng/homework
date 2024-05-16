height = int(input())
width = int(input())
needed = int(input())

if not (needed % height and needed % width) and needed <= width * height:
    print("YES")
else:
    print("NO")
