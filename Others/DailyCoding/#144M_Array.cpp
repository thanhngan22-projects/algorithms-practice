/*
Given an array of numbers and an index i, return the index of the nearest larger number of the number at index i, where distance is measured in array indices.

For example, given [4, 1, 3, 5, 6] and index 0, you should return 3.

If two distances to larger numbers are the equal, then return any one of them. If the array at i doesn't have a nearest larger integer, then return null.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// cách 1: dùng mảng thường
int nearestLargerNumber (int arr[] , int n, int i) {
    int min = 1;
    for (int j = 0; j < n ; j++) {
        if (arr[j] > arr[i]) {
            if (arr[j] - arr[i] == 1) {
                return j;
            } else {
                if (min < arr[j] - arr[i]) {
                    min = arr[j] - arr[i];
                }
            }
        }
    }
    for (int j = 0; j < n ; j++) {
        if (arr[j] - arr[i] == min) {
            return j;
        }
    }
    return -1;
}

// cách 2: dùng vector
int nearestLargerNumber (vector <int> v, int i) {
    vector <int> duplicate = v;
    sort(duplicate.begin(), duplicate.end());

    int value = v[i];
    int element;
    int k ;
    for (k = 0; k < v.size(); k++) {
        if (duplicate[k] > value) {
            element = duplicate[k];
            break;
        }
    }
    if (k == v.size()) {
        return -1;
    } else {
        for (int j = 0; j < v.size(); j++) {
            if (v[j] == element) {
                return j;
            }
        }
    }

}

int main() {
    int arr[] = {4, 1, 3, 5, 6};
    int arr2[] = {4, 1, 3, 5, 6, 7, 8, 12, 33, 58, 69, 22, 14, 9, 6};

    int n = sizeof(arr) / sizeof(arr[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << nearestLargerNumber(arr, n, 0) << endl;
    cout << nearestLargerNumber(arr2, n2, 6) << endl;

    vector <int> v = {4, 1, 3, 5, 6};
    vector <int> v2 = {4, 1, 3, 5, 6, 7, 8, 12, 33, 58, 69, 22, 14, 9, 6};

    cout << nearestLargerNumber(v, 0) << endl;
    cout << nearestLargerNumber(v2, 6) << endl;


    return 225;

}