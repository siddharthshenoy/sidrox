#include <stdio.h>
#include "Header.h"

int main(int arr, char *argv[])
{
    puts("ENTER SIZE OF AN ARRAY");
    int d;
    scanf("%d", &d);
    puts("ENTER ELEMENTS OF AN ARRAY");
    int a[4];
    for (int i = 0; i < d; i++)
        scanf("%d", &a[i]);
    puts("Input array is");
    print_array(d, a);
    reverse_array(d, a);
    puts("Reversed array is");
    print_array(d, a);
    return 0;
}
