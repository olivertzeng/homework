N = int(input("Entries? "))

if N:
    for i in range(N):
        print("第", i + 1, "場")
        attempt = int(input("請出入投籃次數 "))
        if attempt:
            made = int(input("請輸入命中次數 "))
            print("投籃命中率=", round(made / attempt * 100, 1), "%")
