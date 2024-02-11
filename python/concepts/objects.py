#!/usr/bin/python3

import sys

"""
Generic object
"""
class MyClass:
    # Constructor
    def __init__(self, nums):
        self.nums = nums
        self.size = len(nums)

    def getlength(self):
        return self.size

    def getdoublelength(self):
        return 2 * self.getlength()

# Inheritance
class ChildClass(MyClass):
    def getlength(self):
        return 500

"""
Iterator object
"""
class FibObject:
    def __init__(self, max):
        self.max = max

    def __iter__(self):
        self.a = 0
        self.b = 1
        return self

    def __next__(self):
        fib = self.a
        if fib > self.max:
            raise StopIteration

        temp = self.a
        self.a = self.b
        self.b = temp + self.b

        return fib

"""
Generator function
A type of iterator. They allow you to iterate over a potentially infinite sequence of items
without creating the entire sequence in memory at once.

Example: perform a search query in Elasticsearch. Iterate each document one-by-one.
The documents are fetched in batches, allowing you to work with the data incrementally
rather than loading the entire result set into memory.
"""
def square_generator(n):
    for i in range(n):
        yield i ** 2 # equivalent to math.pow(i,2)

"""
With statement
e.g.: with open(file_name) as f:
"""
class MyObject:
    def __enter__(self):
        # Code to set up the resource or perform any necessary actions
        print("Entering the 'with' block")
        return self  # You can return the object itself or any other object you want to use within the 'with' block

    def __exit__(self, exc_type, exc_value, traceback):
        # Code to clean up resources or handle exceptions
        print("Exiting the 'with' block")

    def some_method(self):
        print("Doing something with MyObject")



def main():
    # arr = [1, 3, 6, 9, 14]
    # myclass = MyClass(arr)
    # print(myclass.getlength())

    # myfib = FibObject(10)
    # for fib in myfib:
    #     print(fib)

    # for num in square_generator(100):
    #     print(num)

    # Manually iterate
    # gen = square_generator(3)
    # print(next(gen))  # Output: 0
    # print(next(gen))  # Output: 1
    # print(next(gen))  # Output: 4

    # Example usage:
    with MyObject() as obj:
        obj.some_method()
    # The __exit__ method will be called automatic

    return 0

if __name__ == "__main__":
    sys.exit(main())
