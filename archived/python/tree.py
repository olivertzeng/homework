import os

def generate_ascii_tree(height):
    for i in range(height):
        # Print the branches
        for j in range(height - i - 1):
            print(" ", end="")
        for j in range(2 * i + 1):
            print("󰐅", end="" if j < 2 * i else "\n")

    # Print the trunk
    for i in range(height // 2):
        for j in range(height - 1):
            print(" ", end="")
        print("█")

user = int(os.popen("gum input --prompt ' ' --placeholder '請輸入樹的層數'").read())
generate_ascii_tree(user)
