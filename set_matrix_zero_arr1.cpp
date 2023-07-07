#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>

vector<vector<int>> setZeros(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1;

    for (int i = 0; i < n; i++)
    { // no of rows
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0; // matrix[i][0] being used as mark row array
                if (j != 0)
                {
                    matrix[0][j] = 0; // matrix[0][j] being used mark col array
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }
    /*avoiding disrupting/changing mark table values as other
        values are depended on them*/
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }
    // now in order to update the first column & row values
    /*check for update in 0th row or mark col arr before making any changes in the
    0th col or mark row as col values depend on row */
    if (matrix[0][0] == 0)
    { // mark row's first ele=0 then entire row ele =0
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    // similarly
    if (col0 == 0)
    { // makes each ele of first col 0
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
    return matrix;
}
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = setZeros(matrix);

    cout << "The Final matrix is: n";
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}