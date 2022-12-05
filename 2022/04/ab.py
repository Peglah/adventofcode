f = open("/storage/emulated/0/Download/input.txt", "r")
s1 = 0
s2 = 0

for line in f:
  L1H1 = line[:line.find(',')]
  L1 = int(L1H1[:L1H1.find('-')])
  H1 = int(L1H1[L1H1.find('-')+1:])
  
  L2H2 = line[line.find(',')+1:]
  L2 = int(L2H2[:L2H2.find('-')])
  H2 = int(L2H2[L2H2.find('-')+1:])
  
  # s1
  if(L1 >= L2 and H1 <= H2):
    s1 += 1
  elif(L1 <= L2 and H1 >= H2):
    s1 += 1
  
  # s2
  if((L1 >= L2 and L1 <= H2) or (H1 >= L2 and H1 <= H2)):
    s2 += 1
  elif((L2 >= L1 and L2 <= H1) or (H2 >= L1 and H2 <= H1)):
    s2 += 1

f.close()
print('Sum1: ', s1)
print('Sum2: ', s2)
