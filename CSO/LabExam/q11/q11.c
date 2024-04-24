#include <stdio.h>
#define ll long long int

void findAns(ll N, ll arr[], ll ans[]) {
    ll idx = 0;
    ll temp = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0) {
            temp += i;
        }
        else {
            temp += N-1-i;
        }
    }

    ll left = 0;
    ll right = N-1;
    while (arr[left] == 1) {
        left++;
    }
    while (arr[right] == 0) {
        right--;
    }

    while (left < right) {
        if (left <= N-1-right) {
            temp += N-1-left - left;
            ans[idx++] = temp;

            left++;
            while (arr[left] == 1) {
                left++;

                if (left >= N) {
                    break;
                }
            }
        }

        else {
            temp += right - (N-1-right);
            ans[idx++] = temp;

            right--;
            while (arr[right] == 0) {
                right--;

                if (right < 0) {
                    break;
                }
            }
        }
    }

    while (idx < N) {
        ans[idx++] = temp;
    }
    
    return;
}

int main() {
    ll N;
    scanf("%lld", &N);

    ll arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    ll ans[N];
    findAns(N, arr, ans);

    for (int j = 0; j < N; j++) {
        printf("%lld ", ans[j]);
    }
    printf("\n");
    return 0;
}