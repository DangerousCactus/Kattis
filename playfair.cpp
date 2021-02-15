#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

string encrypt(char a, char b, string& block);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string alphabet = "abcdefghijklmnoprstuvwxyz";
  string cipher;
  string plainText;
  string block;

  getline(cin, cipher);
  getline(cin, plainText);

  for (int i = 0; i < plainText.length(); i++)
    if (plainText[i] == ' ')
      plainText.erase(i--, 1);

  for (char c : cipher) {
    int idx = block.find(c);

    if (idx == -1 && c != ' ' && c != 'q')
      block += c;
  }

  for (char l : alphabet) {
    int idx = block.find(l);

    if (idx == -1)
      block += l;
  }

  string cipherText;

  for (int i = 0; i < plainText.length(); i += 2) {
    if (i + 1 == plainText.length() || plainText[i] == plainText[i + 1]) {
      cipherText += encrypt(plainText[i], 'x', block);
      i--;
    } else {
      cipherText += encrypt(plainText[i], plainText[i + 1], block);
    }
  }

  for (char c : cipherText) {
    cout << (char)toupper(c);
  }

  return 0;
}

string encrypt(char a, char b, string& block) {
  string out;
  int ac = block.find(a);
  int bc = block.find(b);
  if (ac / 5 == bc / 5) {  // row
    out += block[ac + 1 - 5 * (ac % 5 == 4)];
    out += block[bc + 1 - 5 * (bc % 5 == 4)];
  } else if (ac % 5 == bc % 5) {  // col
    out += block[ac + 5 - 25 * (ac / 5 == 4)];
    out += block[bc + 5 - 25 * (bc / 5 == 4)];
  } else {
    out += block[5 * (ac / 5) + bc % 5];
    out += block[5 * (bc / 5) + ac % 5];
  }

  return out;
}
