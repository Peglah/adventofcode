def find_nth(string, substring, n):
   if (n == 1):
       return string.find(substring)
   else:
       return string.find(substring, find_nth(string, substring, n - 1) + 1)

f = open('input.txt', 'r')

s1 = 0
s2 = 0

for line in f:
    sides = [int(line[:find_nth(line, 'x', 1)]), int(line[find_nth(line, 'x', 1)+1:find_nth(line, 'x', 2)]), int(line[find_nth(line, 'x', 2)+1:])]

    # s1
    areas = [sides[0] * sides[1] * 2, sides[2] * sides[1] * 2, sides[0] * sides[2] * 2]
    s1 += int(sum(areas) + min(areas) / 2)

    # s2
    sides.sort()
    s2 += sides[0] * 2 + sides[1] * 2 + sides[0] * sides[1] * sides[2]

print('Sum1: ', s1)
print('Sum2: ', s2)
