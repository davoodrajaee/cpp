#include <iostream>

using namespace std;

int main() {
	int in, temp, count, n, i, max;
	cin >> (cout << "\nEnter N : ", n);
	cin >> (cout << "\nEnter num [1/" << n << "] = ", in);
	for(i = max = count = 1, temp = in; i < n; i++, temp = in) {
		cin >> (cout << "Enter num [" << i + 1 << "/" << n << "] = ", in);
		count = (in == temp) ? count + 1 : 1;
		if(max < count) max = count;
	}
	cout << "\nResult = " << max;

	return system("pause>nul"), 0;
}