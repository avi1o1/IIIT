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

Heap* heapify(Station* dat, int size) {
    Heap* newHeap = (Heap*) malloc(sizeof(Heap));
    newHeap->arr = (Station*) malloc(sizeof(Station)*(size+1));
    newHeap->count = 0;


    newHeap->arr[0] = (Station) malloc(sizeof(Node));
    newHeap->arr[0]->depth = 0;
    newHeap->arr[0]->time = 0;

    for (ll i = 0; i < size; i++) {
        newHeap->arr[i+1] = dat[i];
        newHeap->count++;

        int j = i+1;
        while (newHeap->arr[j/2]->depth > newHeap->arr[j]->depth) {
            Station tempNode = newHeap->arr[j];
            newHeap->arr[j] = newHeap->arr[j/2];
            newHeap->arr[j/2] = tempNode;
            j /= 2;

            if (j <= 1) {
                break;
            }
        }
    }
    return newHeap;
}

Station extract(Heap* heap) {
    Station retNode = heap->arr[1];
    heap->arr[1] = heap->arr[heap->count];
    heap->count--;

    int idx = 1;
    while (2*idx <= heap->count) {
        if (2*idx + 1 <= heap->count) {
            if (heap->arr[idx]->depth > heap->arr[2*idx]->depth || heap->arr[idx]->depth > heap->arr[2*idx+1]->depth) {
                if (heap->arr[2*idx]->depth < heap->arr[2*idx+1]->depth) {
                    Station tempNode = heap->arr[2*idx];
                    heap->arr[2*idx] = heap->arr[idx];
                    heap->arr[idx] = tempNode;
                    idx *= 2;
                }
                else {
                    Station tempNode = heap->arr[2*idx+1];
                    heap->arr[2*idx+1] = heap->arr[idx];
                    heap->arr[idx] = tempNode;
                    idx = 2*idx+1;
                }
            }
            else {
                break;
            }
        }
        else {
            if (heap->arr[idx]->depth > heap->arr[2*idx]->depth) {
                Station tempNode = heap->arr[2*idx];
                heap->arr[2*idx] = heap->arr[idx];
                heap->arr[idx] = tempNode;
                idx *= 2;
            }
            else {
                break;
            }
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
    Heap* avilol = heapify(arr, stationCount);

    // for (int x = 0; x < stationCount; x++) {
    //     printf("%lld %lld\n", avilol->arr[x+1]->depth, avilol->arr[x+1]->time);
    // }

    // for (int x = 0; x < stationCount; x++) {
    //     Station temp = extract(avilol);
    //     printf("%lld %lld\n", temp->depth, temp->time);
    // }

    ll totalTime = 0;
    ll currDepth = 0;

    while (totalDist - currDepth > currOxygen) {
        // Finding the next station
        Station nextStation = extract(avilol);
        while (nextStation->depth <= currDepth) {
            // If no station is left
            if (avilol->count == 0) {
                printf("-1 %lld\n", currDepth+currOxygen);
                return 0;
            }

            nextStation = extract(avilol);
        }

        // If next station is unreachable
        if (nextStation->depth - currDepth > currOxygen) {
            printf("-1 %lld\n", currDepth+currOxygen);
            return 0;
        }

        // Finding the last reachable station
        int lastStation = avilol->count;
        for (int i = 1; i <= avilol->count; i++) {
            if (avilol->arr[i]->depth - currDepth <= currOxygen) {
                lastStation = i;
            }
        }

        // Refilling oxygen at the last reachable station
        totalTime += avilol->arr[lastStation]->time;
        currOxygen += refillValue;
        currOxygen -= (avilol->arr[lastStation]->depth - currDepth);
        currDepth = avilol->arr[lastStation]->depth;
    }

    printf("%lld\n", totalTime);
    return 0;
}