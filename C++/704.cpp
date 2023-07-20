#include<iostream>
#include<vector>
using namespace std;
//二分查找法有两种方式
//第一种是全闭，该方法（目的是使用左右相等）是使用middle来逼近目标值 
//第二种是使用左值来逼近，一旦左右相等说明没找到
class Solution {
public:
    int search(vector<int>&nums,int num){
        int left = 0;
        int right = nums.size()-1;
        // int middle = left+(right-left)/2;
        while(left<=right){
            int middle = left + (right-left)/2;
            if (nums[middle]>num){
                right = middle-1;
            }
            else if(nums[middle]<num){
                left = middle+1;

            }
            else{
                return middle;
            }
        }
        return -1;
    }
    int search2(vector<int>&nums,int num){
        //使用左闭右开的方式来夹
        int left = 0;
        int right = nums.size();
        while(left<right){
            int middle = left + ((right-left)>>1);
            if (nums[middle]>num){
                right = middle;
            }
            else if(nums[middle]<num){
                left = middle+1;
            }
            else{
                return middle;
            }
        }
        return -1;
    }


    

    };

int main(){
    Solution solution;
    vector<int> nums = {-3,-2,-1,0,1,2,3};
    int index = solution.search2(nums,3);
    cout<<"索引为："<<index<<endl;
    return 0 ;

}