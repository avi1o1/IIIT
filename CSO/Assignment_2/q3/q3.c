#include <stdio.h>
#define ll long long int
// Assuming by single digit integer, it only means the set {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}.

ll evaluatePostfix(ll N, ll arr[]);
// {
//     ll i = 0;
//     while (i < N-1) {
//         ll num1 = arr[i];
//         ll num2 = arr[i+2];
        
//         if (arr[i+4] == 43) {
//             arr[i+4] = num1 + num2;
//         }
//         else if (arr[i+4] == 45) {
//             arr[i+4] = num1 - num2;
//         }
//         else if (arr[i+4] == 42) {
//             arr[i+4] = num1 * num2;
//         }
//         else if (arr[i+4] == 47) {
//             arr[i+4] = num1 / num2;
//         }
//         i += 4;
//     }
//     return arr[N-1];
// }

int main() {
    ll N;
    scanf("%lld", &N);
    ll arr[N];
    
    char c;
    scanf("%c", &c);
    for (ll i = 0; i < N; i++) {
        scanf("%c", &c);

        if (c == ' ') {
            arr[i] = -1;
        }      
        else if (c == '+') {
            arr[i] = 43;
        }
        else if (c == '-') {
            arr[i] = 45;
        }
        else if (c == '*') {
            arr[i] = 42;
        }
        else if (c == '/') {
            arr[i] = 47;
        }
        else {
            arr[i] = (int) (c - 48);
        }
    }

    ll res =  evaluatePostfix(N, arr);
    printf("%lld\n", res);
    
    return 0;
}