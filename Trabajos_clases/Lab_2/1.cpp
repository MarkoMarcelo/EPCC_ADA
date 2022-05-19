#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void MERGESORT(int*,int,int);
void merge(int*,int,int,int);
void Array(int*,int);

int main(){
    srand(time(NULL));
    int arr[500];
    for(int i=0;i<500;i++)
        arr[i]=rand()%250;
    Array(arr,500);
    MERGESORT(arr,0,500);
    Array(arr,500);
    return 0;
}

void MERGESORT(int arr[],int p,int r){
    if(p<r){
        int q=(p+r)/2;
        MERGESORT(arr,p,q);
        MERGESORT(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

void merge(int arr[],int p,int q,int r){
    int n1,n2,i,j,k; 
    n1=q-p+1;
    n2=r-q;             
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i]=arr[p+i];
    for(j=0;j<n2;j++)
        R[j]=arr[q+j+1];
    i=0,j=0;
    for(k=p;i<n1&&j<n2;k++){
        if(L[i]<R[j])
            arr[k]=L[i++];
        else
            arr[k]=R[j++];
    }
    while(i<n1)
        arr[k++]=L[i++];
    while(j<n2)
        arr[k++]=R[j++];
}

void Array(int arr[], int n){
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}