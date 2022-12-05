f = open("/storage/emulated/0/Download/input.txt", "r")
s1 = 0
s2 = 0

# s1
for line in f:
  fst = line[:int(len(line)/2)]
  sec = line[int(len(line)/2):]
  
  for c in fst:
    for d in sec:
      if c == d:
        cd = ord(c)
  if(cd >= 97):
    s1 += cd - 96
  else:
    s1 += cd - 38
f.seek(0)

#s2
while True:
  elf1 = f.readline()
  elf2 = f.readline()
  elf3 = f.readline()
  if not elf3: break  # EOF
  
  for c in elf1:
    for d in elf2:
      for e in elf3:
        if(c == d and d == e and c != '\n'):
          cd = ord(c)
          
  if(cd >= 97):
    s2 += cd - 96
  elif(cd <= 90):
    s2 += cd - 38

f.close()
print('Sum1: ', s1)
print('Sum2: ', s2)
