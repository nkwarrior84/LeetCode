/*

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
   Hide Hint #1  
So, we essentially need to find three numbers x, y, and z such that they add up to the given value. If we fix one of the numbers say x, we are left with the two-sum problem at hand!
   Hide Hint #2  
For the two-sum problem, if we fix one of the numbers, say
x
, we have to scan the entire array to find the next number
y
which is
value - x
where value is the input parameter. Can we change our array somehow so that this search becomes faster?
   Hide Hint #3  
The second train of thought for two-sum is, without changing the array, can we use additional space somehow? Like maybe a hash map to speed up the search?


*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<vector<int>> ans;
        
        for(int left = 0; left <= N-3; left++){
            //in this case, nums[left]'s role is already played by nums[left-1]
            //, so we will only get duplicate combinations
            if(left > 0 && nums[left] == nums[left-1]) continue;
            int mid = left+1, right = N-1;
            while(mid < right){
                if(nums[left] + nums[mid] + nums[right] == 0){
                    ans.push_back({nums[left], nums[mid], nums[right]});
                    //find a mid s.t. nums[mid+1] != current nums[mid]
                    while(mid < right && nums[mid] == nums[mid+1]) mid++;
                    while(mid < right && nums[right] == nums[right-1]) right--;
                    //switch to mid+1(nums[mid+1] != current nums[mid])
                    mid++; right--;
                }else if(nums[left] + nums[mid] + nums[right] < 0){
                    mid++;
                }else{
                    right--;
                }
            }
        }
        
        return ans;
        
    }
};