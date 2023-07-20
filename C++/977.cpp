#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    //对有序数组的平方进行排序
    vector<int> _sort(vector<int> &nums){
        vector<int> newnums(nums.size(),0);
        int k = nums.size()-1;
        for(int i=0,j =nums.size()-1;i <= j;){
            if(nums[i]*nums[i]<=nums[j]*nums[j]){
                newnums[k] = nums[j];
                j--;
            }
            else{
                newnums[k] = nums[i];
                i++;
            }
            k--;
        }
        return  newnums;
    }
};
int main(){
    vector<int> nums = {-11,-7,3,4,5,6,7,8};
    Solution solution;
    vector<int> result = solution._sort(nums);
    for(int i = 0;i<nums.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}