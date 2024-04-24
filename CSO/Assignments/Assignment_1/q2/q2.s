.global shift                   # %rdi = N , %rsi = arr

shift:
    movq (%rsi), %rcx           # store the first value
    jmp .func                   # call the main operating function

.func:
    cmpq $1, %rdi               # compare to test if all values have been computed
    jle .end                    # jump to the return fuction

    movq 8(%rsi), %r8           # retrieving value at the next index
    movq %r8, (%rsi)            # substituting the retrieved value to current index
    
    addq $8, %rsi               # moving pointer to the next index
    subq $1, %rdi               # decrementing N
    jmp .func                   # recursive call to implement for loop

.end:
    movq %rcx, (%rsi)           # setting the first value to the last index

    movq %rcx, %rax             # moving the array address to the return variable
    ret                         # return the final answer

