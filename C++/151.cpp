//反转字符串里的单词
#include<iostream>
#include<string>
using namespace std;
class Solution{
public:
    void delete_pace(string &s){
        int slow = 0;
        for(int i =0;i<s.size();i++){
            if(s[i]!=' '){
                if (slow!=0){
                    //说明不是第一个单词
                    //要加空格
                    s[slow++] = '';
                    //在单词之后加空格

                }
                while(i<s.size()&&s[i]!=' '){
                    //看什么时候遍历完一个单词
                    s[slow++] = s[i++];

                }
            }
        }

    }
};
int main(){
    return 0 ;
}