.global gcd                     # %rdi = a ; %rsi = b

gcd:
    cmpq $0, %rdi               # Check while condition
    je .finally                 # Exit loop, if a == 0

    movq %rdi, %r8              # temp = a
    movq %rsi, %rax             # Setting up rax for modulo division
    movq $0, %rdx               # Setting up rdx for modulo division
    idivq %rdi                  # b % a
    movq %rdx, %rdi             # a = b % a
    movq %r8, %rsi              # b = temp

    jmp gcd

.finally:
    movq %rsi, %rax             # Setting up return register
    ret                         # Return answer
