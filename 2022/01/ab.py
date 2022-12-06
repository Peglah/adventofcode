with open('input.txt', 'r') as file:
  input = file.readlines() # Store values in list

calories = [] # List
elf = 0

for line in input:
  if line == '\n':
    calories.append(int(elf))
    elf = 0
  else:
    elf += int(line)
calories.sort()

print(max(calories)) # Answer 1
print(sum(calories[-3:])) # Answer 2
