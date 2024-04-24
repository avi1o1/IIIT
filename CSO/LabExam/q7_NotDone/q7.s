.global maxSum                          # %rdi = ans , %rsi = N , %rcx = B

maxSum:
    movq $0, %r8                        # ans = 0
    movq $0, %r9                        # temp = 0

    movq %rdi, %r11                     # %r11 = ans
    movq %rdi, %r12                     # %r12 = ans

    movq $0, %r10                       # i = 0
    jmp .initSum                        # Find sum of first B elements

.initSum:
    cmpq %r10, %rcx                     # Comparing i and B
    je .findAns                         # Jumping to next stage, if equal

    addq (%r11), %r9                    # temp += arr[i]
    addq $8, %r11                       # &arr[i] = &arr[i+1]
    addq $1, %r10                       # i += 1

    jmp .initSum

.findAns:
    movq %r9, %r8                       # ans = temp

    movq %rsi, %r14                     # %14 = N
    decq %r14                           # %14 = N-1
    imulq $8, %r14                      # %r14 = (N-1) * 8

    addq %rdi, %r14                     # %r14 = &arr[N-1]
    subq $8, %r11                       # %r11 = &arr[B-1]
    movq $0, %r13                       # j = 0

    jmp .ansLoop

.ansLoop:
    cmpq %r13, %rcx                     # Comparing j and B
    je .finally                         # Jumping to return stage, if equal

    addq (%r14), %r9                    # temp += arr[N-1-j]
    subq (%r11), %r9                    # temp -= arr[B-1-j]

    subq $8, %r14                       # %r14 = &arr[X--]
    subq $8, %r11                       # %r11 = &arr[X--]
    incq %r13                           # j += 1

    cmpq %r9, %r8                       # Comparing temp and ans
    jg .updateAns                       # update ans

    jmp .ansLoop                        # Loop back

.updateAns:
    movq %r9, %r8                       # ans = temp
    jmp .ansLoop                        # Loop back

.finally:
    movq %r8, %rax                      # Setting up return value
    ret
