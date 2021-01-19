from cs50 import get_float


change = -1
q = d = n = p = 0

while change < 0:
    change = get_float("Change owed: ") * 100

q = int(change / 25) if change // 25 >= 1 else 0
change -= q * 25

d = int(change/10) if change // 10 >= 1 else 0
change -= d * 10

n = int(change / 5) if change // 5 >= 1 else 0
change -= n * 5

p = change if change // 1 >= 1 else 0
change -= p * 1

print(int(q + d + n + p))

