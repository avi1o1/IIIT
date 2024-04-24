.global palSum                              # %rdi = N

palSum:
    cmpq $0, %rdi                           # Checking for N = 0, seperately
    je .retZero                             # Zero return for N = 0

    movq %rdi, %r8                          # %r8 = temp = N
    movq $0, %r9                            # %r9 = sum = 0

    jmp .whileLoop                          # Finding the digit palindrome sum

.whileLoop:
    cmpq $0, %r8                            # Checking for zero-palindrome
    je .sumFound                            # Palindrome sum calculated

    movq $10, %r13                          # Setting up divisor for division
    movq %r8, %rax                          # Setting up %rax for division
    movq $0, %rdx                           # Setting up %rdx for division
    idivq %r13                              # Dividing by 10
    movq %rdx, %r10                         # %r10 = x = temp % 10
    movq %rax, %r8                          # %r8 = temp /= 10

    cmpq $9, %r10                           # Unit digit is 9
    je .addNine                             # Add 9! to sum

    cmpq $8, %r10                           # Unit digit is 8
    je .addEight                            # Add 8! to sum

    cmpq $7, %r10                           # Unit digit is 7
    je .addSeven                            # Add 7! to sum

    cmpq $6, %r10                           # Unit digit is 6
    je .addSix                              # Add 6! to sum

    cmpq $5, %r10                           # Unit digit is 5
    je .addFive                             # Add 5! to sum

    cmpq $4, %r10                           # Unit digit is 4
    je .addFour                             # Add 4! to sum

    cmpq $3, %r10                           # Unit digit is 3
    je .addThree                            # Add 3! to sum

    cmpq $2, %r10                           # Unit digit is 2
    je .addTwo                              # Add 2! to sum

    jmp .addOne                             # Add 1 to sum

.addOne:
    addq $1, %r9                            # Adding 1!
    jmp .whileLoop                          # Continuing the while loop

.addTwo:
    addq $2, %r9                            # Adding 2!
    jmp .whileLoop                          # Continuing the while loop

.addThree:
    addq $6, %r9                            # Adding 3!
    jmp .whileLoop                          # Continuing the while loop

.addFour:
    addq $24, %r9                           # Adding 4!
    jmp .whileLoop                          # Continuing the while loop

.addFive:
    addq $120, %r9                          # Adding 5!
    jmp .whileLoop                          # Continuing the while loop

.addSix:
    addq $720, %r9                          # Adding 6!
    jmp .whileLoop                          # Continuing the while loop

.addSeven:
    addq $5040, %r9                         # Adding 7!
    jmp .whileLoop                          # Continuing the while loop

.addEight:
    addq $40320, %r9                        # Adding 8!
    jmp .whileLoop                          # Continuing the while loop

.addNine:
    addq $362880, %r9                       # Adding 9!
    jmp .whileLoop                          # Continuing the while loop

.sumFound:
    cmpq %rdi, %r9                          # Comparing palindrome sum and N
    je .retOne                              # If equal

    jmp .retZero                            # Not equal

.retOne:
    movq $1, %rax                           # Setting up return value as 1
    ret

.retZero:
    movq $0, %rax                           # Setting up return value as 0
    ret
