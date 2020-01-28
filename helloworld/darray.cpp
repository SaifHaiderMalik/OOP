#include<iostream>
using namespace std;

int main(){
    int index=1, *array=new int[index]{0}, tot=0;

	do{
		cout<<"Enter a number to add: ";
		cin>>array[index];
        index++;
	}while (array[index-1]!=0);
	
	for (int i=0;i<index;i++){
        cout << array[i] << endl;
        tot+=array[i];
	}
	
	cout<<"Total: "<<tot<<endl;
	return 0;
}