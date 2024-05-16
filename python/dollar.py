dollar = int(input())
cents = int(input())
quantity = int(input())
print(dollar * quantity + cents * quantity // 100, cents * quantity % 100)
