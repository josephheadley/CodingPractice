import math as m
import random as r 

lbound = 0
ubound = 1
total = int(input("How many trials would you like to have: "))

xrand = r.uniform(lbound,ubound)

def area(x):
    return (6/m.sqrt(4-(x**2)))

integral = 0.0

for i in range(total):
    integral += area(xrand)

answer = (ubound-lbound)/float(total)*integral
print(answer)
print(m.pi)

#for trial in range(0, total):
    #x = r.random()**2
    #if (6/m.sqrt(4-x)) < 1.0:
     #   area += 1
#pi = (float(area)/total)*4
#print(pi)
#print(m.pi)