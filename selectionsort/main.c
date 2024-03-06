#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size) {
    int swaps=0;
    int comparisons=0;
    for (int step = 0; step < size-1 ; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            comparisons ++;
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        swap(&array[min_idx], &array[step]);
        swaps++;
    }
    printf("\nVertauschungen: %d",swaps);
    printf("\nVergleiche: %d",comparisons);

}


void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
}

int main() {
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);
    printf("Array unsortiert: ");
    printArray(data, size);
    selectionSort(data, size);
    printf("\nArray in aufsteigender Reihenfolge: ");
    printArray(data, size);
}