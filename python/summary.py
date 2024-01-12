#!/usr/bin/python3

from collections import deque
import heapq
import sys

def hashsets():
    myset = set()
    myset.add(1)
    myset.add(2)
    print(myset)
    print(1 in myset)
    print(3 in myset)

    # list to set
    print(set([1,2,3]))
    # set comprehension
    myset = {i for i in range(5)}
    print(myset)

def hashmaps():
    mymap = {}
    mymap["key1"] = 100
    mymap["key2"] = 150
    print(mymap)
    print("key1" in mymap)
    mymap.pop("key1")
    print(mymap)

    # Dict comprehension
    mymap = {i: 2*i for i in range(3)}
    print(mymap)

    # Looping maps
    for key in mymap:
        print(key, mymap[key])

    # If we don't need key
    for val in mymap.values():
        print(val)

    for key,val in mymap.items():
        print(key, val)

def stack():
    st = []
    st.append("a")
    st.append("b")
    st.append("c")
    print(st)

    # Containers are true when not empty
    # Containers are false when empty
    while st:
        print(st.pop())

def queue():
    """
    Queues are double ended
    """
    q = deque()
    q.append(1)
    q.append(2)
    print(q)

    q.popleft()
    q.appendleft(1)
    q.pop()
    print(q)

def tuples():
    """
    Tuples are like arrays but are immutable (cannot modify)
    Mainly use tuples for keys in hash maps

    Lists are not hashable and cannot be keys in hash maps
    """
    tup = (1, 2, 3)
    print(tup)
    mymap = {
        (1,2): 3
    }
    print(mymap)
    myset = set()
    myset.add((1,2))
    print((1,2) in myset)

def heaps():
    """
    Under the hood, heaps are arrays
    By default, heaps are min heaps in Python

    Minimum element is always at index 0
    """
    minheap = []
    heapq.heappush(minheap, 3)
    heapq.heappush(minheap, 1)
    heapq.heappush(minheap, 6)

    while len(minheap):
        print(heapq.heappop(minheap))

    # Python does not have max heaps by default
    # Work around is to multiply by -1 when push and pop

    maxheap = []
    heapq.heappush(maxheap, -3)
    heapq.heappush(maxheap, -1)
    heapq.heappush(maxheap, -4)

    while len(maxheap):
        print(-1 * heapq.heappop(maxheap))

    # Build heap from initial values
    arr = [2, 1, 8, 4, 5]
    heapq.heapify(arr)
    print(arr)

def nested_function(a, b):
    """
    Nested functions have access to outer variables
    """
    c = "c"

    def inner():
        return a + b + c
    print(inner())


def main():
    # stack()
    # queue()
    # hashsets()
    # hashmaps()
    # tuples()
    # heaps()

    # FUNCTIONS GUIDE
    nested_function(a="a", b="b")
    return 0

if __name__ == "__main__":
    sys.exit(main())
