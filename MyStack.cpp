#include<iostream>
#include<stack>
using namespace std;


class MyStack{
	int currsize,maxsize;
	int* arr;
public:
	MyStack() 
    { 
        arr=new int[1]; 
        maxsize=1; 
	    currsize=0; 
    }
    void push(int item){ 
        if (currsize==maxsize){ 
            int* temp = new int[2*maxsize];
            for (int i=0;i<maxsize;i++){ 
                temp[i]=arr[i]; 
            }
            delete[] arr; 
            maxsize=maxsize*2; 
            arr=temp; 
        }
        arr[currsize]=item; 
        currsize++; 
    }
    int pop(){
    	int x;
    	x=arr[currsize-1];
    	currsize--;
    	return x;
    }
	int peek(){
		return arr[currsize-1];
	}
	bool empty(){
		if(currsize==0){
			return true;
		}
		else{
			return false;
		}
	}
};