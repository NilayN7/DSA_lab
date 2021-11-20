#include<iostream>
using namespace std; 
  
class CircularQueue{
private:
    int r; 
    int f; 
    int size; 
    int *arr; 
public:
    CircularQueue(int k);
    int front();
    int rear();
    bool enqueue(int value);
    bool dequeue();
    bool isEmpty();
    bool isFull();
    
};


CircularQueue::CircularQueue(int k)
{ 
    f=-1;
    r=-1; 
    size=k; 
    arr=new int[k]; 
}

int CircularQueue::front()
{
    if(f==-1){
        return -1;
    }
    else{
        return arr[f];
    }
}

int CircularQueue::rear()
{
    if(f==-1){
        return -1;
    }
    else{
        return arr[r];
    }
}

bool CircularQueue::enqueue(int value)
{
    if ((f == 0 && r==size-1) || (r==(f-1)%(size-1))){
        return false; 
    }
    else if(f==-1){ 
        f=0;
        r=0; 
        arr[r]=value; 
    } 
    else if(r==size-1 && f!=0){ 
        r=0; 
        arr[r]=value; 
    } 
    else{ 
        r++; 
        arr[r] = value; 
    }
    return true;
}

bool CircularQueue::dequeue()
{
    if (f==-1){
        return false; 
    } 
    arr[f]=-1; 
    if (f==r){ 
        f=-1; 
        r=-1; 
    } 
    else if(f==size-1) 
        f=0; 
    else
        f++; 
    return true;
}

bool CircularQueue::isEmpty()
{
    if(f==-1)
        return true;
    else
        return false;
}

bool CircularQueue::isFull()
{
    if ((f == 0 && r==size-1) || (r==(f-1)%(size-1))){ 
        return true;
    }
    else{
        return false;
    }
}