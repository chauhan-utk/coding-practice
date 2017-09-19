/*
Problem statement: http://practice.geeksforgeeks.org/problems/n-queen-problem/0
*/

#include <bits/stdc++.h>
using namespace std;
#define vvii vector<vector<int> >
int N;
int cnt;

void printSol(vvii board){
    cnt++;
    cout<<"[";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board.at(j).at(i))
            {
                cout<<j+1<<" ";
            }
        }
    }
    cout<<"] ";
}

bool isSafe(vvii board, int row, int col){
    int i, j;
    //check current row
    for(i=0;i<col;i++) if(board.at(row).at(i)) return false;
    //check upper diagonal
    for(i=row, j=col;i>=0 and j>=0;i--,j--){
        if(board.at(i).at(j)) return false;
    }
    //check lower diagonal
    for(i=row,j=col;i<N and j>=0;i++,j--){
        if(board.at(i).at(j)) return false;
    }
    return true;
}

void solveNQ(vvii board, int col){
    if(col == N){
        //solution found. current board is a solution.
        printSol(board);
        return;
    }
    for(int j=0;j<N;j++){
        if(isSafe(board, j, col)){
            board.at(j).at(col)=1;
            solveNQ(board, col+1);
            board.at(j).at(col)=0;
        }
    }
    return;
}

int main() {
	int t; cin>>t;
	while(t--){
	  cin>>N;
	  cnt=-1;
	  vvii board(N, vector<int>(N, 0));
	  solveNQ(board, 0);
	  //cout<<isSafe(board, 3, 3);
	  if(cnt==-1) cout<<"-1";
	  cout<<"\n";
	}
	return 0;
}
