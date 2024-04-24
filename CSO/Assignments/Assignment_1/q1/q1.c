#include <stdio.h>
#define ll long long int

ll lonely(ll N, ll arr[]);

int main() {
    ll n;
    scanf("%lld", &n);

    ll N = 2*n + 1;

    ll arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    ll res = lonely(N, arr);
    printf("%lld\n", res);
    
    return 0;
}