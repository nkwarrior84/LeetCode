/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.

*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNums(n, 0);
        uglyNums[0] = 1;
        int i2, i3, i5;
        i2 = i3 = i5 = 0; 
        int nextUgly2 = 2;
        int nextUgly3 = 3;
        int nextUgly5 = 5;
        int nextUglyNo = 1;
        for(int i = 1; i < n; ++i) {
            nextUglyNo = min(min(nextUgly2, nextUgly3), nextUgly5);
            uglyNums[i] = nextUglyNo;
            if(nextUglyNo == nextUgly2) {
                nextUgly2 = uglyNums[++i2] * 2;
            }
            if(nextUglyNo == nextUgly3) {
                nextUgly3 = uglyNums[++i3] * 3;
            }
            if(nextUglyNo == nextUgly5) {
                nextUgly5 = uglyNums[++i5] * 5;
            }
        }
        return nextUglyNo;
    }
};