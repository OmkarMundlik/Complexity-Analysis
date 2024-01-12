/*
    Name : Omkar Umesh Mundlik
    Class: AI-B
    Roll Number : 34
    
    Assignment Programs : 
        1.WAP that identifies and removes duplicates from an array of size n.

        2.WAP to print sum of upper right triangular matrix

        3.WAP to print all even number from given matrix

        4.WAP to print largest element from lower triangle of matrix

        5.WAP to print left lower and right lower triangle of matrix of size n*n
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(vector<int> arr)
{
    unordered_set<int> s;
    vector<int> ans;
    for (auto i : arr)
    {
        if (s.find(i) == s.end())
        {
            ans.push_back(i);
        }
        s.insert(i);
    }
    return ans;
}

int upperRightTMatrixSum(vector<vector<int>> &matrix)
{ 
    /*
    00 01 02
    10 11 12
    20 21 22
    */

    int sum = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = matrix.size()-i-1; j < matrix.size(); j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

void printEvenNumbers(vector<int> &arr)
{
    for (auto i : arr)
    {
        if (!(i & 1))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int largestInLowerT(vector<vector<int>> &matrix)
{
    int Max = INT_MIN;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            Max = max(Max, matrix[i][j]);
        }
    }
    return Max;
}

int printLeftLower_RightLower(vector<vector<int>> &matrix)
{
    cout << "Left lower triangular Matrix : " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << matrix[i][j] << " ";
        }
        for (int j = i + 1; j < matrix.size(); j++)
        {
            cout << "0 ";
        }
        cout << endl;
    }

    cout << "Right lower triangular Matrix : " << endl; // 3x3
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size() - i - 1; j++)
        {
            cout << "0 ";
        }
        for (int j = matrix.size() - i - 1; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix;

    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Remove Duplicates from Array\n";
        cout << "2. Upper Right Triangle Matrix Sum\n";
        cout << "3. Print Even Numbers\n";
        cout << "4. Largest Element in Lower Triangle of Matrix\n";
        cout << "5. Print Left Lower and Right Lower Triangular Matrices\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                vector<int> arr;
                int n;
                cout << "Enter the number of elements in the array: ";
                cin >> n;
                cout << "Enter array elements: ";
                for (int i = 0; i < n; ++i) {
                    int element;
                    cin >> element;
                    arr.push_back(element);
                }
                vector<int> result = removeDuplicates(arr);
                cout << "Array after removing duplicates: ";
                for (int num : result) {
                    cout << num << " ";
                }
                cout << endl;
                break;
            }
            case 2: {
                int rows, cols;
                cout << "Enter the number of rows and columns for the matrix: ";
                cin >> rows >> cols;
                matrix.clear(); // Clear the existing matrix before taking input
                cout << "Enter matrix elements:\n";
                for (int i = 0; i < rows; ++i) {
                    vector<int> row;
                    for (int j = 0; j < cols; ++j) {
                        int element;
                        cin >> element;
                        row.push_back(element);
                    }
                    matrix.push_back(row);
                }
                int sum = upperRightTMatrixSum(matrix);
                cout << "Sum of upper right triangle elements: " << sum << endl;
                break;
            }
            case 3: {
                vector<int> arr;
                int n;
                cout << "Enter the number of elements in the array: ";
                cin >> n;
                cout << "Enter array elements: ";
                for (int i = 0; i < n; ++i) {
                    int element;
                    cin >> element;
                    arr.push_back(element);
                }
                cout << "Even numbers in the array: ";
                printEvenNumbers(arr);
                break;
            }
            case 4: {
                int rows, cols;
                cout << "Enter the number of rows and columns for the matrix: ";
                cin >> rows >> cols;
                matrix.clear(); // Clear the existing matrix before taking input
                cout << "Enter matrix elements:\n";
                for (int i = 0; i < rows; ++i) {
                    vector<int> row;
                    for (int j = 0; j < cols; ++j) {
                        int element;
                        cin >> element;
                        row.push_back(element);
                    }
                    matrix.push_back(row);
                }
                int maxInLowerT = largestInLowerT(matrix);
                cout << "Largest element in the lower triangle of the matrix: " << maxInLowerT << endl;
                break;
            }
            case 5: {
                int rows, cols;
                cout << "Enter the number of rows and columns for the matrix: ";
                cin >> rows >> cols;
                matrix.clear(); // Clear the existing matrix before taking input
                cout << "Enter matrix elements:\n";
                for (int i = 0; i < rows; ++i) {
                    vector<int> row;
                    for (int j = 0; j < cols; ++j) {
                        int element;
                        cin >> element;
                        row.push_back(element);
                    }
                    matrix.push_back(row);
                }
                printLeftLower_RightLower(matrix);
                break;
            }
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 6);

    return 0;
}

