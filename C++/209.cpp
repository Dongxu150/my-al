#include<iostream>
#include<vector>
#include <climits>
using namespace std;
class Solution{
public:
    int _find(vector<int> &nums,int  target){
        int left = 0;
        int ans = INT_MAX;
        int sum = 0;
        for (int right = 0;right < nums.size();right++){
            sum = sum +nums[right];
            while(sum>=target){
                ans = min(ans, right - left + 1);
                sum = sum-nums[left];
                left++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
int main(){
    vector<int> nums = {1,2,3,4,6,1,2,3,4,2,3};
    Solution solution;
    int length = solution._find(nums,6);
    cout<<length<<endl;
    return 0;
}