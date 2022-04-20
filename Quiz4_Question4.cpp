#include <iostream>

using namespace std;

#define MAX 10

class Set {
public:
	Set() : size(0) {}
	~Set() {
		if(size) delete[] data;
	}
	bool member(int d) {
		for(int i = 0; i < size; i++)
			if(data[i] == d) return true;
		return false;
	}
	int cradinality() {
		return size;
	}
	void Insert(int d) {
		if(!size) {
			data = new int[++size];
			data[0] = d;
		}
		else {
			int *temp = new int[++size];
			for(int i = 0; i < size - 1; i++)
				temp[i] = data[i];
			temp[size - 1] = d;
			delete[] data;
			data = temp;
		}
	}
	bool del(int d) {
		if(!(size && member(d))) return false;
		int *temp = new int[--size];
		int i, j;
		for(i = j = 0; i < size + 1; i++) {
			if(data[i] == d) break;
			temp[j++] = data[i];
		}
		for(i++; i < size + 1; i++, j++)
			temp[j] = data[i];
		delete[] data;
		data = temp;
		// del(d);	// To Delete All Selected Value
		return true;
	}
	// void print() {
	// 	for(int i = 0; i < size; i++) cout << data[i] << " ";
	// }
private:
	int *data;
	int size;
};

int main() {
	Set arr;
	int temp;
	cout << "\nEnter " << MAX << " Number : ";
	for(int i = 0; i < MAX; i++) {
		cin >> temp;
		arr.Insert(temp);
	}
	cout << endl;
	cin >> (cout << "\nEnter an another Number : ", temp);
	if(arr.member(temp)) arr.del(temp);
	cout << "\nYour arr have " << arr.cradinality() << " value\n";
	
	return system("pause>nul"), 0;
}