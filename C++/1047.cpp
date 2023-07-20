#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution{
public:
    string _remove(string S){
        stack<char> st;
        for(char s : S){
            if(st.empty()||st.top()!=s){
                st.push(s);
            }
            else{
                st.pop();
            }

        }
        string result = "";
            while(!st.empty()){
                result+=st.top();
                st.pop();
            }
        reverse(result.begin(),result.end());
    }   return result; 
};
int main(){
    return 0 ;
}