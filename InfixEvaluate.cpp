#include<bits/stdc++.h> 
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

int prec(char c){ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
}

string infixToPostfix(string s){ 
    MyStack st; 
    st.push('N'); 
    int l = s.length(); 
    string ns; 
    for(int i=0;i<l;i++){
        if((s[i] >='0' && s[i]<='9')){ 
            if(i!=0 && (48>int(s[i-1]) || 57<int(s[i-1]))){
                ns+=' ';
            } 
            ns+=s[i];
        }
        else if(s[i]=='(')
        st.push('('); 
        else if(s[i]==')'){ 
            while(st.peek()!= 'N' && st.peek()!='('){ 
                char c=st.peek(); 
                st.pop(); 
                ns+=c; 
            } 
            if(st.peek()=='('){ 
                char c=st.peek(); 
                st.pop(); 
            } 
        } 
        else{ 
            while(st.peek()!='N' && prec(s[i])<=prec(st.peek())){ 
                char c = st.peek(); 
                st.pop(); 
                ns += c; 
            } 
            st.push(s[i]); 
        }
    }
    while(st.peek() != 'N'){ 
        char c = st.peek(); 
        st.pop(); 
        ns += c; 
    }
    return ns; 
} 

bool isint(char input){
    switch(input){
    case '1':
        return true;
    case '2':
        return true;
    case '3':
        return true;
    case '4':
        return true;
    case '5':
        return true;
    case '6':
        return true;
    case '7':
        return true;
    case '8':
        return true;
    case '9':
        return true;
    case '0':
        return true;
    }
    return false;
}



bool oprtr(char input) 
{ 
    switch (input) { 
    case '+': 
        return true; 
    case '-': 
        return true; 
    case '*': 
        return true; 
    case '^': 
        return true; 
    case '/': 
        return true; 
    case '(': 
        return true; 
    } 
    return false; 
} 

int evaluate(string s){
    string num="";
    MyStack st;
    for(int i=0;i<s.length();i++){
        if(isint(s[i])){
            num+=s[i];
        }
        else if(s[i]==' '){
            if(num!=""){
                st.push(stoi(num));
                num="";
            }
        }
        else if(oprtr(s[i])){
            if(num!=""){
                st.push(stoi(num));
                num="";
            }
            int x=st.peek();
            st.pop();
            int y=st.peek();
            st.pop();
            switch(s[i]){
                case '-':
                st.push(y-x);
                break;
                case '+':
                st.push(x+y);
                break;
                case '*':
                st.push(x*y);
                break;
                case '/':
                st.push(y/x);
                break;
                case '^':
                st.push((int)(pow(y,x)));
                break;
            }
        }
    }
    return st.peek();
}

int main(){
    string s="56+4^(3^(2)-1)";
    cout<<evaluate(infixToPostfix(s));
}