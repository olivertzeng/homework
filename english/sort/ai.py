import csv
import re

# Define constants
BLOCKED_WORDS = ["a", "an", "at", "be", "for", "in", "of", "on", "the", "to"]
NEWLINE_LABEL = "甭"
BLOCK_LABEL = "峀"


def clean_line(line):
    """Remove extra whitespaces from a line."""
    return line.strip()


def is_main_line(line):
    """Check if a line is a main line (starts with a number + ',')."""
    return re.match(r"^\d+,", line)


def group_lines(lines):
    """Group sub-lines with main lines."""
    result = []
    main_line = None
    for line in lines:
        if is_main_line(line):
            if main_line:
                result.append(main_line)
            main_line = line
        elif main_line:
            main_line += " " + NEWLINE_LABEL + " " + line
        else:
            main_line = NEWLINE_LABEL + " " + line
    if main_line:
        result.append(main_line)
    return result


def block_lines(lines):
    """Add block labels until n+1th word isn't blocked."""
    n = 1
    while True:
        all_blocked = True
        for i, line in enumerate(lines):
            words = line.split()
            if words[n] in BLOCKED_WORDS or re.match(r"\(\w+\)", line):
                all_blocked = False
                lines[i] += " " + BLOCK_LABEL
        if all_blocked:
            break
        n += 1
    return lines


def sort_lines(lines):
    """Sort lines based on the nth word."""
    n = 1
    while True:
        words = [line.split()[n] for line in lines if n < len(line.split())]
        if words:
            lines.sort(key=lambda x: x.split()[n] if n < len(x.split()) else "")
            n += 1
        else:
            break
    return lines


def label_lines(lines):
    """Add line numbers to each line."""
    return [f"{i+1}, {line}" for i, line in enumerate(lines)]


def restore_lines(lines):
    """Remove newline labels and block labels."""
    result = []
    for line in lines:
        line = line.replace(NEWLINE_LABEL, "")
        line = line.replace(BLOCK_LABEL, "")
        while "," in line:
            line = line[: line.index(",")]
        result.append(line.strip())
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
        lines = [clean_line(line[0]) for line in reader]
        print("cleaning complete")
        write_to_file("cleaned.csv", lines)

        print("now grouping")
        lines = group_lines(lines)
        print("grouping complete")
        write_to_file("grouped.csv", lines)

        print("now blocking")
        lines = block_lines(lines)
        print("blocking complete")
        write_to_file("blocked.csv", lines)

        print("now sorting")
        lines = sort_lines(lines)
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
