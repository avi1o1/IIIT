.global sumArray                # %rdi = N , %rsi = arr , %rdx = L , %rcx = R

sumArray:
    movq $0, %r8                # ans = 0
    movq $0, %r9                # i = 0
    jmp .outerLoop              # Outer loop starts

.outerLoop:
    cmpq %rdi, %r9              # Compare i with N
    jge .finally                # If i >= N (exit loop)

    movq %r9, %r10              # j = i
    jmp .middleLoop             # Jump to middle loop

.middleLoop:
    cmpq %rdi, %r10             # Compare j wih N
    jge .endMiddleLoop          # If j >= N (exit loop)

    movq %r10, %r11             # %r11 = j
    subq %r9, %r11              # %r11 -= i
    incq %r11                   # %r11 += 1

    cmpq %rdx, %r11             # Check if L <= j-i+1
    jl .nextMiddleLoop          # If not, jump to next iteration of inner loop
    cmpq %rcx, %r11             # Check if j-i+1 <= R
    jg .nextMiddleLoop          # If not, jump to next iteration of inner loop

    movq $0, %r12               # sum = 0
    movq %r9, %r13              # k = i
    jmp .calcSum                # Calculate the sum

.calcSum:
    cmpq %r10, %r13             # Check if k <= j
    jg .sumUpdate               # If not, call sumUpdate

    movq %r13, %r14             # %r15 = k
    imulq $8, %r14              # %r15 *= 8
    addq %rsi, %r14             # %r15 += arr
    addq (%r14), %r12           # sum += arr[k]
    incq %r13                   # Increment k
    jmp .calcSum                # Call loop recursively

.sumUpdate:
    cmpq %r8, %r12              # Compare sum with ans
    jle .nextMiddleLoop         # If sum <= ans, no change

    movq %r12, %r8              # Else, ans = sum
    jmp .nextMiddleLoop

.nextMiddleLoop:
    incq %r10                   # Increment j
    jmp .middleLoop             # Continue middle loop

.endMiddleLoop:
    incq %r9                    # Increment i
    jmp .outerLoop              # Continue outer loop

.finally:
    movq %r8, %rax              # Set return value
    ret                         # Return ans    
