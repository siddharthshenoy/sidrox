#include <stdio.h>

void reverse_array(int size, int array[size])
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}

void print_array(int size, int array[size])
{
    for (int i = 0; i < size; i++)
        printf("%d", array[i]);
    puts("");
}
