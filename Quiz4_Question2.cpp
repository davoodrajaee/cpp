#include <iostream>

using namespace std;

#define MAX 1000

struct date {
	int year;
	int month;
	int day;
};

struct info {
	string name;
	date birthday;
	long int id;
};

void read(info &p, int i) {
		cin >> (cout << "\nName of person " << i + 1 << " : ", p.name);
		cout << "Birthday Date of person "
		<< i + 1 << " (Year, Month, Day) : ";
		cin >> p.birthday.year >> p.birthday.month >> p.birthday.day;
		cin >> (cout << "National ID of person " << i + 1 << " : ", p.id);
}

void write(info p) {
	cout << p.name << "\t" << p.birthday.year << "," << p.birthday.month 
	<< "," << p.birthday.day << "\t" << p.id << endl;
}

int main() {
	info people[MAX];
	int mMonth, month[12] = {0};
	for(int i = 0; i < MAX; i++)
		read(people[i], i);
	for (int i = 0; i < MAX; i++)
		month[people[i].birthday.month]++;
	for(int i = 0, max = 0; i < 12; i++)
		if (max < month[i]) {
			max = month[i];
			mMonth = i;
		}
	cout << "\nName\tBirthday\tNational ID\n";
	for(int i = 0; i < MAX; i++)
		if (people[i].birthday.month == mMonth)
			write(people[i]);

	return system("pause>nul"), 0;
}