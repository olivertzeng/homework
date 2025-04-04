import re


def clean_lines(lines):
    """Remove extra whitespaces from each line."""
    return [re.sub(" +", " ", line) for line in lines]


def group_lines(lines):
    """Group sub-lines with main-lines and add newline labels."""
    lines = [line for line in lines if line]  # Remove empty lines
    main_lines = [line for line in lines if re.match(r"\d+,", line)]
    sub_lines = [line for line in lines if not re.match(r"\d+,", line)]

    # Pair sub-lines with main-lines
    grouped_lines = []
    sub_index = 0
    for main_line in main_lines:
        sub_group = []
        while sub_index < len(sub_lines) and not re.match(
            r"\d+,", sub_lines[sub_index]
        ):
            sub_line = sub_lines[sub_index]
            sub_index += 1
            sub_line = "NEWLINE " + sub_line
            sub_group.append(sub_line)
        grouped_lines.append(main_line + " " + " ".join(sub_group))

    return grouped_lines


def block_lines(lines, block_list):
    """Add block labels until all (n+1)th words are not blocked."""
    n = 1
    max_iterations = 100  # prevent infinite loop
    iteration = 0
    while iteration < max_iterations:
        new_lines = []
        allBlocked = True
        block_list_set = set(block_list)
        for line in lines:
            words = line.split()
            if n <= len(words) and words[n - 1] not in block_list_set:
                new_lines.append("BLOCK " + line)
                allBlocked = False
            else:
                new_lines.append(line)
        if allBlocked or n > len(max(lines, key=lambda x: len(x.split())).split()):
            break
        lines = new_lines
        n += 1
        iteration += 1

    # Ensure that lines do not have 'BLOCK' at the beginning if the first word is not a number
    lines = [line[6:] if not re.match(r"\d+,", line[6:]) else line for line in lines]
    return lines, n


def sort_lines(lines, n):
    """Sort lines based on the nth word."""
    return sorted(lines, key=lambda line: line.split()[n - 1])


def label_lines(lines):
    """Add line numbers to each line."""
    return [f"{i+1}, {line}" for i, line in enumerate(lines)]


def restore_lines(lines):
    """Make a new line before each label and remove newline and block
    labels."""
    output_lines = []
    for line in lines:
        words = line.split()
        new_lines = []
        for word in words:
            if word == "NEWLINE":
                output_lines.append(" ".join(new_lines))
                new_lines = []
            elif word == "BLOCK":
                continue
            else:
                new_lines.append(word)
        output_lines.append(" ".join(new_lines))
    return output_lines


def main():
    # Read input file
    with open("phrases.cs", "r") as file:
        lines = file.readlines()

    block_list = ["Hello", "Foo"]

    lines = lines[1:]  # Ignore first line
    lines = [line.strip() for line in lines]
    lines = clean_lines(lines)
    lines = group_lines(lines)
    lines, n = block_lines(lines, block_list)
    lines = sort_lines(lines, n)
    lines = label_lines(lines)
    lines = restore_lines(lines)

    # Write to output file
    with open("output.txt", "w") as file:
        for line in lines:
            file.write(line + "\n")


if __name__ == "__main__":
    main()
