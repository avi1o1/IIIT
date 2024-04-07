.global productExcept           # %rdi = N , %rsi = arr 

productExcept:
    cmpq $1, %rdi
    je .finally
    
    movq %rdi, %r8              # Duplicating 'N'
    movq %rdi, %r11             # Duplicating 'N'
    movq %rdi, %r14             # Duplicating 'N'
    movq %rdi, %r10             # Duplicating 'N'

    movq %rsi, %r15             # Duplicating arr
    movq %rsi, %r12             # Duplicating arr
    movq %rsi, %r9              # Saving for return later

    movq $0, %rcx               # ZeroCount

    jmp .checkForZero           # calling the actual function

.checkForZero:
    cmpq $0, %r8                # compare to test if all values have been computed
    jle .direct                 # Now that no. of zeroes have been counted, jump to direct
    
    cmpq $0, (%r15)             # Checking for zero
    je .incZero                 # If zero, increase count of zero

    decq %r8                    # Decreasing N count
    addq $8, %r15               # Moving to next element in array
    jmp .checkForZero           # recursively calling, to implement a for loop

.incZero:
    incq %rcx                   # Increasing zero count

    decq %r8                    # Decreasing N count
    addq $8, %r15               # Moving to next element in array
    jmp .checkForZero           # Calling back the zeroCheck loop

.direct:
    cmpq $0, %rcx               # No zero in the array
    jle .normal                 # Jump to .normal function

    cmpq $2, %rcx               # Multiple zeroes in the array
    jge .zero                   # Jump to .zero function

    jmp .multExceptZero         # In case of only one zero, jump to .loser

.zero:
    cmpq $0, %rdi               # compare to test if all values have been computed
    jle .finally                # Now that no. of zeroes have been counted, jump to direct
    
    movq $0, (%rsi)             # Setting value to zero

    decq %rdi                   # Decreasing N count
    addq $8, %rsi               # Moving to next element in array
    jmp .zero                   # recursively calling, to implement a for loop


.multExceptZero:
    movq $1, %rbx               # Setting a product variable
    jmp .zeroProd               # calling the actual function

.zeroProd:
    cmpq $0, %r10               # compare to test if all values have been computed
    jle .loser                  # jump to the set-up function

    cmpq $0, (%r12)             # Check for zero
    je .zeroFound               # Zero found

    imulq (%r12), %rbx          # multiply all the values (to find the product)

    addq $8, %r12               # moving to the next array index (8 bytes ahead)
    subq $1, %r10               # decrementing N to keep check for the number of iterations

    jmp .zeroProd               # recursively calling, to implement a for loop

.zeroFound:
    addq $8, %r12               # moving to the next array index (8 bytes ahead)
    subq $1, %r10               # decrementing N to keep check for the number of iterations
    jmp .zeroProd               # recursively calling, to implement a for loop

.loser:
    cmpq $0, %rdi               # compare to test if all values have been computed
    jle .finally                # Now that no. of zeroes have been counted, jump to direct

    cmpq $0, (%rsi)             # Check if zero
    je .singleZero              # Zero detected
    
    movq $0, (%rsi)             # Setting value to zero

    decq %rdi                   # Decreasing N count
    addq $8, %rsi               # Moving to next element in array
    jmp .loser                  # recursively calling, to implement a for loop

.singleZero:
    movq %rbx, (%rsi)           # Setting value to zero
    decq %rdi                   # Decreasing N count
    addq $8, %rsi               # Moving to next element in array
    jmp .loser                  # recursively calling, to implement a for loop

.normal:
    movq $1, %r13               # Setting a product variable
    jmp .product                # calling the actual function

.product:
    cmpq $0, %r11               # compare to test if all values have been computed
    jle .array                  # jump to the return function
    
    imulq (%rsi), %r13          # multiply all the values (to find the product)
    addq $8, %rsi               # moving to the next array index (8 bytes ahead)
    subq $1, %r11               # decrementing N to keep check for the number of iterations

    jmp .product                # recursively calling, to implement a for loop

.array:
    cmpq $0, %r14               # compare to test if all values have been computed
    jle .finally                # jump to the return function

    subq $8, %rsi               # moving to the next array index (8 bytes ahead)
    subq $1, %r14               # decrementing N to keep check for the number of iterations

    movq $0, %rdx
    movq %r13, %rax
    cqto                        # sign-extend %rax into %rdx
    idivq (%rsi)                # use idivq for signed division
    movq %rax, (%rsi)

    jmp .array

.finally:
    movq %rcx, %rax
    ret
