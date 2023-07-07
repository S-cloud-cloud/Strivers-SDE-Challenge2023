#include <bits/stdc++.h>
using namespace std;
// variation 2: given the row_no = n , print the entire row;
/* properties : in pascal triangle for each nth row -> n elements i.e. n columns exists and each element can be obtained by using
row_no-1^Ccol_no-1*/
//  type:hard
/* 1
  1 1     add above  ele having a mid to get next mid ele b/w first and last 1's
1  2  1
1  3  3   1
1  4  6  4   1
1  5  10  10  5   1*/
void print_row(int n)
{
    /*from observatiion we optimized to the formula that except 1'st element which is always 1 rest elements when
     column indexing is zero based & ans=1:
   can be found by ans = ans*(row_no - col_no)/col_no; */
    int ans = 1;
    cout << ans; // first element always 1

    for (int i = 1; i < n; i++) // col_no = i(zero based indexing but 1st element always 1) && col= no_of_elements = row_no=n
    {
        ans = ans * (n - i);
        ans = ans / i;
        cout << "\v" << ans;
    }
}
int main()
{
    int rw = 5; // row_no
    cout << " The elements in " << rw << "th row are : \n";
    print_row(rw);
    return 0;
}