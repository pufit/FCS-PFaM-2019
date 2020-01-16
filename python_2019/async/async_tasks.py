import asyncio
import itertools
import time


async def first_task():
    for i in itertools.count():
        await asyncio.sleep(1)  # настоящий асинх
        print(f'Iteration #{i}')


async def second_task():
    i = 0
    while True:
        await asyncio.sleep(1)  # настоящий асинх
        i = (i + 1) % 5  # каждые 5 секунд

        if i == 0:
            print(time.time())


tasks = [first_task(), second_task()]
loop = asyncio.new_event_loop()

loop.run_until_complete(asyncio.wait(tasks))