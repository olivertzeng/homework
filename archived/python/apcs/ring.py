def hanoi(n, source, target, auxiliary):
    if n == 1:
        print(f"Move ring 1 from {source} to {target}")
        return
    hanoi(n - 1, source, auxiliary, target)
    print(f"Move ring {n} from {source} to {target}")
    hanoi(n - 1, auxiliary, target, source)


if __name__ == "__main__":
    rings = int(input())  # Number of rings
    hanoi(rings, "A", "C", "B")  # A, B and C are names of rods
