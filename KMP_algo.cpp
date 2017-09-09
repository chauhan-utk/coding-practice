#include <bits/stdc++.h>
using namespace std;

vector<int> computelps(string str){
    vector<int> res(str.size(),0);
    int i=1;
    int j=0;
    while(i<str.size()){
        if(str.at(i)==str.at(j)){
            res.at(i) = j+1;
            j++;
            i++;
        }
        else{
            if(j!=0){ j = res.at(j-1); }
            else{ res.at(i) = 0; i++; }
        }
    }
    return res;
}

bool KMP(string str, string pattern){
    vector<int> lps=computelps(pattern);
    int i=0, j=0;
    while(i<str.size() and j<pattern.size()){
        if(str.at(i) == pattern.at(j)){
            i++; j++;
        }
        else{
            if(j!=0){ j = lps.at(j-1); }
            else{ i++; }
        }
    }
    if(j == pattern.size())
        return true;
    
    return false;
}

int main() {
	
	string str = "abcxabcdabcdabcy";
	string pattern = "abcdabcy";
	cout<<KMP(str,pattern);
	
	return 0;
}
