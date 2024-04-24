#include <stdio.h>
#include <stdlib.h>
#define ll long long int

typedef struct Node {
    ll depth;
    ll time;
} Node;
typedef Node* Station;

int main() {
    ll stationCount, currOxygen, totalDist, refillValue;
    scanf("%lld %lld %lld %lld", &stationCount, &currOxygen, &totalDist, &refillValue);

    // Initializing an array of stations
    Station arr[stationCount];

    // Getting the depth of each station
    for (int i = 0; i < stationCount; i++) {
        int depth;
        scanf("%d", &depth);

        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->depth = depth;
        newNode->time = 0;
        arr[i] = newNode;
    }

    // Getting the time to refill oxygen at each station
    for (int j = 0; j < stationCount; j++) {
        ll time;
        scanf("%lld", &time);
        arr[j]->time = time;
    }

    // Sorting arr based on the depth
    for (int i = 0; i < stationCount; i++) {
        for (int j = i+1; j < stationCount; j++) {
            if (arr[i] && arr[j]) {
                if (arr[i]->depth > arr[j]->depth) {
                    Node* temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    // for (int k = 0; k < stationCount; k++) {
    //     printf("%lld %lld\n", arr[k]->depth, arr[k]->time);
    // }

    ll totalTime = 0;
    ll currDepth = 0;

    while (totalDist - currDepth > currOxygen) {
        // Finding the next station from currDepth
        int nextStation = -1;
        for (int i = 0; i < stationCount; i++) {
            if (arr[i]->depth > currDepth) {
                nextStation = i;
                break;
            }
        }

        // No station found
        if (nextStation == -1) {
            printf("-1 %lld\n", currDepth+currOxygen);
            return 0;
        }

        // If next station is unreachable
        if (arr[nextStation]->depth - currDepth > currOxygen) {
            printf("-1 %lld\n", currDepth+currOxygen);
            return 0;
        }


        // Finding the last reachable station that can be reached
        int lastStation = currDepth;
        for (int i = 0; i < stationCount; i++) {
            if (arr[i]->depth - currDepth <= currOxygen) {
                lastStation = i;
            }
        }

        // Refilling oxygen at the last reachable station
        totalTime += arr[lastStation]->time;
        currOxygen += refillValue;
        currOxygen -= (arr[lastStation]->depth - currDepth);
        currDepth = arr[lastStation]->depth;
    }

    printf("%lld\n", totalTime);
    return 0;
}