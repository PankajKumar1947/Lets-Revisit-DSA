#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


//13.Suduko Solver
bool isValid(vector<vector<char>> &board, int row, int col, char c){
    //cheking all three condition in single iteration.
    for(int i=0;i<9;i++){
        if(board[i][col]==c)//checking the column
         return false;
        if(board[row][i]==c)//checking the row
         return false;
        //checking the 3*3 matrix
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
          return false;
    }
    return true;
}
bool solve(vector<vector<char>> &board){
    //traversing the matrix.
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='.')//insert position
            {
                for(char c='1';c<='9';c++){
                    if(isValid(board,i,j,c)){
                      board[i][j]=c;

                    if(solve(board)==true)
                      return true;
                    else
                      board[i][j]='.';
                    }
                }
                return false;
            }
            
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
        solve(board);
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

//14. Finding kth bit in binary String:
/*
Given two positive integers n and k, the binary string Sn is formed as follows:

S1 = "0"
Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

For example, the first four strings in the above sequence are:

S1 = "0"
S2 = "011"
S3 = "0111001"
S4 = "011100110110001"
Return the kth bit in Sn. It is guaranteed that k is valid for the given n.
*/
string invert(string str){
    for(int i=0;i<str.length();i++){
        if(str[i]=='0')
          str[i]='1';
        else
          str[i]='0';
    }
    return str;
}
string rev(string str){
    reverse(str.begin(),str.end());
    return str;
}

string formString(int n){
   if(n==1)
     return "0";
    return (formString(n-1)+ "1" +rev(invert(formString(n-1))));
}
int main(){
    string str=formString(4);
    cout<<str;
    return 0;
}

