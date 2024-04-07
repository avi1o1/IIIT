.global lonely                  # %rdi = N , %rsi = arr

lonely:
    movq $0, %rax               # setting return value
    jmp .func                   # calling the actual function

.func:
    cmpq $0, %rdi               # compare to test if all values have been computed
    jle .end                    # jump to the return fuction
    
    xorq (%rsi), %rax           # xor all the values (to find the lonely number)
    addq $8, %rsi               # moving to next array index (8 bytes ahead)
    subq $1, %rdi               # decrementing N to keep check for number of iterations

    jmp .func                   # recursively calling, to implement a for loop

.end:
    ret                         # return the final answer
