#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0; // 统计空格的个数
        int sOldSize = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        // 扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
        s.resize(s.size() + count * 2);
        int sNewSize = s.size();
        // 从后先前将空格替换为"%20"
        //循环里的j和i相等以后，代表前面的数值是一样的
        for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
            cout<<i<<" "<<j<<endl;
            if (s[j] != ' ') {
                s[i] = s[j];
            } else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};

int main() {
    string s = "We are happy.";
    Solution solution;
    string result = solution.replaceSpace(s);
    cout << result << endl; // 输出：We%20are%20happy.
    return 0;
}