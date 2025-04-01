with open("phrases.md", "r") as file:
    lines = file.readlines()

modified_lines = []
for line in lines:
    stripped_line = line.lstrip()
    if not stripped_line.lower().startswith(("a", "an", "the")):
        modified_lines.append("3D " + line)
    else:
        modified_lines.append(line)
# Sort the lines based on the second word of each line
sorted_lines = sorted(modified_lines, key=lambda line: line.split()[1])

with open("sorted.md", "w") as file:
    file.writelines(sorted_lines)
