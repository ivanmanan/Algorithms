#!/usr/bin/python3
"""
Python Cheat Sheet
"""

import math
import sys
import threading


def parallel_programming():
    t1 = threading.Thread(target=func1)
    t2 = threading.Thread(target=func2)
    t1.start()
    t2.start()
    t1.join()
    t2.join()



def variables_and_conditionals():
    # Variable types are determined at runtime (dynamically typed)
    n = 0
    print("n =", n)
    n = "abc"
    print("n =", n)
    # n changed from int to string

    # Multiple assignments
    m, n = 0, "abc"

    # None is null
    if m is not None:
        print("m is not none.")
    elif m is None:
        print("m is none.")
    else:
        print("Won't reach here.")

    if n == "abc" and m >= 0 or m < 0:
        print("n == abc and m >= 0 or m < 0")

def loops():
    n = 0
    while n < 5:
        print(n)
        n += 1

    print("Loop i=0 to i=4:")
    for i in range(5):
        # i is incremented implicitly
        print(i)
    print("Loop i=2 to i=5:")
    for i in range(2,6):
        print(i)
    print("Loop i=5 to i=2:")
    for i in range(5, 1, -1):
        print(i)

def python_math():
    # Division is decimal by default
    print(5/2)
    # Double slash rounds down
    print(5//2)

    # Negative values will round down instead of towards 0
    print(-3//2)

    # Workaround to round towards zero is divide then typecast to int
    print(int(-3/2))

    x=5
    print(type(x)) # int
    print(type(x/2)) # float

    print(10%3) # Answer: 1
    print(-10%3) # Answer: 2
    # To get 1, import math and do math.fmod(-10,3)

    print(math.floor(3/2))
    print(math.ceil(3/2))
    print(math.sqrt(2))
    print(math.pow(2,3))

    # Python numbers are infinite so they never overflow
    print(float("inf")) # MAX_INT
    print(float("-inf")) # MIN_INT
    # This large number is less than infinity
    print(math.pow(2,200) < float("inf"))

def arrays():
    # Arrays are lists in Python

    arr = [1, 2, 3]
    print(arr)

    # Can be used as a stack
    arr.append(4)
    arr.append(5)
    print(arr)

    # Insert 7 into index 2
    arr.insert(1,7) # Time: O(N) operation
    print(arr)

    arr[0] = 0
    arr[3] = 0
    print(arr)

    # Index -1 is the last value and is not out of bounds
    print(arr[-1])
    print(arr[-2]) # Prints 2nd to last value
    # print(arr[100]) --> Throws error

    # Set array of size n with default value 1
    n = 3
    arr = [1] * n
    print(arr)
    print(len(arr))

    # Sublists (slicing)
    arr = [1, 2, 3, 4]
    print(arr[1:3]) # Print index 1, index 2

    # Unpacking
    a, b, c = [1,2,3]
    print(a,b,c)

    nums = [1,2,3]
    # With indexes
    for i in range(len(nums)):
        print(nums[i])

    # Without indexes
    for n in nums:
        print(n)

    # With indexes
    for i, n in enumerate(nums):
        print(i, n)

    # Loop multiple arrays with unpacking
    nums1 = [1, 3, 5]
    nums2 = [2, 4, 6]
    for n1, n2 in zip(nums1, nums2):
        print(n1,n2)

    # Reverse
    nums = [1, 2, 3]
    nums.reverse()
    print(nums)

    # Sort
    arr = [5, 4, 7, 3, 8]
    arr.sort()
    print(arr)

    arr.sort(reverse=True)
    print(arr)

    # Custom sort by length of string
    arr = ["bob", "alice", "jane", "doe"]
    arr.sort(key=lambda x: len(x))
    print(arr)

    # List comprehension
    arr = [i+i for i in range(5)]
    # for each element, add 2 times the index
    print(arr)

    # 2-D lists
    # [0]*4 --> Create one array of size 4 with all 0s
    # We want the row generated four times
    arr = [[i] * 4 for i in range(4)]
    print(arr)

    # Strings are similar to arrays
    # However, strings are immutable
    s = "abc"
    print(s[0:2])
    # This won't work
    # s[0] = "A"


def main():

    # variables_and_conditionals()
    # loops()
    # python_math()

    arrays()

    return 0




if __name__ == "__main__":
    sys.exit(main())
