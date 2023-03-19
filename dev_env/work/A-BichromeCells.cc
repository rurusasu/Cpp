#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N = 0,
      drowAreaW = 0,
      drowAreaBk = 0;

  cin >> N >> drowAreaW;
  drowAreaBk = N * N - drowAreaW;

  cout << drowAreaBk << endl;
}