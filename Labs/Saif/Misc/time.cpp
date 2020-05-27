#include<iostream>
#include<string>
#include<ctime>
#include<chrono>

using namespace std;    

int main(void){

    int openTime;
    int closeTime;
    int orderTime;
    string Rest;

    cout << "Enter Open Time: " <<endl;
    cin >> openTime;

    cout << "Enter Close Time: " <<endl;
    cin >> closeTime;

    cout << "Enter Order Time: " <<endl;
    cin >> orderTime;

   if(openTime > closeTime){
	    if(((orderTime >= openTime) && (orderTime > closeTime)) || ((orderTime < openTime) && (orderTime <= closeTime))){
	    	Rest = "Open";
	    }
        if((orderTime >= openTime) && (orderTime <= closeTime)){
	    	Rest = "Open";
	    }	
        else{
            Rest = "Close";
        }

	    
        }
   }

    cout << "Restaurant is: " << Rest;
}