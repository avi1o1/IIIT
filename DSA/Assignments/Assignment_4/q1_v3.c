#include <stdio.h>
#include <stdlib.h>
#define ll long long int

typedef struct Node {
    ll depth;
    ll time;
} Node;
typedef Node* Station;

typedef struct Heap {
    Station* arr;
    int count;
} Heap;

Heap* insert(Heap* avilol, Station node) {
    avilol->arr[++(avilol->count)] = node;

    int j = avilol->count;
    while (j > 1 && avilol->arr[j/2]->time > avilol->arr[j]->time) {
        Station tempNode = avilol->arr[j];
        avilol->arr[j] = avilol->arr[j/2];
        avilol->arr[j/2] = tempNode;
        j /= 2;
    }
    return avilol;
}

Station extract(Heap* heap) {
    Station retNode = heap->arr[1];
    heap->arr[1] = heap->arr[heap->count--];
    heap->arr[heap->count+1] = NULL;

    int idx = 1;
    while (2*idx <= heap->count) {
        int child;
        if (2*idx + 1 <= heap->count && heap->arr[2*idx+1]->time < heap->arr[2*idx]->time) {
            child = 2*idx + 1;
        } else {
            child = 2*idx;
        }

        if (heap->arr[idx]->time > heap->arr[child]->time) {
            Station tempNode = heap->arr[child];
            heap->arr[child] = heap->arr[idx];
            heap->arr[idx] = tempNode;
            idx = child;
        } else {
            break;
        }
    }
    return retNode;
}

int main() {
    int stationCount;
    ll currOxygen, totalDist, refillValue;
    scanf("%d %lld %lld %lld", &stationCount, &currOxygen, &totalDist, &refillValue);

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

    // create a min heap of station nodes
    Heap* avilol = (Heap*) malloc(sizeof(Heap));
    avilol->arr = (Station*) malloc(sizeof(Station) * (stationCount + 1));
    avilol->count = 0;

    Station sentinelNode = (Station) malloc(sizeof(Node));
    sentinelNode->depth = 0;
    sentinelNode->time = 0;
    avilol->arr[0] = sentinelNode;

    for (int i = 1; i < stationCount + 1; i++) {
        avilol->arr[i] = NULL;
    }

    // Checking insert function
    // for (int i = 0; i < stationCount; i++) {
    //     avilol = insert(avilol, arr[i]);
    // }

    // Checking extract function
    // for (int x = 0; x < stationCount; x++) {
    //     Station temp = extract(avilol);
    //     printf("%lld %lld\n", temp->depth, temp->time);
    // }

    ll currDepth = 0;
    ll totalTime = 0;

    while (currDepth + currOxygen < totalDist) {
        for (int i = 0; i < stationCount; i++) {
            if (arr[i] && arr[i]->depth > currDepth && arr[i]->depth <= currDepth + currOxygen) {
                avilol = insert(avilol, arr[i]);
                arr[i] = NULL;
            }
        }

        if (avilol->count == 0) {
            printf("-1 %lld\n", currDepth + currOxygen);
            return 0;
        }

        Station temp = extract(avilol);
        totalTime += temp->time;
        currOxygen -= (temp->depth - currDepth);
        currOxygen += refillValue;
        currDepth = temp->depth;
    }

    printf("%lld\n", totalTime);
    return 0;
}