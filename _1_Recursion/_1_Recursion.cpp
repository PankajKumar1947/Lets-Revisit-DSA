#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

//storing natural numbers in a vector using recursion
void storeNaturalNo(int n,vector<int> &vect){
    if(n==0){
        return ;
    }
    storeNaturalNo(n-1,vect);
    vect.push_back(n);
}
//storing natural numbers by making return type vector.
vector<int> store(int n){
    if(n<=0)
      return {};
    vector<int> temp=store(n-1);
    temp.push_back(n);
    return temp;
}
//reverse store return type void
void reverseStore(int n, vector<int> &vect){
    if(n==0)
      return ;
    vect.push_back(n);
    reverseStore(n-1,vect);
}
//reverse store return type vector


//find binary of a number
void findBinary(int n,vector<int> &ans){
    if(n==0)
      return ;
    findBinary(n/2,ans);
    ans.push_back(n%2);  
}
//finding reverse of a number using recursion
int reverseNumber(int num) {
    if (num < 10) {
        return num;
    } else {
        int lastDigit = num % 10;
        int remainingDigits = num / 10;
        int numDigits = 0;
        int temp = remainingDigits;

        while (temp > 0) {
            temp /= 10;
            numDigits++;
        }

        return lastDigit * pow(10, numDigits) + reverseNumber(remainingDigits);
    }
}

int main(){
    vector<int> test;
    int n=25;
    // storeNaturalNo(n,test);
    //reverseStore(n,test);

    // findBinary(n,test);
    // for(int i=0;i<test.size();i++)
    //   cout<<test[i]<<" ";
     

    //calling a reverse function.
    cout<<"After reversing the number "<<reverseNumber(n);
    return 0;
}
//day-1 completed