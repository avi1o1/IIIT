#include <stdio.h>
#define ll long long int

ll records(ll N, ll arr[], ll temp[]);
// {
//     ll idx = 0;
//     ll ans = 0;
//     for (int i = 0; i < N; i++) {
//         if (arr[i] == 101) {
//             idx--;
//         }
//         else if (arr[i] == 102) {
//             temp[idx++] = temp[idx-1] * 2;
//         }
//         else if (arr[i] == 103) {
//             temp[idx++] = temp[idx - 2] + temp[idx - 1];
//         }
//         else {
//             temp[idx++] = arr[i];
//         }
//     }

//     for (int j = 0; j < idx; j++) {
//         ans += temp[j];
//     }

//     return ans;
// }

int main() {
    ll N;
    scanf("%lld", &N);

    ll arr[N];
    char c;
    scanf("%c", &c);

    for (int i = 0; i < N; i++) {
        scanf("%c", &c);

        if (c == ' ') {
            i--;
        }
        else if (c == 'C') {
            arr[i] = 101;
        }
        else if (c == 'D') {
            arr[i] = 102;
        }
        else if (c == '+') {
            arr[i] = 103;
        }
        else if (c == '-') {
            ll num;
            scanf("%lld", &num);
            arr[i] = -1*num;
        }
        else {
            ll num = c - '0';
            while (1) {
                scanf("%c", &c);
                if (c == ' ' || c == '\n') {
                    break;
                }
                num = num*10 + (c - '0');
            }
            arr[i] = num;
        }
    }

    ll temp[N];
    printf("%lld\n", records(N, arr, temp));
    return 0;
}