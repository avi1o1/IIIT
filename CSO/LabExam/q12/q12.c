#include <stdio.h>

int palSum(int N);
// {
//     if (N == 0) {
//         return 0;
//     }

//     int temp = N;
//     int sum = 0;

//     while (N) {
//         int x = N % 10;

//         if (x == 9) {
//             sum += 362880;
//         }
//         else if (x == 8) {
//             sum += 40320;
//         }
//         else if (x == 7) {
//             sum += 5040;
//         }
//         else if (x == 6) {
//             sum += 720;
//         }
//         else if (x == 5) {
//             sum += 120;
//         }
//         else if (x == 4) {
//             sum += 24;
//         }
//         else if (x == 3) {
//             sum += 6;
//         }
//         else if (x == 2) {
//             sum += 2;
//         }
//         else {
//             sum += 1;
//         }

//         N /= 10;
//     }

//     if (sum == temp) {
//         return 1;
//     }
//     return 0;
// }

int main() {
    int N;
    scanf("%d", &N);

    if (palSum(N)) {
        printf("TRUE\n");
    }
    else {
        printf("FALSE\n");
    }
}