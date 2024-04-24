#include <stdio.h>
#define ll long long int

ll maxSum(ll arr[], ll N, ll B);
// {
//     ll ans = 0;
//     ll temp = 0;

//     for (int i = 0; i < B; i++) {
//         temp += arr[i]; 
//     }
//     ans = temp;

//     for (int j = 0; j < B; j++) {
//         temp += arr[N-j-1] - arr[B-j-1];
//         if (temp > ans) {
//             ans = temp;
//         }
//     }
//     return ans;
// }

int main() {
    ll N, B;
    scanf("%lld %lld", &N, &B);

    ll arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    printf("%lld\n", maxSum(arr, N, B));
    return 0;
}