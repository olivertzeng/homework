batting_average = float(input())
home_run_cycle = float(input())
run_batted_in = float(input())
total_bases = float(input())

total = 1000 * batting_average + 20 * home_run_cycle + 5 * run_batted_in + total_bases


def bruh(t):
    if t >= 1500:
        return "超強者"
    elif t >= 800:
        return "高手"
    elif t >= 500:
        return "普通"
    else:
        return "再努力"


print(total, bruh(total))
