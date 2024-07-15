#include <stdio.h>
#include<stdlib.h>

int place(int x[], int k) {
    for (int i = 1; i < k; i++) {
        if (x[i] == x[k] || (abs(x[i] - x[k]) == abs(i - k))) {
            return 0;
        }
    }
    return 1;
}

void display(int x[], int n) {
    char board[20][20];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            board[i][j] = 'x';
        }
    }
    for (int i = 1; i <= n; i++) {
        board[i][x[i]] = 'Q';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void nqueens(int n) {
    int x[30];
    int k = 1;
    x[k] = 0;
    while (k != 0) {
        x[k] = x[k] + 1;
        while ((x[k] <= n) && !place(x, k)) {
            x[k] = x[k] + 1;
        }
        if (x[k] <= n) {
            if (k == n) {
                display(x, n);
            } else {
                k++;
                x[k] = 0;
            }
        } else {
            k--;
        }
    }
}

int main() {
    int n;
    printf("Enter number of queens (n > 3): ");
    scanf("%d", &n);
    printf("The solution to the queen problem is:\n");
    nqueens(n);
    return 0;
}
