#include <stdio.h>
#include <stdlib.h>
#define ll long long int

// Defining the data structure
typedef struct Node {
    ll depth;
    ll time;
} Node;
typedef Node* Station;

// Defining the heap structure
typedef struct Heap {
    Station* arr;
    int count;
} Heap;

// Function to insert a node into the heap
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

// Function to extract the minimum node from the heap
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

// Compare functio for qsort implementation
int compare(const void* a, const void* b) {
    Station* nodeA = (Station*) a;
    Station* nodeB = (Station*) b;
    return (*nodeA)->depth - (*nodeB)->depth;
}

int main() {
    // Taking inputs
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

    // Creating a min heap of station nodes
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

    // Sorting arr based on arr->depth
    qsort(arr, stationCount, sizeof(Station), compare);

    ll currDepth = 0;
    ll totalTime = 0;
    int idx = 0;

    // Finding the minimum time to reach the destination
    while (currDepth + currOxygen < totalDist) {
        for (int i = idx; i < stationCount; i++) {
            // If the station is reachable, insert it into the heap
            if (arr[i] && arr[i]->depth > currDepth && arr[i]->depth <= currDepth + currOxygen) {
                avilol = insert(avilol, arr[i]);
                idx++;
                arr[i] = NULL;
            }
            else {
                break;
            }
        }

        // If no station is reachable, return -1
        if (avilol->count == 0) {
            printf("-1 %lld\n", currDepth + currOxygen);
            return 0;
        }

        // Extract the most optimum station
        Station temp = extract(avilol);
        totalTime += temp->time;
        currOxygen -= (temp->depth - currDepth);
        currOxygen += refillValue;
        currDepth = temp->depth;
    }

    printf("%lld\n", totalTime);
    return 0;
}