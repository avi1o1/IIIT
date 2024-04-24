#include <stdio.h>
#include <limits.h>

int main() {
    long long int N, T;
    scanf("%lld %lld", &N, &T);

    long long int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }
    
    long long int low = 0;
    long long int high = LONG_MAX / 5;
    long long int mid;
    long long int ans = 0;

    while (low <= high) {
        mid = (low+high) / 2;
        // printf("%lld\n", mid);

        long long int possible = 0;
        for (int i = 0; i < N; i++) {
            possible += (mid / arr[i]);

            if (possible >= T) {
                ans = mid;
                high = mid - 1;
                break;
            }
        }

        if (possible < T) {
            low = mid + 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}