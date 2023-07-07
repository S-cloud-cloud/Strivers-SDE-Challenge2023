#include <bits/stdc++.h>
using namespace std;

// type: medium
/*when the permutation(all possible ways to arrange given sample integers ) of N integers is
written in sorted/dictionary order then the arrangement at next index after finding the input arrangement
is the next permutation*/

vector<int> NextPermutation(vector<int> &i_permutation, int n)
{
    int indx = -1;
    /*last chance of the dip occurrence that gives
        the longest prefix match is always at n-2*/
    for (int i = n - 2; i > 0; i--)
    {
        if (i_permutation[i + 1] > i_permutation[i]) // finding the break_point or the dip condition
        {
            indx = i;
            break;
        }
    }
    // if there is no arramgent index after the given largest possible permutation
    // largest arrangement given as input,fall back to first arrangement(obtained by reverse of largest)

    if (indx == -1)
    {
        reverse(i_permutation.begin(), i_permutation.end());
        return i_permutation;
    }

    // find the > arr[indx] but the smallest one possible out of all after the dip point
    /*as dip+1 to n-1 all points are in a decreasing order,so the chance of smallest after dip+1 but > arr[dip]
    starts at n-1.*/
    // due decreasing order check last first
    for (int i = n - 1; i > 0; i--)
    {
        if (i_permutation[i] > i_permutation[indx])
        {
            swap(i_permutation[i], i_permutation[indx]);
            break;
        }
    }
    // sort remaining in sorted oder:
    reverse(i_permutation.begin() + indx + 1, i_permutation.end());
    /* since n-1 to dip+1 elements are in increasing order,so,
    to find the smallest we can easily reverse & sort it*/
    return i_permutation;
}

int main()
{
    /*123
      132
      213
      231
      312
      321*/
    vector<int> i_permutation{3, 2, 1};
    int n = i_permutation.size();
    vector<int> ans = NextPermutation(i_permutation, n);
    cout << "\n next permutation is : \n ";
    for (int X : ans)
    {
        cout << X << " ";
    }
}