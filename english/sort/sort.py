import csv
import pathlib
import re

# Define constants
BLOCKED = [
    "N",
    "Ving",
    "a",
    "about",
    "an",
    "and",
    "at",
    "be",
    "by",
    "for",
    "in",
    "it",
    "itself",
    "of",
    "on",
    "one",
    "one's",
    "oneself",
    "out",
    "sb",
    "sth",
    "the",
    "to",
    "up",
    "with",
]
UNBLOCKED = [
    "by oneself",
    "in itself",
    "one another",
    "one by one",
    "one on one",
    "up to N",
    "up to",
]
BLOCK_LABEL = "峀"
NEWLINE_LABEL = "甭"
PARENTHESIS_LABEL = "刂"


def isMain(l):
    """Check if a line is a main line (starts with a number + ',')."""
    return re.match(r"^\d+,", l)


def blocked(l, n):
    noUnblock = l.split()[n] in BLOCKED or re.search(r"\([^)]*\)", l.split()[n])
    return not (l[: l.index(",")] in UNBLOCKED) and noUnblock


def group(lines):
    result = []
    mainLine = None
    for l in lines:
        if isMain(l):
            if mainLine:
                result.append(mainLine)
            mainLine = l
        else:
            if mainLine:
                mainLine += NEWLINE_LABEL + l
    if mainLine:
        result.append(mainLine)
    for i, l in enumerate(result):
        result[i] = l[l.index(",") + 1 :]
    return result


def block(lines):
    """Add block labels until the nth word isn't blocked."""
    n = 0
    for i, l in enumerate(lines):
        """Group parenthesis into a single word(setup)"""
        if "(" in l and ")" in l:
            # find the substring within the parenthesis
            start_idx = l.find("(")
            end_idx = l.find(")")

            # replace extra spaces within the parenthesis
            substring = re.sub(r"\s+", PARENTHESIS_LABEL, l[start_idx + 1 : end_idx])

            # replace the original substring with the modified one
            lines[i] = l[: start_idx + 1] + substring + l[end_idx:]
    while True:
        """the main proccess"""
        allBlocked = True
        for i, l in enumerate(lines):
            if blocked(l, n):
                allBlocked = False
                break
        if allBlocked:
            break
        for i, l in enumerate(lines):
            if not blocked(l, n):
                lines[i] = BLOCK_LABEL + " " + l
        n += 1
    print("iterated " + str(n) + " times")
    return n, lines


def label(lines):
    """Add line numbers to each line."""
    return [f"{i+1},{l}" for i, l in enumerate(lines)]


def restore(lines):
    """Remove labels"""
    result = []
    for l in lines:
        l = l.replace(BLOCK_LABEL + " ", "")
        l = l.replace(PARENTHESIS_LABEL, " ")
        l = l.replace(NEWLINE_LABEL, "\n")
        result.append(l)
    return result


def write_to_file(filename, lines):
    """Write the given lines to a new csv file."""
    with open(filename, "w", newline="") as f_out:
        for l in lines:
            f_out.write(l + "\n")
    print(f"Lines written to {filename}")


def process_file(input_file, output_file):
    """Process the input file and write to the output file."""
    with open(input_file, "r") as f_in:
        reader = csv.reader(f_in)
        next(reader)  # Skip the first line
        pathlib.Path("debug").mkdir(exist_ok=True)
        print("now cleaning")
        lines = [[cell.strip() for cell in row] for row in reader]
        lines = [",".join(row) for row in lines]
        print("cleaning complete")
        write_to_file("debug/cleaned.csv", lines)

        print("now grouping")
        lines = group(lines)
        print("grouping complete")
        write_to_file("debug/grouped.csv", lines)

        print("now blocking")
        n, lines = block(lines)
        print("blocking complete")
        write_to_file("debug/blocked.csv", lines)

        print("now sorting")
        lines = sorted(lines, key=lambda x: x.split()[n])
        print("sorting complete")
        write_to_file("debug/sorted.csv", lines)

        print("now labeling")
        lines = label(lines)
        print("labeling complete")
        write_to_file("debug/labeled.csv", lines)

        print("now restoring")
        lines = restore(lines)
        print("restoring complete")
        write_to_file(output_file, lines)


process_file("phrases.csv", "output.csv")
