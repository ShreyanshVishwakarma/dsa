#include <bits/stdc++.h>
using namespace std;

void selection(int arr[], int n)
{
    int min;
    int pxy;

    for (size_t i = 0; i <= n - 2; i++)
    {
        min = i;
        for (size_t j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        pxy = arr[min];
        arr[min] = arr[i];
        arr[i] = pxy;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selection(arr, n);
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    return 0;
}
