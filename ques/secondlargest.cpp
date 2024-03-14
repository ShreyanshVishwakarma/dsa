// find second largest and smallest(optional) element in an array

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int largest = arr[0];
    int slargest = arr[1];
    for (size_t i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > slargest)
        {
            slargest = arr[i];
        }
    }
    cout << "largest element is " << largest << endl;
    cout << "second largest element is " << slargest << endl;
}