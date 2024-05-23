
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string convertToBinary(int n) {
  string res;
  cout << "Enter a number: ";
  cin >> n;

  if (n == 0) {
    return "0";
  }

  while (n > 0) {
    if (n % 2 == 1)
      res += "1";
    else
      res += "0";
    n = n / 2;
  }

  reverse(res.begin(), res.end());
  return res;
}

int main() {
  int n;
  string ans = convertToBinary(n);
  cout << "Binary Equivalent: " << ans << endl;
  return 0;
}
