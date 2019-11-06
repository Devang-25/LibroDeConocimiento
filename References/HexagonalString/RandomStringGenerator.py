#!/usr/bin/python3

import itertools
import random

# characters = "AEGHIJNOPQRXYZ"
characters = "HARXYHEPRZPXAGYRIHOEAHHNHXGAYRPHOHAJQN"

# characters = random.sample(characters, random.randint(0, len(characters)))
characters = random.sample(characters, random.randint(0, len(characters) // 4))

for index, current in enumerate(itertools.permutations(characters)):
    print("".join(current), end = ' ')
    if (index >= 9): break

print()
