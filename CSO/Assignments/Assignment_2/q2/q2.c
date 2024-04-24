#include <stdio.h>
#define ll long long int

ll combi(ll N, ll R);
// {
//     if (R == 0) {
//         return 1;
//     }
//     return combi(N, R-1) * (N-R+1)/R;
// }

int main() {
    ll N, R;
    scanf("%lld %lld", &N, &R);

    printf("%lld\n", combi(N, R));    
    return 0;
}

// .global combi                   # %rdi = N , %rsi = R

// combi:
//     movq $1, %rax               # %rax = ans = 1
//     movq $1, %r8                # %r8 = i = 1
//     jmp .forLoop                # Enter the for loop

// .forLoop:
//     cmpq %rsi, %r8              # Compare i with R
//     jg .finally                 # i exceeded R, return values

//     movq %rdi, %r9              # %r9 = N
//     subq %r8, %r9               # %r9 -= i
//     incq %r9                    # %r9 += 1
//     imulq %r9, %rax             # %rax = ans *= (N-i+1)

//     movq $0, %rdx               # Setting %rdx to zero for division
//     idivq %r8                   # %rax /= i
//     incq %r8                    # i++
//     jmp .forLoop

// .finally:
//     ret                         # Return from function call
