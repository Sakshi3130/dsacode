#include<iostream>
using namespace std;
void max_heap(int a[],int n,int i){
    int temp;
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && a[largest]<a[left]){
        largest=left;
    }
    if(right<n &&a[largest]<a[right]){
        largest=right;
    }
    if(largest!=i){
        temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;
        max_heap(a,n,largest);
    }
}

void min_heap(int a[], int n, int i) {
    int temp;
    int smallest = i;
    int left = 2 * i+1;
    int right = 2 * i + 2;

    if (left < n && a[smallest] > a[left]) {
        smallest = left;
    }
    if (right < n && a[smallest] > a[right]) {
        smallest = right;
    }
    if (smallest != i) {
        temp = a[smallest];
        a[smallest] = a[i];
        a[i] = temp;
        min_heap(a, n, smallest);
    }
}


int main(){
    int k;
    cout<<"Enter the size of array: "<<endl;
    cin>>k;
    int arr[k];
    cout<<"Enter elements: "<<endl;
    for(int i = 0;i<k;i++){
        cin>>arr[i];
    }
    
    for(int i = k/2;i>=0;i--){
        max_heap(arr,k,i);
    }
    cout<<"max heap: "<<endl;
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i = k/2;i>=0;i--){
        min_heap(arr,k,i);
    }
    cout<<"min heap: "<<endl;
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}