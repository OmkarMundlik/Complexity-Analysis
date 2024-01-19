/*
    Name : Omkar Umesh Mundlik
    Class: AI-B
    Roll Number : 34

    Assignment based on Searching and Sorting
        1. WAP to implement linear search
        2. WAP to implement binary search
        3. WAP to implement selection sort
        4. WAP to implement insertion sort
*/

#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &arr, int target)
{
    int i = 0, j = arr.size() - 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }
    return -1;
}

int linearSearch(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int mini = i, Min = arr[i];
        for (int j = i; j < n; j++)
        {
            if (arr[j] < Min)
            {
                Min = arr[j];
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }
    return;
}

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int size, target;

    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Selection Sort\n";
        cout << "4. Insertion Sort\n";
        cout << "5. Print Array\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the target for linear search: ";
            cin >> target;
            int res = linearSearch(arr, target);
            if (res == -1)
            {
                cout << "Element not found" << endl;
            }
            else
            {
                cout << "Target element's index: " << res << endl;
            }
            break;
        }

        case 2:
        {
            cout << "Enter the target for binary search: ";
            cin >> target;
            int res = binarySearch(arr, target);
            if (res == -1)
            {
                cout << "Element not found" << endl;
            }
            else
            {
                cout << "Target element's index: " << res << endl;
            }
            break;
        }

        case 3:
        {
            selectionSort(arr);
            cout << "Array after Selection Sort:\n";
            for (auto i : arr)
            {
                cout << i << " ";
            }
            cout << endl;
            break;
        }

        case 4:
        {
            insertionSort(arr);
            cout << "Array after Insertion Sort:\n";
            for (auto i : arr)
            {
                cout << i << " ";
            }
            cout << endl;
            break;
        }

        case 5:
        {
            cout << "Array: ";
            for (auto i : arr)
            {
                cout << i << " ";
            }
            cout << endl;
            break;
        }

        case 6:
        {
            cout << "Exiting program. Goodbye!\n";
            break;
        }

        default:
        {
            cout << "Invalid choice. Please enter a valid option.\n";
        }
        }

    } while (choice != 6);

    return 0;
}
