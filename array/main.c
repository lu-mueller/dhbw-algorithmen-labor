#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/*long long timeInMilli(void)
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return(((long long)tv.tv.sec)*1000)+(tv.tv_usec/1000);
}*/
        int *createArray(unsigned int length, int value)
{
    int *array = (int *)malloc(length * sizeof(int));
    if (array == NULL) //als Safety-Maßnahme
    {
        return NULL;
    }
    for (unsigned int i = 0; i < length; ++i)
    {
        array[i] = value;
    }
    return array;
}

void printArray(int *array, unsigned int length)
{
    for (unsigned int i = 0; i < length; ++i)
    {
        printf("%d\n", array[i]);
    }
}

int main() {

    int num_elements = 10;
    //to initalize random-generator, um Zufaelligkeit zu gewäehrleisten (Zeitstempel wird uebergeben)
    srand(time(NULL));
    for (int i = 0; i<10; i++)
    {
        int number = rand() %50;
        printf("%d ", number);
        int *array = createArray(num_elements, number);
    }
    printf("\n");
    printArray(array, num_elements);
    return 0;
}