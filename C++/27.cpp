//使用快慢指针来完成数组覆盖
//该方法还能保证按照顺序覆盖
#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int _delete(vector<int> &nums, int num){
        //int _size = nums.size();
        int slow = 0;
        for (int i =0;i<=nums.size();i++){
            if (nums[i]!=num){
                nums[slow] =  nums[i];
                slow++;
            }

        }
        return slow;

    }
    //暴力删除，逐步迁移
    vector<int> baoli(vector<int> &nums,int num){
        int _size = nums.size();
        for(int i=0;i<_size;i++){
            if (nums[i]==num){
                for (int j =i+1;j<_size;j++){
                    nums[j-1] = nums[j];
                }
                i--;
                _size--;
            }

        }
        return nums;

    }
};
int main(){
    vector<int> nums = {1,2,3,1,2,3,4};
    Solution solution;
    solution.baoli(nums,1);
    for(int i =0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}