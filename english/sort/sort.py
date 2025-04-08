import csv
import re

# Define constants
BLOCKED_WORDS = [
    "a",
    "about",
    "an",
    "at",
    "be",
    "for",
    "in",
    "of",
    "on",
    "one",
    "one's",
    "oneself",
    "the",
    "to",
]
BLOCK_LABEL = "峀"
NEWLINE_LABEL = "甭"
PARENTHESIS_LABEL = "刂"


def is_main_line(line):
    """Check if a line is a main line (starts with a number + ',')."""
    return re.match(r"^\d+,", line)


def group_lines(lines):
    result = []
    main_line = None
    for line in lines:
        if is_main_line(line):
            if main_line:
                result.append(main_line)
            main_line = line
        else:
            if main_line:
                main_line += NEWLINE_LABEL + line
    if main_line:
        result.append(main_line)
    for i, line in enumerate(result):
        result[i] = line[line.index(",") + 1 :]
    return result


def block_lines(lines):
    """Add block labels until the nth word isn't blocked."""
    n = 0
    for i, line in enumerate(lines):
        """Group parenthesis into a single word(setup)"""
        if "(" in line and ")" in line:
            # find the substring within the parenthesis
            start_idx = line.find("(")
            end_idx = line.find(")")

            # replace extra spaces within the parenthesis
            substring = re.sub(r"\s+", PARENTHESIS_LABEL, line[start_idx + 1 : end_idx])

            # replace the original substring with the modified one
            lines[i] = line[: start_idx + 1] + substring + line[end_idx:]
    while True:
        """the main proccess"""
        allBlocked = True
        for i, line in enumerate(lines):
            words = line.split()
            if words[n] in BLOCKED_WORDS or re.search(r"\([^)]*\)", words[n]):
                allBlocked = False
                break
        if allBlocked:
            break
        for i, line in enumerate(lines):
            words = line.split()
            if not (words[n] in BLOCKED_WORDS or re.search(r"\([^)]*\)", words[n])):
                lines[i] = BLOCK_LABEL + " " + line
        n += 1
    print(n)
    return n, lines


def label_lines(lines):
    """Add line numbers to each line."""
    return [f"{i+1}, {line}" for i, line in enumerate(lines)]


def restore_lines(lines):
    """Remove labels"""
    result = []
    for line in lines:
        line = line.replace(BLOCK_LABEL, "")
        line = line.replace(PARENTHESIS_LABEL, " ")
        line = line.replace(NEWLINE_LABEL, "\n")
    return result


def write_to_file(filename, lines):
    """Write the given lines to a new csv file."""
    with open(filename, "w", newline="") as f_out:
        for line in lines:
            f_out.write(line + "\n")
    print(f"Lines written to {filename}")


def process_file(input_file, output_file):
    """Process the input file and write to the output file."""
    with open(input_file, "r") as f_in:
        reader = csv.reader(f_in)
        next(reader)  # Skip the first line
        print("now cleaning")
        lines = [[cell.strip() for cell in row] for row in reader]
        lines = [",".join(row) for row in lines]
        print("cleaning complete")
        write_to_file("cleaned.csv", lines)

        print("now grouping")
        lines = group_lines(lines)
        print("grouping complete")
        write_to_file("grouped.csv", lines)

        print("now blocking")
        n, lines = block_lines(lines)
        print("blocking complete")
        write_to_file("blocked.csv", lines)

        print("now sorting")
        lines = sorted(lines, key=lambda x: x.split()[n])
        print("sorting complete")
        write_to_file("sorted.csv", lines)

        print("now labeling")
        lines = label_lines(lines)
        print("labeling complete")
        write_to_file("labeled.csv", lines)

        print("now restoring")
        lines = restore_lines(lines)
        print("restoring complete")
        write_to_file(output_file, lines)


process_file("phrases.csv", "output.csv")
