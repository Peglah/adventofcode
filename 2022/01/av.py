f = open("/storage/emulated/0/Download/input.txt", "r")
h0 = 0
h1 = 0
h2 = 0
tmp = 0

# h0
for x in f:
  if x == "\n":
    if tmp > h0:
      h0 = tmp
    tmp = 0
  else:
    tmp = tmp + int(x)
if tmp > h0:
  h0 = tmp
tmp = 0
f.seek(0)

# h1
for x in f:
  if x == "\n":
    if tmp > h1 and tmp != h0:
      h1 = tmp
    tmp = 0
  else:
    tmp = tmp + int(x)
if tmp > h1 and tmp != h0:
  h1 = tmp
tmp = 0
f.seek(0)

# h2
for x in f:
  if x == "\n":
    if tmp > h2 and tmp != h1 and tmp != h0:
      h2 = tmp
    tmp = 0
  else:
    tmp = tmp + int(x)
if tmp > h2 and tmp != h1 and tmp != h0:
  h2 = tmp
tmp = 0

f.close()
print("H0: ", h0)
print("H1: ", h1)
print("H2: ", h2)
print("Sum: ", h0+h1+h2)
