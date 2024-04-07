import random
from q1_a import pseudo_rand_num_gen

# Estimating the value of pi using Monte Carlo method
def estimatingPI(n: int) -> float:
    x = pseudo_rand_num_gen(6937, n)
    y = pseudo_rand_num_gen(5423, n)

    inside = 0
    for i in range(n):
        if ((x[i]/10**len(str(x[i])))**2 + (y[i]/10**len(str(x[i])))**2) < 1:
            inside += 1

    return 4*inside/n

# Estimating the value of pi using Python's in-built module
def estimatePI(n: int) -> float:
    inside = 0
    for i in range(n):
        x = random.random()
        y = random.random()

        if (x**2 + y**2) < 1:
            inside += 1
    
    return 4*inside/n

# Driver code for testing
if __name__ == "__main__":
    acc = int(input("Accuracy : "))
    print("Estimated value of pi by Monte Carlo Method : {}".format(estimatingPI(acc)))  
    print("Estimated value of pi by Python's In-built Library : {}".format(estimatePI(acc)))  
    
