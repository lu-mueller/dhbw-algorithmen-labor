#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int counter = 0;

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
        printf("%d, ", array[i]);
    }
}

int getRandomNumber()
{
    //to initalize random-generator, um Zufaelligkeit zu gewäehrleisten (Zeitstempel wird uebergeben)
    srand(time(NULL));
    int number = rand() % 50;
    return number;
}
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
bool is_sorted(int *a, int n)
{


    //schaut ob die elemente gesorted sind
    while ( --n >= 1 ) {    //ziehe 1 von der laenge ab, schaue if >= 1
        if ( a[n] < a[n-1] ) return false;  //wenn 2. element kleiner dann unsorted
    }
    return true;
}

void shuffle(int *a, int n)
{
    counter++;
    int i, t, r;
    for(i=0; i < n; i++) {
        t = a[i];
        r = rand() % n;
        a[i] = a[r];
        a[r] = t;
    }
}
void bogosort(int *a, int n)
{
    while ( !is_sorted(a, n) ) shuffle(a, n);   //wenn nicht gesorted, shuffle
}

int *createRandomArray(unsigned int length)
{
    srand(time(NULL));

    int *array = (int *)malloc(length * sizeof(int));
    if (array == NULL) //als Safety-Maßnahme
    {
        return NULL;
    }
    for (unsigned int i = 0; i < length; ++i)
    {
        int number = rand() %500;
        //printf("%d ", number);
        array[i] = number;
    }
    return array;
}

int main() {
    int length = 11;
    //int *array = (int *)malloc(length * sizeof(int));
    double startzeit;
    startzeit = clock();
    int *unsortedarray = createRandomArray(length);
    printArray(unsortedarray,length);
    //printf("Time fuer unsorted %5.3f \n", (clock()-startzeit)/1000);

    // printArray(array, length);
    printf("\n");
    startzeit = clock();
    bubbleSort(unsortedarray, length);
    printf("Time fuer bubble sort %5.3f \n", (clock()-startzeit)/1000);
    printArray(unsortedarray, length);

    printf("\n");
    startzeit = clock();
    bogosort(unsortedarray, length);
    printf("Anzahl von shuffles: %i \n ", counter);
    printf("Time fuer bogo sort %5.3f \n", (clock()-startzeit)/1000);
    printArray(unsortedarray, length);
    printf("done");


    //printf("\n");
    //printArray(array, length);
    return 0;
}