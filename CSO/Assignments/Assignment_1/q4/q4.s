.global extreme                 # %rdi = N , %rsi = arr

extreme:                        # Assuming input number lie in the range [-69, 420]
    movq $421, %r8              # setting a minimum value variable
    movq $-70, %r9              # setting a maximum value variable
    jmp .func                   # calling the actual function

.func:
    cmpq $0, %rdi               # compare to test if all values have been computed
    jle .end                    # jump to the return fuction

    cmpq %r8, (%rsi)            # compare with the minimum value
    cmovl (%rsi), %r8           # if smaller, update the minimum variable

    cmpq %r9, (%rsi)            # compare with the maximum value
    cmovg (%rsi), %r9           # if larger, update the maximum variable

    addq $8, %rsi               # moving to next array index (8 bytes ahead)
    subq $1, %rdi               # decrementing N to keep check for number of iterations

    jmp .func                   # recursively calling, to implement a for loop

.end:
    movq %r8, %rax              # moving minimum value to the return variable
    addq %r9, %rax              # adding maximum value to the return variable
    ret                         # return the final answer
