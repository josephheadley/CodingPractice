x = "8,3,6,40,19"
y = x.split(",")
z = [int(y[num]) for num in range(len(y))]

#for i in range(len(y)):
    #z.append(int(y[i]))

print(z)