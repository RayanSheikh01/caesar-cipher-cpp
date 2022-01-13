#include <iostream>
#include <random>

using namespace std;

int main() {
       	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> uni(1, 26);
	string text;
	cout << "Enter text (only lowercase):\n";
	cin >> text;
	auto salt = uni(rng);
	cout << "plaintext:\n" <<  text << "\n";
	cout << "ciphertext:\n";

	for (int i = 0; i < text.length(); i++) {
		int num;
		num = int(text[i]);
		if (num+salt > 122) {
			num = (num+salt)-25;
		}
		else if (num+salt <= 122) {
			num += salt;
		}
		cout << char(num);
	}
	cout << "\n" << "Salt: " << salt << "\n";

	return 0;

}
