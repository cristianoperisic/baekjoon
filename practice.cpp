#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using std::vector;
using std::string;								// น้มุ 1541

int main(void) {
	string s;
	std::cin >> s;
	vector<char> A(s.begin(), s.end());
	
	int n = 0;
	for (int i = 0; i < A.size();i++) {
		if (n == 0 && A[i] == '-')
			n++;
		else if (n == 1 && A[i] == '+')
			A[i] = '-';
	}

	while (A[0] == '0')
		A.erase(A.begin());

	for (int i = 1; i < A.size(); i++) {
		if (A[i] == '0' && (A[i - 1] == '-' || A[i - 1] == '+')) {
			A.erase(A.begin()+i);
			i--;
		}
	}



	string b(A.begin(), A.end());
	vector<int> myVector;

	for (int i = 1;i <= b.size();i++) {
		if (b[i] == '-' || b[i] == '+') {
			string k="";
			for (int j = 0; j < i;j++) {
				k += b[j];
			}
			for (int j = 0;j < i;j++) {
				b.erase(b.begin());
			}
			myVector.push_back(stoi(k));
			i = i - k.size() + 1;
		}
		if (b[i] == '\0') {
			string k = "";
			for (int j = 0; j < i;j++) {
				k += b[j];
			}
			myVector.push_back(stoi(k));
			break;
		}
	}

	int sum = 0;
	for (int i = 0; i < myVector.size();i++) {
		sum += myVector[i];
	}

	std::cout << sum;

	return 0;
}
