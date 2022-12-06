f = open("/storage/emulated/0/Download/input.txt", "r")
s1 = 0
s2 = 0

def find_nth(string, substring, n):
   if (n == 1):
       return string.find(substring)
   else:
       return string.find(substring, find_nth(string, substring, n - 1) + 1)

"""
[C]         [S] [H]                
[F] [B]     [C] [S]     [W]        
[B] [W]     [W] [M] [S] [B]        
[L] [H] [G] [L] [P] [F] [Q]        
[D] [P] [J] [F] [T] [G] [M] [T]    
[P] [G] [B] [N] [L] [W] [P] [W] [R]
[Z] [V] [W] [J] [J] [C] [T] [S] [C]
[S] [N] [F] [G] [W] [B] [H] [F] [N]
 1   2   3   4   5   6   7   8   9 
"""
 
piles = [['S','Z','P','D','L','B','F','C'],['N','V','G','P','H','W','B'],['F','W','B','J','G'],['G','J','N','F','L','W','C','S'],['W','J','L','T','P','M','S','H'],['B','C','W','G','F','S'],['H','T','P','M','Q','B','W'],['F','S','W','T'],['N','C','R']]
piles2 = [['S','Z','P','D','L','B','F','C'],['N','V','G','P','H','W','B'],['F','W','B','J','G'],['G','J','N','F','L','W','C','S'],['W','J','L','T','P','M','S','H'],['B','C','W','G','F','S'],['H','T','P','M','Q','B','W'],['F','S','W','T'],['N','C','R']]
tmp = []


f.seek(325)

for line in f:
  loop = line[find_nth(line, ' ', 1):find_nth(line, ' ', 2)]
  loop = int(loop)
  loop2 = loop
  
  frm = line[find_nth(line, ' ', 3):find_nth(line, ' ', 4)]
  frm = int(frm)-1
  
  to = line[find_nth(line, ' ', 5):]
  to = int(to)-1
  
  # s1
  while loop > 0:
    piles[to].append(piles[frm].pop())
    loop -= 1
    
  # s2
  while loop2 > 0:
    tmp.append(piles2[frm].pop())
    loop2 -= 1
  while len(tmp) > 0:
    piles2[to].append(tmp.pop())
    
f.close()


print('Part 1: ', end = '')
for x in piles:
  print(x.pop(), end = '')

print()
print('Part 2: ', end = '')
for x in piles2:
  print(x.pop(), end = '')
