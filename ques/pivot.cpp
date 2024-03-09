#include<iostream>
using namespace std;

int pivot(int* arr, int size) {
    int s = 0, e = size - 1;
    int mid;

    while (s < e) {
        mid = s + (e - s) / 2;

        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        } else if (arr[mid] < arr[0]) {
            e = mid;
        }
    }

    return s;
}

int main(int argc, char const* argv[]) {
    int arr[] = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    cout << pivot(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}
