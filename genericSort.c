// //CECS 424 ASSIGNMENT 3
// //genericSort.c
// //Dominique Oyco (014605758)

#include <stdio.h>
/*
	type = 1 -> float
	type = 2 -> struct
*/
int type;

/*
People contains a pair of values. A character name and an integer age
*/
typedef struct People
{
	char* name;
	int age;
}People;

// Print elements in an array
void arrayPrinter(void* a, int size, int type)
{
	if (type == 1) // float
	{
    printf("The sorted float values are: ");
		for (int i = 0; i < size; i++)
    		printf("%.2f ", *((float*)a + i));
	}

	else if (type == 2) // struct
	{
		People* temp = (People*)a;

		for (int i = 0; i < size; i++)
		{
			printf("Name: %s, Age: %d \n", temp->name, temp->age);
			temp = ((People*)temp + 1);

			if (i != size - 1)
				printf(" ");
		}
	}
}

int floatCompare(const void* a, const void* b){
  	return ((*(float*)a) - (*(float*)b));
}

int nameCompare(const void* a, const void* b){
	People* tempA = (People*)a;
	People* tempB = (People*)b;

	// Sort by name first then age
	if(strcmp(tempA->name, tempB->name) == 0)
		return (tempA->age - tempB->age);

	return strcmp(tempA->name, tempB->name);
}

int ageCompare(const void* a, const void* b){
    People* tempA = (People*)a;
    People* tempB = (People*)b;

  // Sort by age first then name
	if((tempB->age - tempA->age) == 0)
		  return (strcmp(tempA->name, tempB->name)); //if people have the same age, it will displayed in alphabetical order

	return (tempB->age - tempA->age);
}

int main()
{
	int structArrSize;

	printf("\n");

	// Sorting array of floating point values
	type = 1;
	float floatArray[] = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};
	structArrSize = sizeof(floatArray) / sizeof(floatArray[0]);
	qsort(floatArray, structArrSize, sizeof(float), floatCompare);
	arrayPrinter(floatArray, structArrSize, type);
	printf("\n\n");

	// Sorting array of structures
	type = 2;
	People nameAgeStruct[] = {[0].name = "Hal", [0].age = 20,
						   [1].name = "Susann",[1].age = 31,
						   [2].name = "Dwight",[2].age = 19,
						   [3].name = "Kassandra",[3].age = 21,
						   [4].name = "Lawrence",[4].age = 25,
						   [5].name = "Cindy",[5].age = 22,
						   [6].name = "Cory",[6].age = 27,
						   [7].name = "Mac",[7].age = 19,
						   [8].name = "Romana",[8].age = 27,
						   [9].name = "Doretha",[9].age = 32,
						   [10].name = "Danna",[10].age = 20,
						   [11].name = "Zara",[11].age = 23,
						   [12].name = "Rosalyn",[12].age = 26,
						   [13].name = "Risa",[13].age = 24,
						   [14].name = "Benny",[14].age = 28,
						   [15].name = "Juan",[15].age = 33,
						   [16].name = "Natalie",[16].age = 25};

  //Sort by name or sort by age?
  int choice;  
  do{
    printf("Would you like to sort by name (1) or by age (2)?: ");
    scanf("%d", &choice);

    if(choice == 1){
      structArrSize = sizeof(nameAgeStruct) / sizeof(nameAgeStruct[0]);
      qsort(nameAgeStruct, structArrSize, sizeof(People), nameCompare);
      arrayPrinter(nameAgeStruct, structArrSize, type);
      printf("\n\n");
      break;
    }

    else if(choice == 2){
      structArrSize = sizeof(nameAgeStruct) / sizeof(nameAgeStruct[0]);
      qsort(nameAgeStruct, structArrSize, sizeof(People), ageCompare);
      arrayPrinter(nameAgeStruct, structArrSize, type);
      printf("\n\n");
      break;
    }
  }while(choice != 1 || choice != 2);

  return 0;

}