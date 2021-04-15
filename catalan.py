nums = [1]
for i in range(1, 5005):
  nums.append((4*i - 2) * (nums[-1]) // (i + 1))

n = int(input())

for i in range(n):
  x = int(input())
  print(nums[x])

