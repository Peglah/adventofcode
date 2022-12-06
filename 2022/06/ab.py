with open('input.txt', 'r') as file:
  input = file.read() # Store values in list

  pos = 4
  while pos < len(input)-4:
    if len(set(input[pos-4:pos])) == 4:
      print(pos)
      break
    pos += 1

  pos = 14
  while pos < len(input)-14:
    if len(set(input[pos-14:pos])) == 14:
      print(pos)
      break
    pos += 1
