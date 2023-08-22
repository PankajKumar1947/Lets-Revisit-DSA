#include<iostream>
#include<vector>
using namespace std;

//1.Reversing an array using recursion
void reverse(int i, vector<int> &temp){
    if(i>=temp.size()/2)
      return ;
      swap(temp[i],temp[temp.size()-1-i]);
    reverse(i+1,temp);
}

//2.Check if a string is a palindrome
bool checkPalindrom(int i,string &s){
    if(i>=s.size()/2)
      return true;
    if(s[i]!=s[s.size()-i-1])
      return false;
    return checkPalindrom(i+1,s);
}

//3. Print all Subsequences.
void printF(int ind,vector<int> &ds, int arr[],int n)
{
    if(ind==n){
        for(auto it:ds){
            cout<<it<<" ";
        }
        if(ds.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return ;
    }

    //not pick , or not take condition , this element is not added to your subsequnces.
    printF(ind+1,ds,arr,n);

    //take or pick the particular index into the subsequences
    ds.push_back(arr[ind]);
    
    printF(ind+1,ds,arr,n); 
    ds.pop_back();
}

//4.Printing Subsequnces whose sum is k
void printSum(int ind, vector<int> &ds, int s, int sum ,int arr[],int n)
{
    if(ind==n){
        if(s==sum){
        for(auto it:ds)
          cout<<it<<" ";
        cout<<endl;
        }
        return ;
    }
    ds.push_back(arr[ind]);
    s+=arr[ind];

    printSum(ind+1,ds,s,sum,arr,n);

    s-=arr[ind];
    ds.pop_back();

    //not pick
    printSum(ind+1,ds,s,sum,arr,n);
}

//5.Print any one subsequence in the ques-4
bool printOneSum(int ind, vector<int> &ds, int s, int sum ,int arr[],int n)
{
    if(ind==n){
        //condition satisfied
        if(s==sum){
        for(auto it:ds)
          cout<<it<<" ";
        cout<<endl;
        return true;
        }
        else
         return false;
    }
    ds.push_back(arr[ind]);
    s+=arr[ind];

    if(printOneSum(ind+1,ds,s,sum,arr,n)==true){
        return true;
    }

    s-=arr[ind];
    ds.pop_back();

    //not pick
    if(printOneSum(ind+1,ds,s,sum,arr,n)==true)
      return true;
    return false;
}

//6. Count number of subsequnces with sum=2;
int countSub(int ind,int s,int sum, int arr[],int n){
    //condition not satisfied
    if(s>sum)
      return 0;
    if(ind==n){
        //condition satisfied
        if(s==sum)
          return 1;
        else
          return 0;
    }
    s+=arr[ind];
    int l=countSub(ind+1,s,sum,arr,n);
    s-=arr[ind];

    //not pick
    int r=countSub(ind+1,s,sum,arr,n);
    return l+r;
}
int main(){
    vector<int> test={1,2,3};
    vector<vector<int>> ans;
    int n=3;
    int arr[n]={1,2,1};
    vector<int>ds;
    string str="madam";
    // reverse(0,test);//1.Reverse function call.

    // cout<<checkPalindrom(0,str);//2.CheckPalindrome function call

    //printF(0,ds,arr,n);//3.finding subsequences.
    
    int target=2;
    // printSum(0,ds,0,target,arr,n);//4. printSum() is called for printing all the subsequences whose sum is target.

    //printOneSum(0,ds,0,target,arr,n);//5. Printing only one subsequnces.

    cout<<countSub(0,0,target,arr,n);//6. Printing number of subsequnces wiht sum=target.




    //printing 1-D Array
    // for(int i=0;i<test.size();i++){
    //     cout<<test[i]<<" ";
    // }


    //printing 2-D Array
    // for(int i=0;i<ans.size();i++){
    //     cout<<"[ ";
    //     for(int j=0;j<ans[0].size();j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<" ]";
    // }
    return 0;
}

//day-3 completed