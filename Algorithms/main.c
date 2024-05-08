#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 40000
int efficency = 0;

void fillArray(int array[])
{
    for(int i = 0; i < SIZE; ++i)
        array[i] = rand() % SIZE;
}

int checkArray(int array[])
{
    for(int i = 1; i < SIZE; ++i)
    {
        if(array[i] < array[i-1])
            return 0;
    }
    return 1;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int array[])
{
    bool swapped;
    int i, j;
    for(i = 0; i < SIZE - 1; ++i){
        swapped = false;
        for(j = 0; j < SIZE - i - 1; ++j){
            efficency++;
            if(array[j] > array[j+1]){
                efficency++;
                swap(&array[j], &array[j+1]);
                swapped = true;
            }
        }
    if (swapped == false)
        break;
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        efficency++;
        if (array[j] < pivot) {
            i++;
            efficency++;
            swap(&array[i], &array[j]);
        }
    }
    efficency++;
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    efficency++;
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void error(int array[], char *text)
{
    printf("Error while sorting with pervious method.\n");
    FILE* fp;
    fp = fopen(text, "w");
    for(int i = 0; i < SIZE; ++i)
        fprintf(fp,"%d ", array[i]);
    fclose(fp);
}

void sortSelect(int x[], char* sort)
{
    int check = checkArray(x);
    if(check == 0)
        error(x,sort);
}

void replace(int a[], int b[])
{
    for(int i = 0; i < SIZE; ++i)
        a[i] = b[i];
}

void insertionSort(int array[])
{
    int i, key, j;
    for (i = 1; i < SIZE; i++) {
        efficency++;
        key = array[i]; //current element
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            efficency += 2;
            j = j - 1;
        }
        efficency++;
        array[j + 1] = key;
    }
}

void selectionSort(int array[])
{
    int i, j, key;
    for (i = 0; i < SIZE-1; i++)
    {
        key = i;    //minimum element
        for (j = i+1; j < SIZE; j++){
            efficency++;
            if (array[j] < array[key])
                key = j;
        }
        efficency++;
        if(key != i){
            efficency++;
            swap(&array[key], &array[i]);
        }
    }
}

void merge(int array[], int low, int half, int high)
{
    int i, j, k;
    int n1 = half - low + 1;
    int n2 = high - half;
    int left[n1], right[n2];

    for (i = 0; i < n1; i++){
        efficency++;
        left[i] = array[low + i];
    }
    for (j = 0; j < n2; j++){
        efficency++;
        right[j] = array[half + 1 + j];
    }

    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2) {
        efficency++;
        if (left[i] <= right[j]) {
            efficency++;
            array[k] = left[i];
            i++;
        }
        else {
            efficency++;
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        efficency++;
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        efficency++;
        array[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int array[],int low, int high)
{
    efficency++;
    if (low < high) {
        int half = low + (high - low) / 2;
        mergeSort(array, low, half);
        mergeSort(array, half + 1, high);
        merge(array, low, half, high);
    }
}

int main()
{
    int x[SIZE], original[SIZE];
    srand(time(NULL));
    fillArray(x);

    FILE* fp;
    fp = fopen("OriginalArray.txt", "w");
    for(int i = 0; i < SIZE; ++i)
        fprintf(fp,"%d ", x[i]);
    fclose(fp);

    replace(original, x);
    clock_t begin = clock();
    bubbleSort(x);
    clock_t end = clock();
    double time_taken = (double)(end-begin)/CLOCKS_PER_SEC;

    sortSelect(x, "Error.txt");
    printf("Bubble sort efficency: %d; Time efficency: %f\n", efficency, time_taken);
    efficency = 0;


    replace(x, original);
    begin = clock();
    quickSort(x, 0, SIZE-1);
    end = clock();
    time_taken = (double)(end - begin)/CLOCKS_PER_SEC;

    sortSelect(x, "Error.txt");
    printf("Quick sort efficency: %d; Time efficency: %f\n", efficency, time_taken);
    efficency = 0;


    replace(x, original);
    begin = clock();
    insertionSort(x);
    end = clock();
    time_taken = (double)(end - begin)/CLOCKS_PER_SEC;

    sortSelect(x, "Error.txt");
    printf("Insertion sort efficency: %d; Time efficency: %f\n", efficency, time_taken);
    efficency = 0;


    replace(x, original);
    begin = clock();
    selectionSort(x);
    end = clock();
    time_taken = (double)(end - begin)/CLOCKS_PER_SEC;

    sortSelect(x, "Error.txt");
    printf("Selection sort efficency: %d; Time efficency: %f\n", efficency, time_taken);
    efficency = 0;


    replace(x, original);
    begin = clock();
    mergeSort(x, 0, SIZE-1);
    end = clock();
    time_taken = (double)(end - begin)/CLOCKS_PER_SEC;

    sortSelect(x, "Error.txt");
    printf("Merge sort efficency: %d; Time efficency: %f\n", efficency, time_taken);

    return 0;
}
