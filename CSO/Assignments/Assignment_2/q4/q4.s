.global records                 # %rdi = N , %rsi = arr , %rdx = temp

records:
    movq $0, %r8                # idx = 0
    movq $0, %r9                # ans = 0
    movq $0, %r10               # i = 0
    movq $0, %r11               # j = 0
    jmp .forLoop                # Enter for loop

.forLoop:
    cmpq %r10, %rdi             # Check for valid index
    jle .findSum                # Find sum of the resultant array

    cmpq $101, (%rsi)           # Check for 'C'
    je .detectedC               # Detected a 'C'

    cmpq $102, (%rsi)           # Check for 'D'
    je .detectedD               # Detected a 'D'

    cmpq $103, (%rsi)           # Check for '+'
    je .detectedPlus            # Detected a '+'

    jmp .detectedNum            # Detected a normal number

.detectedC:
    decq %r8                    # idx--

    incq %r10                   # i++
    addq $8, %rsi               # &arr[i]
    jmp .forLoop                # Continuing the for loop

.detectedD:
    movq %r8, %r13              # %r13 = idx
    decq %r13                   # %r13 = idx-1
    imulq $8, %r13              # %r13 = (idx-1)*8
    addq %rdx, %r13             # %r13 = &temp[idx-1]
    movq (%r13), %r12           # %r12 = temp[idx-1]
    imulq $2, %r12              # %r12 = 2 * temp[idx-1]

    movq %r8, %r14              # %r14 = idx
    imulq $8, %r14              # %r14 = 8*idx
    addq %rdx, %r14             # %r14 = &temp[idx]

    movq %r12, (%r14)           # temp[idx] = 2 * temp[idx-1]
    incq %r8                    # idx++

    incq %r10                   # i++
    addq $8, %rsi               # &arr[i]
    jmp .forLoop                # Continuing the for loop

.detectedPlus:
    movq %r8, %r13              # %r13 = idx
    decq %r13                   # %r13 = idx-1
    imulq $8, %r13              # %r13 = (idx-1)*8
    movq %r13, %r15             # %r15 = %r13
    subq $8, %r13               # %r13 = (idx-2)*8

    addq %rdx, %r15             # %r15 = &temp[idx-1]
    addq %rdx, %r13             # %r13 = &temp[idx-2]

    movq %r8, %r14              # %r14 = idx
    imulq $8, %r14              # %r14 = 8*idx
    addq %rdx, %r14             # %r14 = &temp[idx]

    movq (%r13), %r12           # %r12 = temp[idx-2]
    addq (%r15), %r12           # %r12 += temp[idx-1]
    movq %r12, (%r14)           # temp[idx] = %r12
    incq %r8                    # idx++

    incq %r10                   # i++
    addq $8, %rsi               # arr[i]
    jmp .forLoop                # Continuing the for loop

.detectedNum:
    movq %r8, %r14              # %r14 = idx
    imulq $8, %r14              # %r14 = 8*idx
    addq %rdx, %r14             # %r14 = &temp[idx]

    movq (%rsi), %r12           # %r12 = arr[i]
    movq %r12, (%r14)           # temp[idx] = %r12
    incq %r8                    # idx++

    incq %r10                   # i++
    addq $8, %rsi               # &arr[i]
    jmp .forLoop                # Continuing the for loop

.findSum:
    cmpq %r11, %r8              # Check for valid index
    jle .finally                # Call for a return of values

    addq (%rdx), %r9            # ans += temp[j]
    incq %r11                   # j++
    addq $8, %rdx               # &temp[j]
    jmp .findSum                # Recalling the for loop

.finally:
    movq %r9, %rax              # Setting up return value
    ret                         # Returning from function call
