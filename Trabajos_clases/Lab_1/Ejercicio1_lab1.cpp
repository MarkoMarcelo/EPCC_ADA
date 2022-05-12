#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int arr[] = {6,3,1,10,43};
	int i,key,j;
	
	for(i=0;i<5;i++){
		key = i; 
		j = arr[i];
		
		while((key>0) && (arr[key-1] > j)){
			arr[key] = arr[key-1];
			key--;
		}
		arr[key] = j;
	}
	
	cout<<"Insercion Sort";
	for(i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
        