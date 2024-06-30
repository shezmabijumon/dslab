#include<stdio.h>
#include<stdlib.h>

void Display(int arr[], int n, char c[]);
void swap(int arr[], int i, int j);
void InsertionSort(int arr[], int n);
void SelectionSort(int arr[], int n);
void Heapify(int heapArr[], int len, int i);
void HeapSort(int arr[], int n);
void MergeSort(int arr[], int lb, int ub);
void Merge(int arr[], int lb, int mid, int ub);
void QuickSort(int arr[], int lb, int ub);
int partition(int arr[], int lb, int ub);

void main() {
    printf("SORTING\n");
    FILE *fp = fopen("sort.txt", "r");
    int arr[30], temp[30];
    int size = 0;
    printf("Contents in the file\n");
    while (!feof(fp)) {
        fscanf(fp, "%d\n", &arr[size++]);
        printf("%d ", arr[size - 1]);
    }
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    printf("\nMENU\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection sort\n");
    printf("3. Heap sort\n");
    printf("4. Merge sort\n");
    printf("5. Quick sort\n"); 
    int choice;
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        for (int i = 0; i < size; i++) {
            arr[i] = temp[i];
        }
        switch (choice) {
            case 1:
                Display(arr, size, "Unsorted List");
                InsertionSort(arr, size);
                Display(arr, size, "Sorted list");
                break;
            case 2:
                Display(arr, size, "Unsorted List");
                SelectionSort(arr, size);
                Display(arr, size, "Sorted list");
                break;
            case 3:
                Display(arr, size, "Unsorted List");
                HeapSort(arr, size);
                Display(arr, size, "Sorted list");
                break;
            case 4:
                Display(arr, size, "Unsorted List");
                MergeSort(arr, 0, size - 1);
                Display(arr, size, "Sorted list");
                break;
            case 5:    
                Display(arr, size, "Unsorted List");
                QuickSort(arr, 0, size - 1);
                Display(arr, size, "Sorted list");
                break;
        }
    } while (choice < 6);
}
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void Display(int arr[], int n, char c[]) {
    printf("%s: ", c);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void SelectionSort(int arr[], int n) {
    int min, index;
    for (int i = 0; i < n; i++) {
        min = arr[i];
        index = i;
        for (int j = i; j < n; j++) {
            if (min > arr[j]) {
                index = j;
                min = arr[j];
            }
        }
        swap(arr, index, i);
    }
}
void InsertionSort(int arr[], int n) {
    int temp;
    for (int i = 1; i < n; i++) {
        temp = arr[i];
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] <= temp)
                break;
            swap(arr, j + 1, j);
        }
    }
}
void Heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    while (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    while (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(arr, i, largest);
        Heapify(arr, n, largest);
    }
}
void HeapSort(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        Heapify(arr, n, i);
    }
    for (i = n - 1; i >= 0; i--) {
        swap(arr, 0, i);
        Heapify(arr, i, 0);
    }
}
void MergeSort(int arr[], int lb, int ub) {
    if (lb == ub)
        return;
    int mid = (lb + ub) / 2;
    MergeSort(arr, lb, mid);
    MergeSort(arr, mid + 1, ub);
    Merge(arr, lb, mid, ub);
}
void Merge(int arr[], int lb, int mid, int ub) {
    int a[30];
    int i = lb;
    int j = mid + 1;
    int k = lb;
    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j]) {
            a[k] = arr[i];
            i++;
        } 
        else {
            a[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
        while (j <= ub) {
            a[k] = arr[j];
            j++;
            k++;
        }
    } 
    else {
        while (i <= mid) {
            a[k] = arr[i];
            i++;
            k++;
        }
    }
    for (k = lb; k <= ub; k++) {
        arr[k] = a[k];
    }
}
void QuickSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(arr, lb, ub);
        QuickSort(arr, lb, loc - 1);
        QuickSort(arr, loc + 1, ub);
    }
}
int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while (start < end) {
        while (arr[start] <= pivot) {
            start++;
        }
        while (arr[end] > pivot) {
            end--;
        }
        if (start < end) {
            swap(arr, start, end);
        }
    }
    swap(arr, lb, end);
    return end;
}