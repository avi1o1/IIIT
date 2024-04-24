#include <stdio.h>
#define ll long long int

ll gcd(ll a, ll b);
// {
//     while (a != 0) {
//         ll temp = a;
//         a = b % a;
//         b = temp;
//     }
//     return b;
// }

int main() {
    ll M, N;
    scanf("%lld %lld", &M, &N);

    printf("%lld\n", gcd(M, N));
    return 0;
}