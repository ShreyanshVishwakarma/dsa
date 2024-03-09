#include <iostream>
using namespace std;
int first0cc(int *arr, int size, int key)
{
    int s = 0, e = size - 1, ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s);
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
    }
    return ans;
}
int last0cc(int *arr, int size, int key)
{
    int s = 0, e = size - 1, ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s);
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "first occurrence of 3 is at index " << first0cc(arr, sizeof(arr) / sizeof(arr[0]), 3) << endl;
    cout << "last occurrence of 3 is at index " << last0cc(arr, sizeof(arr) / sizeof(arr[0]), 3) << endl;
    return 0;
}
