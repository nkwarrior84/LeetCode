/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.

Solution 1: Without XOR

Take the mod with two get the last/least significant bit.
Compare each of the i-th bits, adding 1 to our answer when they are different.
Divide both number by 2 remove the last/least significant bit.
Repeat step 1-3 until any number > 0.
class Solution {
    public int hammingDistance(int x, int y) {
        int hd = 0;
        while(x > 0 || y > 0) {
            hd += (x % 2 != y % 2) ? 1 : 0;
            x /= 2;
            y /= 2;
        }
        return hd;
    }
}
Solution 2: 1 Liner using Inbuilt Integer bitCount function
As per hamming distance definition if bit different then 1 else 0 which is same as taking xor and count the number of set bits.

class Solution {
    public int hammingDistance(int x, int y) {
        return Integer.bitCount(x ^ y);
    }
}
Solution 3: If in interview not allowed to use Integer.bitCount(x) method.
countOne / countSetBits in number n can be achieve in many ways.

Using simple Math mod by 2 property used in Solution 1.
Second using below Brian Kernigham Algorithm, fast approach to count set bits
Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost bit.

10 in binary is 00001010
 9 in binary is 00001001
 8 in binary is 00001000
 7 in binary is 00000111
class Solution {
    public int hammingDistance(int x, int y) {
        return bitCount( x ^ y);
    }
    
    private int bitCount(int n) {
        int count = 0;
        while (n > 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
}

*/

class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        int z=x^y;
        int distance = 0;
        while(z)
        {
            distance += z%2;
            z /= 2;
        }
        
        return distance;
    }
};
