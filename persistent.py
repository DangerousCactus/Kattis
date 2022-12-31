n = int(input())

while(n != -1):
  if(n < 10):
    print(f"1{n}")
  else:
    d = {2 : 0, 3: 0, 5: 0, 7: 0}

    for x in d:
      while(n % x == 0):
        n //= x
        d[x] += 1

    if(n != 1):
      print("There is no such number.")
    else:

      out = d[3] // 2 * "9"
      d[3] %= 2

      out = d[2] // 3 * "8" + out
      d[2] %= 3

      out = d[7] * "7" + out

      if(d[2] >= 1 and d[3] >= 1):
        d[2] -= 1
        d[3] -= 1
        out = "6" + out

      out = d[5] * "5" + out

      if(d[2] == 2):
        out = "4" + out

      if(d[3] == 1):
        out = "3" + out

      if(d[2] == 1):
        out = "2" + out

      print(out)



  n = int(input())