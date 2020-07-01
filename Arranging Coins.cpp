/* Arranging Coins
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.

Solution:

Actually, this is the math problem.
The sum of length of each row of staircase shape is n(n + 1) / 2. So this question is to solve the inequality x² + x - 2n <= 0.
Use the formula : x = (-b +/- sqrt(b² - 4ac)) / 2a
The final answer will be x = sqrt(2*n + 0.25) - 0.5 becuase the answer will be positive.
We will cast the answer to int, therefore it satisfies the inequality.

*/

class Solution {
public:
    int arrangeCoins(unsigned int n) {
        unsigned int num = 2 * n;
        int ans = static_cast<int>(sqrt(num + 0.25) - 0.5);
        
        return ans;
    }
};
