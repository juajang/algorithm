#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

string a;
int b;

string Add(string &s1, string &s2){
	string result(max(s1.size(), s2.size()), '0');
	bool carry = false;
	for (int i = 0; i < result.size(); i++){
		int temp = carry;
		carry = false;
		if (i < s1.size()) temp += s1[s1.size() - i - 1] - '0';
		if (i < s2.size()) temp += s2[s2.size() - i - 1] - '0';
		if (temp >= 10){
			carry = true;
			temp -= 10;
		}
		result[result.size() - i - 1] = temp + '0';
	}
	if (carry) result.insert(result.begin(), '1');
	return result;

}
string Multiply(string &s1, string &s2){
	string result = "0";
	for (int i = 0; i < s2.size(); i++){
		string line(s1);
		int carry = 0;
		for (int j = s1.size() - 1; j >= 0; j--){
			int temp = carry;
			carry = 0;
			temp += (s1[j] - '0')*(s2[s2.size() - i - 1] - '0');
			if (temp >= 10) {
				carry = temp / 10;
				temp %= 10;
			}
			line[j] = temp + '0';
		}
		if (carry > 0)
			line.insert(line.begin(), carry + '0');
		line += string(i, '0');
		result = Add(result, line);
	}
	return result;

}
string pow(string &a, int b) {
	if (b == 1) return a;
	else {
		string result = pow(a, b - 1);
		result = Multiply(result, a);
		return result;
	}
}

int main() {
	cin >> a >> b;
	int point = 0;
	string::iterator finder = find(a.begin(), a.end(), '.');
	if (finder != a.end()) {
		point = a.end() - finder - 1;
		a.erase(finder);
	}
	point = point * b;
	string result = pow(a, b);
	if (point) result.insert(result.end() - point, '.');
	cout << result;
	return 0;
}