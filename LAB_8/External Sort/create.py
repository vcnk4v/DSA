import sys
import random
import numpy as np
from datetime import datetime

random.seed(datetime.now().timestamp())

f = open("demofile.txt", "w")

n = 10000000
int_max = 1000000000

for i in range(n):
    a = random.randint(0, int_max)
    f.write(str(a) + " ")

f.close()
