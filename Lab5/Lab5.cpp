#include <iostream>
#include <vector>
using namespace std;
// Majority Element in array
int majorityElement(vector<int>& nums, int low, int high) {
    if (low == high) {
        return nums[low];
    }
    int mid = low + (high - low) / 2;
    int leftMajority = majorityElement(nums, low, mid);
    int rightMajority = majorityElement(nums, mid + 1, high);

    if (leftMajority == rightMajority) {
        return leftMajority;
    }

    int leftCount = 0, rightCount = 0;
    for (int i = low; i <= high; ++i) {
        if (nums[i] == leftMajority) {
            leftCount++;
        } else if (nums[i] == rightMajority) {
            rightCount++;
        }
    }

    return (leftCount > rightCount) ? leftMajority : rightMajority;
}

//Kth Smallest element in array
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low + (high - low) / 2];
    int i = low - 1, j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        std::swap(arr[i], arr[j]);
    }
}
int kthSmallestElement(std::vector<int>& arr, int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int partitionIndex = partition(arr, low, high);
    int elementsInLeft = partitionIndex - low + 1;

    if (k == elementsInLeft) {
        return arr[partitionIndex];
    } else if (k < elementsInLeft) {
        return kthSmallestElement(arr, low, partitionIndex, k);
    } else {
        return kthSmallestElement(arr, partitionIndex + 1, high, k - elementsInLeft);
    }
}

int main() {

    // Code for Running Majority Element in array.
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array separated by spaces: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = majorityElement(nums, 0, nums.size() - 1);
    cout << "Majority Element: " << result << endl;


    // Code for running kth smallest element in array!

    std::cout << "Enter the number of elements in the array: ";
    n;
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array separated by spaces: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int k;
    std::cout << "Enter the value of k: ";
    std::cin >> k;

    result = kthSmallestElement(arr, 0, arr.size() - 1, k);
    std::cout << "The " << k << "th smallest element is: " << result << std::endl;

    return 0;
}
