#include <iostream>

using namespace std;

#define MAX 50

int main() {
	int arr[MAX], i = 0;
	for(cout << "\nEnter Array = "; i < MAX; cin >> arr[i++]);
	bool ascending = 1, descending = 1;
	for(int i = 1; i < MAX; i++) {
		if(arr[i - 1] > arr[i]) ascending = 0;
		if(arr[i - 1] < arr[i]) descending = 0;
		if(!(ascending || descending)) break;
	}
	if(ascending && descending) cout << "\nArray is Stable\n";
	else if(ascending) cout << "\nArray is Ascending\n";
	else if(descending) cout << "\nArray is Descending\n";
	else cout << "\nArray is Not Ascending and Descending\n";

	return system("pause>nul"), 0;
}