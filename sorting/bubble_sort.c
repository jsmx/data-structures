#include <stdio.h>

#define ARRAY_LENGTH(x) (sizeof(x)/sizeof(x[0]))
#define TRUE 1
#define FALSE 0

void bubble_sort(int x[], int n)
{
    int i, j;
    int tmp;
    int switched;
    
    for (i = 0, switched = TRUE; i < n - 1 && TRUE == switched; i++) {
        switched = FALSE;
        for (j = 0; j < n - 1 - i; j++)
            if (x[j] > x[j + 1]) {
                switched = TRUE;
                tmp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = tmp;
            }
    }    
    return;
}

int main()
{
    unsigned int i;
    int x[] = {25, 57, 48, 37, 12, 92, 86, 33};
    
    bubble_sort(x, ARRAY_LENGTH(x));
    
    for (i = 0; i < ARRAY_LENGTH(x); i++)
        printf("%d ", x[i]);
    return 0;
}
