.global findNum                 # %rdi = X , %rsi = arr , %rdx = temp

findNum:
    movq %rdx, %rcx             # %rcx = temp
    movq $0, %r8                # low = 0
    movq $31, %r9               # high = 31
    movq $0, (%rcx)             # temp[0] = 0
    movq %rcx, %r12             # %r12 = temp
    addq $8, %r12               # %r12 = &temp[1]
    movq $0, (%r12)             # temp[1] = 0
    jmp .whileLoop              # Start with the while loop

.whileLoop:
    cmpq %r8, %r9               # Check while condition
    jle .notFound               # if i > N (element not found, return -1)

    movq %r8, %r10              # mid = low
    addq %r9, %r10              # mid = low + high
    movq $0, %rdx               # Setting %rdx to 0, for division
    movq %r10, %rax             # Setting %rax to %r10, for division
    movq $2, %r13               # %r13 = 2
    idivq %r13                  # %rax = (low+high) / 2
    movq %rax, %r10             # %r10 = (low+high) / 2

    movq %rcx, %r15             # %r15 = temp
    addq $8, %r15               # %r15 = &temp[1]
    incq (%r15)                 # temp[1]++

    movq %r10, %r14             # %r14 = mid
    imulq $8, %r14              # %r14 = mid*8
    addq %rsi, %r14             # %r14 = &arr[mid]

    cmpq %rdi, (%r14)           # Compare arr[mid] and X
    je .elementFound            # Element Found

    cmpq %rdi, (%r14)           # Compare arr[mid] and X
    jg .greaterStill            # arr[mid] > X

    jmp .lowerStill             # arr[mid] < X

.elementFound:
    cmpq $0, %r10               # Check if mid is a valid index
    jle .whileCompleted         # Break out of while loop

    movq %r10, %r11             # %r11 = mid
    decq %r11                   # %r11 = mid-1
    imulq $8, %r11              # %r11 = 8*(mid-1)
    addq %rsi, %r11             # %r11 = arr[mid-1]
    cmpq %rdi, %r11             # Comparing arr[mid-1] and X
    jne .whileCompleted         # Break out of while loop

    decq %r10                   # mid--
    movq %rcx, %r15             # %r15 = temp
    addq $8, %r15               # %r15 = &temp[1]
    incq (%r15)                 # temp[1]++
    jmp .elementFound           # Recalling while loop

.greaterStill:
    movq %r10, %r9              # high = mid
    decq %r9                    # high = mid-1
    jmp .whileLoop              # Continue while loop

.lowerStill:
    movq %r10, %r8              # low = mid
    incq %r8                    # low = mid+1
    jmp .whileLoop              # Continue while loop

.whileCompleted:
    movq %r10, (%rcx)           # temp[0] = mid
    ret                         # Return

.notFound:
    movq $-1, (%rcx)            # temp[0] = -1
    ret                         # Return
