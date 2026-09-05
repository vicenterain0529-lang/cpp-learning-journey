import random

dice = {
    1: """
+-------+
|       |
|   ●   |
|       |
+-------+
""",
    2: """
+-------+
| ●     |
|       |
|     ● |
+-------+
""",
    3: """
+-------+
| ●     |
|   ●   |
|     ● |
+-------+
""",
    4: """
+-------+
| ●   ● |
|       |
| ●   ● |
+-------+
""",
    5: """
+-------+
| ●   ● |
|   ●   |
| ●   ● |
+-------+
""",
    6: """
+-------+
| ●   ● |
| ●   ● |
| ●   ● |
+-------+
"""
}


num_dices =int(input('How many dice roll? '))
big_dice = []
total = 0
all_list = []


for die in  range(num_dices):
    big_dice.append(random.randint(1, 6))

print(big_dice)

for die in big_dice:
    total += die
print(f'Total: {total}')

for item in big_dice:
    all_list.append(dice[item].strip().splitlines())

for row in range(len(all_list[0])):
    for die in all_list:
        print(die[row], end= " ")
    print()