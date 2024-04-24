#include <stdio.h>
#define ll long long int

void findNum(ll X, ll arr[], ll temp[]);
// {
//     ll low = 0;
//     ll high = 31;
//     temp[1] = 0;

//     while (low <= high) {
//         ll mid = (low + high) / 2;
//         temp[1]++;

//         if (arr[mid] == X) {
//             while (mid > 0 && arr[mid-1] == X) {
//                 mid--;
//                 temp[1]++;
//             }
//             temp[0] = mid;
//             return;
//         }
//         else if (arr[mid] > X) {
//             high = mid-1;
//         }
//         else {
//             low = mid+1;
//         }
//     }
//     temp[0] = -1;
//     return;
// }

int main() {
    ll arr[32];
    for (int i = 0; i < 32; i++) {
        scanf("%lld", &arr[i]);
    }

    ll X;
    scanf("%lld", &X);

    ll temp[2];
    findNum(X, arr, temp);
    
    printf("%lld %lld\n", temp[0], temp[1]);
    return 0;
}