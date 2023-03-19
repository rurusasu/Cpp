#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a = 0, b = 0;
  int x = 0, y = 0;

  cin >> a >> b;
  x = (a + b) / 2;
  y = (a + b) % 2;
  x = x + y;

  cout << x << endl;
}