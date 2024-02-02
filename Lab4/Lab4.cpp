#include <iostream>
#include <cstdlib>
#include <ctime>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition_random(int arr[], int low, int high) {
    srand(time(NULL));
    int r = low + rand() % (high - low);
    swap(&arr[r], &arr[high]);
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

void quicksortwithPartitionRandom(int arr[], int low, int high) {
    if (low < high) {
        int p = partition_random(arr, low, high);
        quicksortwithPartitionRandom(arr, low, p - 1);
        quicksortwithPartitionRandom(arr, p + 1, high);
    }
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSortwithPivot(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSortwithPivot(array, low, pi - 1);
        quickSortwithPivot(array, pi + 1, high);
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    int data[n];

    std::cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
    }

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Quicksort with Random Partition\n";
        std::cout << "2. Quicksort with Pivot Partition\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                quicksortwithPartitionRandom(data, 0, n - 1);
                std::cout << "Sorted array with Random Partition: \n";
                printArray(data, n);
                break;

            case 2:
                quickSortwithPivot(data, 0, n - 1);
                std::cout << "Sorted array with Pivot Partition: \n";
                printArray(data, n);
                break;

            case 3:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }

    } while (choice != 3);

    return 0;
}
