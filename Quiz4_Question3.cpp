#include <iostream>
#include <fstream>

using namespace std;

#define MAX_WORD 1000
#define MAX_DIGIT 50

void Find_Words(ifstream &file, char **myArray, int &words) {
	int j, k, i = 0;
	while(file >> myArray[i]) {
		for(j = 0; myArray[i][j]; j++) {
			if(myArray[i][j] == '.') {
				myArray[i][j++] = '\0';
				if(myArray[i][j]) {
					for(k = 0; myArray[i][j]; j++, k++)
						myArray[i + 1][k] = myArray[i][j];
					myArray[++i][k] = '\0';
				}
			}
		}
		i++;
	}
	words = i;
}

void move(char *word1, char *word2) {
	int i;
	for(i = 0; word2[i]; i++)
		word1[i] = word2[i];
	word1[i] = word2[0] = '\0';
}

bool is(char *word1, char *word2) {
	int i;
	for(i = 0; word1[i] || word2[i]; i++)
		if(word1[i] != word2[i]) return false;
	if(word1[i] != word2[i]) return false;
	return true;
}

int main() {
	int size = 0;
	char **myArray = new char*[MAX_WORD];
	for(int i = 0; i < MAX_WORD; i++)
		myArray[i] = new  char[MAX_DIGIT];
	ifstream File("string.txt", ios::in);
	if(!File.is_open()) cout << "\nNot Find File...!\n";
	else Find_Words(File, myArray, size);
	File.close();
	int d[size] = {1};
	for(int i = 0; i < size; d[++i] = 1)
		for(int j = i + 1; j < size; j++)
			if(is(myArray[i], myArray[j])) {
				for(int k = j + 1; k < size; k++)
					move(myArray[k - 1], myArray[k]);
				size--;
				d[i]++;
			}
	for(int i = 0; i < size; i++)
		cout << myArray[i] << " " << d[i] << "\n";

	for(int i = 0; i < MAX_WORD; i++)
		delete[] myArray[i];
	delete[] myArray;
	
	return system("pause>nul"), 0;
}