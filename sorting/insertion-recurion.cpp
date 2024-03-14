#include<iostream>
using namespace std;

void insertion_usingrecursion(int arr[],int n){
    if (n<=1)
    {
        return;
    }
    insertion_usingrecursion(arr,n-1);

     int pxy = arr[n-1];
        int j = n-2;
        while (pxy>arr[j] && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=pxy;
    return ;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    insertion_usingrecursion(arr,n);
     for (size_t i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}