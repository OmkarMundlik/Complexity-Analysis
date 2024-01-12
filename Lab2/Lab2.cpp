#include<bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(vector<int> arr){
    unordered_set<int> s;
    vector<int> ans;
    for(auto i : arr){
        if(s.find(i) == s.end()){
            ans.push_back(i);
        }
        s.insert(i);
    }
    return ans;
}

int upperRightTMatrixSum(vector<vector<int>> &matrix){

    int sum = 0;
    for(int i=0;i<matrix.size(); i++){
        for(int j=0;j<matrix.size()-i; j++){
            sum += matrix[i][j];
        }
    }
    return sum;
}

void printEvenNumbers(vector<int> &arr){
    for(auto i : arr){
        if(!(i&1)){
            cout << i << " " ;
        }
    }
    cout << endl;
}

int largestInLowerT(vector<vector<int>> &matrix){
    int Max = INT_MIN;
    for(int i=0;i<matrix.size(); i++){
        for(int j=0;j<=i; j++){
            Max = max(Max, matrix[i][j]);
        }
    }
    return Max;
}

int printLeftLower_RightLower(vector<vector<int>> &matrix){
    cout << "Left lower triangular Matrix : "<<endl;
    for(int i=0;i<matrix.size(); i++){
        for(int j=0;j<=i; j++){
            cout << matrix[i][j]<<" ";
        }
        for(int j=i+1; j<matrix.size(); j++){
            cout <<"0 ";
        }
        cout << endl;
    }

    cout << "Right lower triangular Matrix : "<<endl;  // 3x3
    for(int i=0;i<matrix.size(); i++){
        for(int j=0;j<matrix.size()-i-1; j++){
            cout << "0 ";
        }
        for(int j=matrix.size()-i-1; j<matrix.size(); j++){
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
}

int main()
{
    // vector<int> arr = {1,2,3,4,4,4,4,5,4,4,4,7,6,7,8};
    // arr = removeDuplicates(arr);
    // for(auto i : arr){
    //     cout << i << " " ;
    // }
    vector<vector<int>> m = {{1,2,3}, {4,5,6}, {6,7,8}};
    cout << "Original Matrix : " << endl;
    for(int i=0;i<m.size(); i++){
        for(int j=0;j<m.size(); j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    printLeftLower_RightLower(m);
    // cout << largestInLowerT(m);
    // printEvenNumbers(arr);
    return 0;
}

/*
1.WAP that identifies and removes duplicates from an array of size n.

2.WAP to print sum of upper right triangular matrix 

3.WAP to print all even number from given matrix

4.WAP to print largest element from lower triangle of matrix

5.WAP to print left lower and right lower triangle of matrix of size n*n
*/