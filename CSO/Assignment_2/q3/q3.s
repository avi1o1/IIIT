.global evaluatePostfix         # %rdi = N , %rsi = arr

evaluatePostfix:
    movq $0, %r8                # i = 0
    movq %rdi, %r9              # %r9 = N
    decq %r9                    # %r9 = N-1

    jmp .whileLoop              # Enter the while loop

.whileLoop:
    cmpq %r8, %r9               # Checking for valid index
    jle .finally                # i >= N (exit loop)

    movq %r8, %r10              # %r10 = i
    imulq $8, %r10              # %r10 = 8*i
    addq %rsi, %r10             # %r10 = &arr[i] = num1

    movq %r10, %r11             # %r11 = &arr[i]
    addq $16, %r11              # %r11 = &arr[i+2] = num2
    
    movq %r11, %r12             # %r12 = &arr[i+2]
    addq $16, %r12              # %r12 = &arr[i+4]

    cmpq $43, (%r12)            # Checking for '+'
    je .add                     # '+' detected

    cmpq $45, (%r12)            # Checking for '-'
    je .sub                     # '-' detected

    cmpq $42, (%r12)            # Checking for '*'
    je .mul                     # '*' detected

    cmpq $47, (%r12)            # Checking for '/'
    je .div                     # '/' detected

    addq $4, %r8                # i += 4
    jmp .whileLoop              # Continuing the while loop

.add:
    movq (%r10), %r13           # %r13 = num1
    addq (%r11), %r13           # %r13 += num2
    movq %r13, (%r12)           # (%r12) = arr[i+4] = num1+num2

    addq $4, %r8                # i += 4
    jmp .whileLoop              # Continuing the while loop

.sub:
    movq (%r10), %r13           # %r13 = num1
    subq (%r11), %r13           # %r13 -= num2
    movq %r13, (%r12)           # (%r12) = arr[i+4] = num1-num2

    addq $4, %r8                # i += 4
    jmp .whileLoop              # Continuing the while loop

.mul:
    movq (%r10), %r13           # %r13 = num1
    imulq (%r11), %r13          # %r13 *= num2
    movq %r13, (%r12)           # (%r12) = arr[i+4] = num1*num2

    addq $4, %r8                # i += 4
    jmp .whileLoop              # Continuing the while loop

.div:
    movq (%r10), %rax           # %rax = num1
    movq $0, %rdx               # %rdx = 0
    idivq (%r11)                # num1 / num2
    movq %rax, (%r12)           # (%r12) = arr[i+4] = num1 / num2

    addq $4, %r8                # i += 4
    jmp .whileLoop              # Continuing the while loop

.finally:
    movq %r9, %r15              # %r15 = N-1
    imulq $8, %r15              # %r15 = (N-1)*8
    addq %rsi, %r15             # %r15 = &arr[N-1]
    movq (%r15), %rax           # %rax = arr[N-1]
    ret                         # Returning %rax
