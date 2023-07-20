//反转字符串
#include<iostream>
#include<vector>
using namespace std;
#include<string>
class Solution{
public :
    vector<char> reverse_string(vector<char> &st){
        int i = 0;
        int j = st.size()-1;
        while(i<=j){
            swap(st[i],st[j]);
            i++;
            j--;
        }
        return st;
    }
};
int main(){
    vector<char> st = {'a','b','c','d','e'};
    Solution solution;
    vector<char> new_st = solution.reverse_string(st);
    for(int i =0;i<new_st.size();i++ ){
        cout<<new_st[i]<<" ";

    }
    cout<<endl;
    return 0;
}