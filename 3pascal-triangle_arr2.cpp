#include <bits/stdc++.h>
using namespace std;
// variation 3: given the no of rows i.e. N : generate a pascal triangle/print the pascal triangle.
// step of function ncr optimized by logic of version 2 to achieve a : TC: O(n^2)
// type: hard
vector<vector<int>> generateTriangle(int n)
{
    vector<vector<int>> ans;
    /*  step1: generate an empty ans list*/

    for (int row = 1; row <= n; row++) // step2: logic:  nth row = n elements = n columns
    {
        long long ans1 = 1; /*to make sure first element is 1 and the version 2(nth row given, print all the elements in that row) ncr function logic can be used to generate the elements*/

        vector<int> tempans;  // step 3:  generate a temp list
        tempans.push_back(1); // first ele 1

        for (int col = 1; col < row; col++)
        {
            ans1 = ans1 * (row - col); /*using optimized formula from version 2 to generate elements of the current nth row*/
            ans1 = ans1 / col;
            tempans.push_back(ans1);
        }

        ans.push_back(tempans); /*after all elements of an nth row is generated ,it is added to the ans,till all the rows are generated*/
    }
    return ans;
}

int main()
{
    int n = 6;
    vector<vector<int>> ans = generateTriangle(n); // step1: generate an empty ans list
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
