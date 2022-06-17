#include <bits/stdc++.h>
using namespace std; 

unsigned t, t1;

int partition(int A[],int p,int r) { 
	int pivot=A[r];
	int i=p-1;
	for (int j=p;j<=r-1;j++) { 
		if (A[j]<pivot) { 
			i+=1; 
			swap<int>(A[i],A[j]); 
		} 
	} 
	swap<int>(A[i+1],A[r]); 
	return i+1; 
}   

void insertionSort(int A[],int p,int r){
    for(int i=p+1;i<=r;i++){
        int value=A[i];
        int j=i;
        while(j>p && A[j-1]>value){
            A[j]=A[j-1];
            j--;
        }
        A[j]=value;
    }
}

void quicksortOpimizado(int A[],int p,int r){
    while(p<r){
        if(r-p<10){
            insertionSort(A,p,r);
            break;
        }else{
            int pivot=partition(A,p,r);
            if(pivot-p<r-pivot){
                quicksortOpimizado(A,p,pivot-1);
                p=pivot+1;
            }else{
                quicksortOpimizado(A,pivot+1,r);
                r =pivot-1;
            }
        }
    }
}

void imprimir(int A[],int n) {
	for (int i=0;i<n;i++) 
		cout<<A[i]<<", "; 
	cout<<endl; 
} 

int main(){
    srand(time(NULL));
    int n=10;
    int A[n];
    for(int i=0;i<n;i++){
        A[i]=1+rand()%99;
    }

    imprimir(A,n);

    t=clock();
    quicksortOpimizado(A,0,n-1);
    t1=clock();
    
    imprimir(A,n);
    
    double time0=(double(t1-t)/CLOCKS_PER_SEC);
    cout<<"Tiempo: "<<time0<<endl;

    return 0;
} 