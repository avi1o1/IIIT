from calendar import c
import time
import matplotlib.pyplot
matplotlib.use('TkAgg')

# Subtask 1 : To generate random numbers using system time
def pseudo_rand_num_gen(seed: int, k: int) -> list[int]:
    lst = []
    lst.append(seed)
    for i in range(k-1):
        try:
            seed = int(str(seed ** 2)[-6:-2])
            if seed < 1000:
                # pad seed with 7 to make a 4 digit number
                seed = int("7"*(4-len(str(seed))) + str(seed))
            
            if str(seed)[-1] == '0':
                seed = int(str(seed)[:-1] + "7")
                
        except ValueError:
            seed = seed**2
        lst.append(seed)
    return lst

# Plot a histogram out of a list of integers provided
def plotHistogram(lst: list[int]) -> None:
    matplotlib.pyplot.hist(lst, color='grey', bins=7)
    matplotlib.pyplot.xlabel('Value')
    matplotlib.pyplot.ylabel('Frequency')
    matplotlib.pyplot.show()

# Driver code for testing
if __name__ == "__main__":
    k = int(input("Number of random numbers to generate : "))
    tym = time.strftime("%H%M", time.localtime())

    # tym = time.strftime("%M%S", time.localtime())                 # Testing multiple values in short time
    # print(tym)                                                    # Checking the value of seed/tym

    randomNumbers = pseudo_rand_num_gen(int(tym), k)
    print(randomNumbers)

    temp = [i/(10**len(str(i))) for i in randomNumbers]
    plotHistogram(temp)
