#include<iostream>
#include<vector>
using namespace std;

//finding sum of natural number
int sum(int n){
    if(n==1)
      return 1;
    return n+sum(n-1);
} 

//finding sum of a digit of a given number
int findSum(int n){
    if(n==0)
      return 0;
    return n%10 + findSum(n/10);
}

//finding number of digits in a given number
int countDigits(int n){
    if(n==0)
      return 0;
    return 1+countDigits(n/10);
}

//power of a number 
float power(int x,int y){
    if(y==0)
      return 1;
    if(y>0)
      return x*power(x,y-1);
    else
      return (power(x,y+1))/x;
}

//printing fibonacci of a number
int fib(int n){
    if(n==0 || n==1)
      return n;
    return fib(n-1)+fib(n-2);
}
void printFib(int n){
    if(n==0){
        cout<<n<<" ";
        return ;
    }
    else
      printFib(n-1);
      cout<<fib(n)<<" ";
}

//finding hcf using euclid division lemma
int findHCF(int a,int b){
    if(a>b){
        if(a%b==0)
          return b;
        return findHCF(a%b,b);
    }
    else{
        if(b%a==0)
          return a;
        return findHCF(b%a,a);
    }
}
//finding lcm using recursion
int findLCM(int a, int b){
    //think
}
int main(){
    vector<int> vect;
    int n=1;
    // cout<<"Sum of first "<<n<<" Natural numbers "<<sum(n);
    // cout<<"Sum of digits of "<<n<<" is "<<findSum(n);
    // cout<<"The number of digits present in "<<n<<" is "<<countDigits(n);
    // cout<<"Power="<<power(50,-1);
    // printFib(10);
    cout<<"The HCF="<<findHCF(270,70);
    return 0;
}

//day-2 completed