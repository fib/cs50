import cs50

x = 0
while x < 1 or x == 9:
    x = cs50.get_int("Height: ")

for i in range(1, x + 1):
    print(f"{' ' * (x - i)}{'#' * i}  {'#' * i}")

