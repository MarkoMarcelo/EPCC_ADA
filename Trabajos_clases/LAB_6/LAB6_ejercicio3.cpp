#include <iostream>
#include <ctime>
using namespace std; 

unsigned t, t1;

void partition(int A[],int a,int b,int& i,int& j){
    i=a-1,j=b;
    int p=a-1, q=b;
    int v=A[b];
 
    while(true){
        while(A[++i] < v);
        while(v<A[--j])
            if(j==a) break;
        if(i>=j) break;
        swap(A[i],A[j]);
        if(A[i]==v){
            p++;
            swap(A[p],A[i]);
        }
        if(A[j]==v){
            q--;
            swap(A[j],A[q]);
        }
    }
    swap(A[i],A[b]);
    j=i-1;
    for(int k=a;k<p;k++,j--)
        swap(A[k],A[j]);
    i=i+1;
    for (int k=b-1;k>q;k--,i++)
        swap(A[i], A[k]);
}

void quicksort(int A[],int p,int r){ 
	if(r<=p) return;
	int i,j;
	partition(A,p,r,i,j);
	quicksort(A,p,j);
    quicksort(A,i,r);
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
    quicksort(A,0,n-1);
    t1=clock();
    
    imprimir(A,n);
    
    double time0=(double(t1-t)/CLOCKS_PER_SEC);
    cout<<"TIME: "<<time0<<endl;

    return 0;
} 