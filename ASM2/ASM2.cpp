#include <iostream>
#include <bitset>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int temp = 1;
unsigned int choice;
void Menu(), LineOne(), LineTwo(), EnterInformation(), PrintInformation(), HighestGrade(), LowestGrade();

struct Student
{
	string idTemp;
	float gradeTemp;
	std::vector<string> id;
	std::vector<float> grade;
};
struct Student student;

void LineOne() {
	cout << "--------------------------------" << endl;
}

void LineTwo() {
	cout << "***********************************" << endl;
}

void Menu() {
	cout << " =================================" << endl;
	cout << "|             MENU                |" << endl;
	cout << " =================================" << endl;
	cout << "| 1. Enter student information.   |" << endl;
	cout << "| 2. Print student information.   |" << endl;
	cout << "| 3. Students has highest grade.  |" << endl;
	cout << "| 4. Students has lowest grade.   |" << endl;
	cout << "| 5. Quit.                        |" << endl;
	cout << " ================================= " << endl;
}

void EnterInformation() {
	int i = 0;

	LineOne();
	std::cout << "Enter student ID (enter 0 to end):\n";
	do {
		cout << "\nStudent's id " << i + 1 << ": ";
		cin >> student.idTemp;
		student.id.push_back(student.idTemp);
		cout << "Student's grade " << i + 1 << ": ";
		cin >> student.gradeTemp;
		while (student.gradeTemp > 10 || student.gradeTemp < 0) {
			cout << "Max grade is 10 and min grade is 0, please retype grade: ";
			cin >> student.gradeTemp;
		}
		student.grade.push_back(student.gradeTemp);
		cout << "Enter 1 to continue 0 to stop: ";
		cin >> temp;
		i++;
	} while (temp == 1);
	LineTwo();
}

void PrintInformation() {
	cout << "*******STUDENT'S INFORMATION*******" << endl;
	for (int i = 0; i < student.id.size(); i++) {
		cout << i + 1 << ". " << "ID: " << student.id[i];
		cout << "\t\tGrade: " << student.grade[i] << endl;
	}
	LineOne();
}

void HighestGrade() {
	float highestGrade = 0;

	for (int i = 0; i < student.id.size(); i++) {
		if (student.grade[i] > highestGrade) {
			highestGrade = student.grade[i];
		}
	}

	LineTwo();
	for (int i = 0; i < student.id.size(); i++) {
		if (student.grade[i] == highestGrade) {
			cout << "The student " << student.id[i] << " has highest grade " << student.grade[i] << endl;
		}
	}
	LineTwo();
}

void LowestGrade() {
	float lowestGrade = student.grade[0];

	for (int i = 0; i < student.id.size(); i++) {
		if (student.grade[i] < lowestGrade) {
			lowestGrade = student.grade[i];
		}
	}

	LineTwo();
	for (int i = 0; i < student.id.size(); i++) {
		if (student.grade[i] == lowestGrade) {
			cout << "The student " << student.id[i] << " has highest grade " << student.grade[i] << endl;
		}
	}
	LineTwo();
}

int main()
{
	do
	{
		Menu();

		cout << "Your choice: ";
		cin >> choice;
		while (choice > 5)
		{
			cout << "Invalid value! Please retype: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			EnterInformation();
			break;
		case 2:
			PrintInformation();
			break;
		case 3:
			HighestGrade();
			break;
		case 4:
			LowestGrade();
			break;
		case 5:
			cout << "The program has stopped";
			break;
		}
	} while (choice < 5);
}