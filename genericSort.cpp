//CECS 424 ASSIGNMENT 3
//genericSort.cpp
//Dominique Oyco (014605758)

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct People
{
	string name;
	int age;
};

//comparing the names of the people inside the struct array alphabetically
int nameCompare(People const& a, People const& b) 
{
	// Sort by name first then age
	if (a.name == b.name)
		return a.age < b.age;
	
	return a.name < b.name;
}

//comparing the ages of the people inside the struct array in descending order
int ageCompare(People const& a, People const& b)
{
	if (a.age == b.age)
		return a.name < b.name;
	return a.age > b.age;	
}

template<class T>
// Print elements in an array 
void arrayPrinter(T arr[], int size)
{
	cout << "The sorted numbers are: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

// Print elements in a struct array
void structPrinter(People arr[], int size)
{
	for (int j = 0; j < size; j++)
		cout << "Name: " << (*((People*)arr + j)).name << ", Age: " << (*((People*)arr + j)).age << "\n";
}

int main()
{
	int structArrSize;

	// Sorting array of floating point values
	float numbers[] = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};
	structArrSize = sizeof(numbers) / sizeof(numbers[0]);
	sort(numbers, numbers + structArrSize);
	arrayPrinter(numbers, structArrSize);
	cout << "\n\n";

	// Sorting array of structures
	People nameAgeStruct[] = {{"Hal", 20},
							{"Susann", 31},
							{"Dwight", 19}, 
							{"Kassandra",21},
							{"Lawrence", 25},
							{"Cindy", 22},
							{"Cory", 27},
							{"Mac", 19},
							{"Romana", 27},
							{"Doretha", 32},
							{"Danna", 20},
							{"Zara", 23},
							{"Rosalyn", 26},
							{"Risa", 24},
							{"Benny", 28},
							{"Juan", 33},
							{"Natalie", 25}};

	//Sort by name or sort by age?
	int choice;  
	do{
		cout << "Would you like to sort by name (1) or by age (2)?: ";
		cin >> choice;

	    if(choice == 1){
			structArrSize = sizeof(nameAgeStruct) / sizeof(nameAgeStruct[0]);
			sort(nameAgeStruct, nameAgeStruct + structArrSize, nameCompare);
			structPrinter(nameAgeStruct, structArrSize);
			cout << "\n\n";
			break;
	    }

	    else if(choice == 2){
			structArrSize = sizeof(nameAgeStruct) / sizeof(nameAgeStruct[0]);
			sort(nameAgeStruct, nameAgeStruct + structArrSize, ageCompare);
			structPrinter(nameAgeStruct, structArrSize);
			cout << "\n\n";
			break;
	    }
	  }while(choice != 1 || choice != 2);

	return 0;
}
