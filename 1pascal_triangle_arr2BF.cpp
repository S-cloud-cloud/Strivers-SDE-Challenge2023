#include <bits/stdc++.h>
using namespace std;
// variation 1: row & col no given then by using formula nCr where n=row_no-1 & r = col_no -1 gives the element
//  type:hard
/* 1
  1 1     add above  ele having a mid to get next mid ele b/w first and last 1's
1  2  1
1  3  3   1
1  4  6  4   1
1  5  10  10  5   1*/

long long nCr(int n, int r)
{
  long long res = 1;
  for (int i = 0; i < r; i++)
  {
    res = res * (n - i);
    res = res / (i + 1);
  }
  return res;
}
int main()
{
  int rw = 4;  // row_no
  int col = 3; // col_no
  int element = nCr(rw - 1, col - 1);
  cout << "the element at given row & col num in pascal's triangle is: " << element;
  return 0;
}