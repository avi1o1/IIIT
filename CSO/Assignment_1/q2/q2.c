#include <stdio.h>
#define ll long long int

ll* shift(ll N, ll arr[]);

int main() {
    ll N;
    scanf("%lld", &N);

    ll arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    ll* res = shift(N, arr);
    for (int i = 0; i < N; i++) {
        printf("%lld ", arr[i]);
    }

    printf("\n");    
    return 0;
}