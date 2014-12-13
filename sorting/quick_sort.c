#include <stdio.h>
#define ARRAY_LENGTH(x) (sizeof(x)/sizeof(x[0]))

void partition(int x[], int lb, int ub, int *pivot)
{
    int a;
    int up, down;
    int tmp;
    
    a = x[lb];
    up = ub;
    down = lb;
    while (down < up) {
        while (x[down] <= a && down < ub)
            down++;
        while (x[up] > a)
            up--;
        if (down < up) {
            tmp = x[down];
            x[down] = x[up];
            x[up] = tmp;
        }
    }
    x[lb] = x[up];
    x[up] = a;
    *pivot = up;
}

void quick_sort(int x[], int lb, int ub)
{
    int pivot;
    if (lb >= ub)
        return;
    partition(x, lb, ub, &pivot);
    quick_sort(x, lb, pivot - 1);
    quick_sort(x, pivot + 1, ub);
}

int main()
{
    unsigned int i;
    int x[] = {25, 57, 48, 37, 12, 92, 86, 33};
    
    quick_sort(x, 0, ARRAY_LENGTH(x) - 1);
    
    for (i = 0; i < ARRAY_LENGTH(x); i++)
        printf("%d ", x[i]);

    return 0;
}
