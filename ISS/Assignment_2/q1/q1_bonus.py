import time
import matplotlib.pyplot
matplotlib.use('TkAgg')
from q1_a import pseudo_rand_num_gen

# Estimating value of PI
def estimatingPI(n: int) -> list[int]:
    tym = int(time.strftime("%H%M", time.localtime()))
    x = pseudo_rand_num_gen(5423, n)
    y = pseudo_rand_num_gen(6937, n)   # Adding 69 to the seed to get different random numbers

    inside = 0
    errors = []
    for i in range(n):
        if ((x[i]/10000)**2 + (y[i]/10000)**2) < 1:
            inside += 1
        
        pi = 4*inside/(i+1)
        errors.append(pi - 3.14159)
    
    print("Estimated value of pi : {}".format(pi))
    return errors

# Plotting the error in the estimated value of pi
def plotError(lst: list[int]) -> None:
    matplotlib.pyplot.plot(lst)
    matplotlib.pyplot.xlabel("Number of random numbers")
    matplotlib.pyplot.ylabel("Error in estimated value of pi")
    matplotlib.pyplot.title("Error in estimated value of pi vs Number of random numbers")
    matplotlib.pyplot.show()

# Driver code for testing
if __name__ == "__main__":
    acc = int(input("Accuracy : "))
    plotError(estimatingPI(acc))
