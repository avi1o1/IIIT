.global combi                   # %rdi = N , %rsi = R

combi:
    pushq %rbp                  # Saving base pointer
    movq %rsp, %rbp             # Setting up new base pointer

    cmpq $0, %rsi               # Check for base case
    je .baseCase                # Base case condition satisfied

    pushq %rdi                  # Pushing N to the stack
    pushq %rsi                  # Pushing R to the stack

    decq %rsi                   # R--
    call combi                  # Calling the function recursively

    popq %rsi                   # Pushing N to the stack
    popq %rdi                   # Pushing R to the stack

    movq %rdi, %r8              # %r8 = N
    subq %rsi, %r8              # %r8 -= R
    incq %r8                    # %r8 += 1
    imulq %r8, %rax             # %rax *= (N-R+1)

    movq $0, %rdx               # Setting up %rdx for division
    idivq %rsi                  # %rax /= R

    pop %rbp                    # Restoring base pointer
    ret                         # Return from function call


.baseCase:
    movq $1, %rax               # Setting return value
    popq %rbp                   # Restoring base pointer
    ret                         # Return from function call
