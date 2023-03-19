#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a = 0, b = 0, x=0;

  cin >> a >> b;
  x = (a * b) % 2;

  if (x == 0)
  {
    cout << "Even" << endl;
  }
  else
  {
    cout << "Odd" << endl;
  }
}