#include <bits/stdc++.h>

using namespace std;

int main()
{
  int A = 0,
      N = 0,
      N_1 = 0;

  cin >> N >> A;

  N_1 = N % 500;

  // cout << N_1 << endl;

  if (A >= N_1 || N_1 == 0)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}