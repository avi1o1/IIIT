/* Assignment 3, Question 4 : Valid Paths */

#include <stdio.h>

// Recursive function to calculate the number of valid paths (by traversing all possible paths)
int move_calc(int x, int y, int n_limit, int m_limit, int* grid) {
    // Invalid position
    if (x > n_limit || y > m_limit || x < 0 || y < 0) {
        return 0;
    }
    
    // Destination Reached
    else if (x == 0) {
        return 1;
    }

    // Minion Encountered
    else if (grid[1000*x + y] == -1) {
        return 0;
    }

    // Already calculated
    else if (grid[1000*x + y] > 0) {
        return (grid[1000*x + y]);
    }

    // Otherwise, calculate the number of total further paths
    else {
        int t1 = move_calc(x-2, y+1, n_limit, m_limit, grid);
        int t2 = move_calc(x-1, y+2, n_limit, m_limit, grid);
        int t3 = move_calc(x-2, y-1, n_limit, m_limit, grid);
        int t4 = move_calc(x-1, y-2, n_limit, m_limit, grid);
        grid[1000*x + y] = ((t1+t2+t3+t4) % 1000000007);
        return grid[1000*x + y];
    }

    // Should never reach here (Error)
    printf("Error");
    return 0;
}

int main() {
    // Taking input
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int data[1000000] = { 0 };

    // Setting up the minion positions
    for (int l = 0; l < k; l++) {
        int x, y;
        scanf("%d %d", &x, &y);
        data[1000*(x-1) + y-1] = -1;
    }

    // Calculating and printing the number of valid paths for each column
    for (int k = 0; k < m; k++) {
        printf("%d ", move_calc(n-1, k, n-1, m-1, data));
    }
    printf("\n");

    return 0;
}