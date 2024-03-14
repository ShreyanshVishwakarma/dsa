#include<bits/stdc++.h>

using namespace std;

void rotatebyk(int arr[], int d, int n)
{
    d = d % n;
    vector<int> temp;

    // Store the first 'd' elements in a temporary vector
    for (int i = 0; i < d; i++)
    {
        temp.push_back(arr[i]);
    }

    // Shift the remaining elements to the left by 'd' positions
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    // Copy the elements from the temporary vector back to the end of the array
    for (int i = 0; i < d; i++)
    {
        arr[n - d + i] = temp[i];
    }
}

// Now to solve it in O(1) space complexity

void rotateleft(int arr[], int d, int n)
{
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
    return ;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int d;
    cout << "Enter the number of places to rotate the array: ";
    cin >> d;

    rotateleft(arr, d, n);

    cout << "Rotated array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
