#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    // Array of elements
    long long int arr[N];
	memset(arr, -69, sizeof(arr));

    for (int a = 0; a < N; a++) {
        scanf("%lld", &arr[a]);
    }

    // Bookkeeeping indices
	int ans = 1;
    int startIndex = 0;
    long long int dic[N];
	memset(dic, -69, sizeof(dic));

	for (int i = N-1; i >= 0; i--) {
        dic[i] = 1;
        for (int j = i+1; j < N; j++) {
            if (arr[j] == arr[i] + 1) {
                dic[i] = dic[j] + 1;
                break;
            }
        }

        if (dic[i] > ans) {
            ans = dic[i];
            startIndex = i;
        }
	}
	printf("%d\n", ans);

    long long int nextElement = arr[startIndex];
    for (int k = startIndex; k < N; k++) {
        if (arr[k] == nextElement) {
            printf("%d ", k);
            nextElement++;
            ans--;

            if (!ans) {
                break;
            }
        }
    }
	return 0;
}
