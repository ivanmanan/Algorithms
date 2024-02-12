import heapq

###############################################################################
# Last Stone Weight
def lastStoneWeight(self, stones: List[int]) -> int:
    maxheap = []
    for stone in stones:
        heapq.heappush(maxheap, -stone)

    while maxheap:
        bigstone = -1 * heapq.heappop(maxheap)
        if maxheap:
            smallstone = -1 * heapq.heappop(maxheap)
            heapq.heappush(maxheap, -1 * (bigstone-smallstone))
        else:
            return bigstone
    return -1

###############################################################################
# Fibonnaci Numbers
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

def fibentry():
    myfib = FibObject(10)
    for fib in myfib:
        print(fib)
    return 0

###############################################################################
# Bubble Sort
from typing import List

def bubbleSort(nums: List[int]) -> None:
    size = len(nums)
    for i in range(size):
        for j in range(i+1, size):
            if nums[i] > nums[j]:
                nums[i], nums[j] = nums[j], nums[i] # swap


if __name__ == "__main__":
    nums = [4, 9, 2, 3, 1, 8, 5, 7, 6]
    bubbleSort(nums)
    for num in nums:
        print(num)
