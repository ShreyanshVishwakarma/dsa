#include<iostream>

int binarySearch(int* arr, int size,int key){
    int start = 0;
    int end = size-1;

    while (start<=end)
    {
    int mid = start + (end-start)/2;
        if (arr[mid]==key)
        {
            return mid;
        }
        if (arr[mid] < key)
        {
            start = mid +1;
        }
        else{
            end = mid - 1;
        }  
    }
    return -1;
    
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int index = binarySearch(arr,sizeof(arr)/sizeof(arr[0]),10);
    std::cout<<arr[index]<<" is found on index "<<index<<std::endl;
    return 0;
}

