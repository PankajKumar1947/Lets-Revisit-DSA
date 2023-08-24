#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//11. Permutation:Return answer in any oreder.
void recurPermute(vector<int> &ds,vector<int> &nums,vector<vector<int>> &ans, int freq[]){
    if(ds.size()==nums.size()){
        ans.push_back(ds);
        return ;
    }
    for(int i=0;i<nums.size();i++){
        if(!freq[i])//if checking if the map is marked or not : if it is unmarked(0), then code inside if condition will run
        {
           ds.push_back(nums[i]);//pushing ith element in ds
           freq[i]=1;//marking during going
           recurPermute(ds,nums,ans,freq);
           freq[i]=0;//unmarking during returning  
           ds.pop_back();//taking last pushedelemnt during returning .
        }
    }
}
vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>>ans;
    vector<int> ds;
    int freq[nums.size()]={0};
    recurPermute(ds,nums,ans,freq);
    return ans;
}
//Time Complexity:O(n!*n)
//Space Complexity:O(n)+O(n)//one for ds and other for map. 


//11. method-2: Without using map.: Swap Method
void recurPermute2(int index,vector<int> &nums,vector<vector<int>> &ans){
    if(index==nums.size()){
        ans.push_back(nums);
        return ;
    }
    for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]);//during going we are change the postition of elements.
        recurPermute2(index+1,nums,ans);
        swap(nums[index],nums[i]);//during returning we are removing the changes we made during going.
    }
}
vector<vector<int>> permute2(vector<int> &nums){
    vector<vector<int>> ans;
    recurPermute2(0,nums,ans);
    return ans;
}
//Time complexity=O(n!*n)
//Space Complexity=O(n);



//12. N-Queens: Rule-1.Every row-1Q, 2.Every Column-1Q, and 3.None of the Q attack each other.
//method-1:
bool isSafe(int row,int col, vector<string>board, int n){
    //checking upperDiognal
    int duprow=row;
    int dupcol=col;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q')
          return false;
        row--;
        col--;
    }

    //checking for left position.
    col=dupcol;
    row=duprow;
    while(col>=0){
        if(board[row][col]=='Q')
         return false;
        col--;
    }

    //checking for the right position.
    row=duprow;
    col=dupcol;
    while(row<n && col>=0){
        if(board[row][col]=='Q')
          return false;
        row++;
        col--;
    }
    return true;
}
void solve(int col,vector<string>&board,vector<vector<string>> &ans,int n){
    if(col==n){
        ans.push_back(board);
        return ;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';//marking if the position is safe.
            solve(col+1,board,ans,n);
            board[row][col]='.';//during returning unmarking
        }
    }
}
vector<vector<string>> solveNQueen(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i]=s;//assigning each element of board by .
        cout<<board[i]<<" ";
    }
    

    solve(0,board,ans,n);
    return ans;
}


//Function to print 2d matrix
void print2D(vector<vector<string>> test){
    //printing 2-D Array
    for(int i=0;i<test.size();i++){
        cout<<"[ ";
        for(int j=0;j<test[0].size();j++){
        }
        cout<<"]";
    }
}
int main(){
    vector<int> nums={1,2,3};
    vector<vector<int>> ans;
    
    // ans=permute2(nums);//11. Calling permute function
    // print2D(ans);

    vector<vector<string>> ans_12;
    ans_12=solveNQueen(3);
    print2D(ans_12);

  
    return 0;
}