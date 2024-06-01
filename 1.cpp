#include <stdio.h>

void SMA(int demand[], int x, int y, int n) {
    for (int i = x - y; i < x; i++) {
        double sma = 0;
        for (int j = i - n + 1; j <= i; j++) {
            sma += demand[j];
        }
        sma /= n;
        printf("%.2f ", sma);
    }
    printf("\n");
}

int main() {
    int x, y, n;

    printf("size of the array: ");
    scanf("%d", &x);

    int m[x];

    printf("elements of the array:\n");
    for (int i = 0; i < x; i++) {
        scanf("%d", &m[i]);
    }

    printf("y: ");
    scanf("%d", &y);

    printf("n: ");
    scanf("%d", &n);

    
    if (n <= 0 || n > x) {
        printf("average.\n");
        return 0;
    }

    SMA(m, x, y, n);

    return 0;
}
