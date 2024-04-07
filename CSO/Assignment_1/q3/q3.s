.global palindrome              # %rdi = N , %rsi = arr

palindrome:
    movq %rsi, %r8              # setting the start of array
    movq %rsi, %r9              # setting the end of array
    movq %rdi, %r10             # duplicating 'N'

    jmp .last                   # retrieving th elast index

.last:
    cmpq $1, %r10               # compare to test if end has been reached
    jle .check                  # jump to the actual compute function

    addq $1, %r9                # moving to next array index (1 byte ahead)
    subq $1, %r10               # decrementing N to keep check for number of iterations

    jmp .last                   # recursively calling, to implement a for loop

.check:
    cmpq $1, %rdi               # compare to test if end has been reached
    jle .true                   # jump to the actual compute function

    movzx (%r8), %rcx           # getting front value
    movzx (%r9), %rdx           # getting end value
    cmpq %rcx, %rdx             # comparing
    jne .false                  # returning 0, if false

    addq $1, %r8                # moving to prev array index (1 byte ahead)
    subq $1, %r9                # moving to next array index (1 byte behind)

    subq $1, %rdi               # decrementing N to keep check for number of iterations
    jmp .check                  # recursively calling, to implement a for loop

.false:
    movq $0, %rax               # not a palindrome
    ret                         # return the final answer

.true:
    movq $1, %rax               # is a palindrome
    ret                         # return the final answer
