#!/bin/python3

import threading

# Use "threading.Lock()" to specify timeout
# Avoid deadlocks in Python: Ensure that locks are acquired in a consistent order across all
#                            threads or processes. By enforcing a global order for acquiring
#                            locks, you can reduce the likelihood of circular waits, which is
#                            a common cause of deadlocks.

def func1():
    for i in range(-1, -100, -1):
        # Iterate from [-1,-99), decrementing by 1
        print(i)

def func2():
    for i in range(1, 100, 1):
        print(i)

def parallel_programming():
    t1 = threading.Thread(target=func1)
    t2 = threading.Thread(target=func2)
    t1.start() # start thread 1
    t2.start() # start thread 2
    t1.join() # pause and wait for thread 1 to finish
    t2.join() # pause nad wait for thread 2 to finish



"""
Coroutines are computer program components that allow execution to be suspended and resumed
--> Generalizes subroutines (AKA functions) for cooperative multitasking

Coroutines declared with the async/await syntax is the preferred way
of writing asyncio applications.
"""
import asyncio
import time
async def mycoroutine():
    print('hello')
    await asyncio.sleep(1)
    print('world')

# NOTE: Simply calling mycoroutine() will not schedule it to be executed
asyncio.run(mycoroutine())


"""
The following snippet of code will print “hello” after waiting for 1 second,
and then print “world” after waiting for another 2 seconds.

This runs sequentially and takes 3 seconds
"""
async def say_after(delay, what):
    await asyncio.sleep(delay)
    print(what)

async def main():
    print(f"started at {time.strftime('%X')}")

    await say_after(1, 'hello')
    await say_after(2, 'world')

    print(f"finished at {time.strftime('%X')}")

asyncio.run(main())

"""
This snippet runs the two subroutines concurrently using create_task() function
"""
async def main():
    task1 = asyncio.create_task(
        say_after(1, 'hello'))

    task2 = asyncio.create_task(
        say_after(2, 'world'))

    print(f"started at {time.strftime('%X')}")

    # Wait until both tasks are completed (should take
    # around 2 seconds.)
    await task1
    await task2

    print(f"finished at {time.strftime('%X')}")

"""
Use TaskGroup for a more modern example of above
"""
async def main():
    async with asyncio.TaskGroup() as tg:
        task1 = tg.create_task(
            say_after(1, 'hello'))

        task2 = tg.create_task(
            say_after(2, 'world'))

        print(f"started at {time.strftime('%X')}")

    # The await is implicit when the context manager exits.

    print(f"finished at {time.strftime('%X')}")

"""
async for

With async for, you can iterate over asynchronous iterators in a non-blocking way.
Each iteration of the loop doesn't necessarily wait for the previous one to complete.
Instead, it yields control back to the event loop, allowing other asynchronous tasks to run concurrently
"""
# Define an asynchronous generator
async def async_generator():
    for i in range(5):
        # Simulate some asynchronous operation (e.g., sleeping)
        await asyncio.sleep(1)
        yield i

# Asynchronous function using "async for"
async def main():
    async for value in async_generator():
        print(f"Received value: {value}")
        await asyncio.sleep(0.5)  # Simulate additional asynchronous work


class AsyncCounter:
    def __init__(self, limit):
        self.limit = limit
        self.current = 0

    # Define the asynchronous iterator
    async def __aiter__(self):
        return self

    # Define the asynchronous next method
    async def __anext__(self):
        if self.current < self.limit:
            result = self.current
            self.current += 1
            await asyncio.sleep(1)  # Simulate asynchronous operation
            return result
        else:
            raise StopAsyncIteration
