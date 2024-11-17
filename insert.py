import sys
import math

# input functions


def readint(): return int(sys.stdin.readline())


def readints(): return map(int, sys.stdin.readline().split())
def readar(): return list(map(int, sys.stdin.readline().split()))
def flush(): return sys.stdout.flush()


def solve(arr):
    if(len(arr) <= 1):
        return 1

    root = arr.pop(0)
    left = list(filter(lambda x: x < root, arr))
    right = list(filter(lambda x: x >= root, arr))

    c = math.comb(len(left) + len(right), len(left))
    l = solve(left)
    r = solve(right)

    return l * r * c


n = readint()

while n != 0:
    nums = readar()

    print(solve(nums))

    n = readint()
