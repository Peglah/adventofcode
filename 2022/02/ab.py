file = open("/storage/emulated/0/Download/input.txt", "r")
s1 = 0
s2 = 0

for line in file:
  # 1, 2, 3
  opponent = ord(line[0])-64
  # 5, 6, 7
  response = ord(line[2])-83
  outcome = opponent * response
  
  # s1 response score
  s1 += response-4
  
  # s1 outcome score
  #
  # win , 6, 14, 15
  # draw, 5, 12, 21
  # loss, 7, 10, 18
  if(outcome == 5 or outcome == 12 or outcome == 21):
    s1 += 3
  elif(outcome == 6 or outcome == 14 or outcome == 15):
    s1 += 6
  
  #s2 outcome score
  s2 += (response-5)*3
  
  # s2 response score
  # 
  # rock, 6, 10, 21
  # paper, 7, 12, 15
  # scissors, 5, 14, 18
  
  if(outcome == 6 or outcome == 10 or outcome == 21):
    s2 += 1
  elif(outcome == 7 or outcome == 12 or outcome == 15):
    s2 += 2
  else:
    s2 += 3

file.close()
print("Score1: ", s1)
print('Score2: ', s2)
