#include <bits/stdc++.h>
using namespace std;

void insertion(int arr[], int n)
{
    int pxy;
    for (int i = 1; i < n; i++)
    {
        pxy = arr[i];
        int j = i-1;
        while (pxy>arr[j] && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=pxy;
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
    insertion(arr, n);
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    return 0;
}
