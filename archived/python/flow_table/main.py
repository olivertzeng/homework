with open("src/table.txt") as infile:
    data = infile.readline()

print(data[0])

for row in data:
    print(row)
