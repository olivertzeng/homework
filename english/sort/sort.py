import re

blocklist = ["a", "an", "at", "for", "in", "of", "on", "the", "to"]

with open("phrases.csv", "r") as file:
    lines = file.readlines()

modified_lines = []
index = 1

for line in lines:
    comma_index = line.find(",")

    if comma_index != -1:
        line = line[comma_index + 1 :].lstrip()

    if not (any(line.startswith(e) for e in blocklist) and re.match(r"\(\w+\)", line)):
        line = "3D " + line

lines = sorted(lines, key=lambda x: x.split()[1])
for line in lines:
    line.replace("3D ", "")
    line = str(index) + ", " + line
    index += 1

with open("sorted.csv", "w") as file:
    file.writelines(lines)
