/*
There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

 

Example 1:

Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: 
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:

Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0]
 

Note:

cells.length == 8
cells[i] is in {0, 1}
1 <= N <= 10^9

*********************************************************************

To solve this, we will follow these steps −

Create a map m, and create one set called visited.

if N is 0, then return cells

insert cells into visited set

for i in range 1 to 14

create an array called temp of size 8

for j in range 1 to 6

if cells[j – 1] XOR cells[j + 1] = 0, then temp[j] := 1

cells := temp

m[i] := temp

insert temp into visited

if N is divisible by 14, then return m[14], otherwise m[N mod 14]
*/

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
      map <int, vector <int> > m;
      if(N == 0) return cells;
      set <vector <int> > visited;
      visited.insert(cells);
      for(int i = 1; i<=14 ; i++ ){
         vector <int> temp(8);
         for(int j = 1; j < 7; j++){
            if(cells[j - 1] ^ cells[j + 1] == 0){
               temp[j] = 1;
            }
         }
         cells = temp;
         m[i] = temp;
         visited.insert(temp);
      }
      return m[N % 14 == 0? 14 : N % 14];
        
    }
};