//find the largest element in an array

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (size_t i = 1; i < n; i++)
    {
        cin>>arr[i];
    }
    
    int largest=arr[0];
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i]>largest)
        {
            largest=arr[i];
        }
    }
    cout<<"largest element is "<<largest;
    return 0;
}