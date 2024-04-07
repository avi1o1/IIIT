#include <stdio.h>
#define ll long long int

ll sumArray(ll N, ll arr[], ll L, ll R);
// {
//     ll ans = 0;
//     for (ll i = 0; i < N; i++) {
//         for (ll j = i; j < N; j++) {
//             if (L <= j-i+1 && j-i+1 <= R) {
//                 ll sum = 0;
//                 for (ll k = i; k <= j; k++) {
//                     sum += arr[k];
//                 }
//                 if (sum > ans) {
//                     ans = sum;
//                 }
//             }
//         }
//     }
//     return ans;
// }

int main() {
    ll N, L, R;
    scanf("%lld %lld %lld", &N, &L, &R);

    ll arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    printf("%lld\n", sumArray(N, arr, L, R));
    return 0;
}