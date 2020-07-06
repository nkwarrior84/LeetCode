/*

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int N = digits.size();
        int pos = N -1;
        while(pos >= 0 && digits[pos] == 9){
            //carry
            digits[pos] = 0;
            pos--;
        }
        
        if(pos < 0){
            digits.insert(digits.begin(), 1);
        }else{
            digits[pos]++;
        }
        
        return digits;

        
    }
};