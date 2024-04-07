#include <stdio.h>
#define ll long long int

ll extreme(ll N, ll arr[]);

int main() {
    ll N;
    scanf("%lld", &N);

    ll arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    ll res = extreme(N, arr);
    printf("%lld\n", res);
    
    return 0;
}