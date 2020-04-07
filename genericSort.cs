//CECS 424 ASSIGNMENT 3
//genericSort.cs
//Dominique Oyco (014605758)

 using System;
 using System.Collections.Generic;
 using System.Linq;
 using System.Text;
 using System.Threading.Tasks;

 class genericSort
 {
 	//People contains a pair of values. A character name and an integer age
     struct People
     {
         public string name;
         public int age;
     }

     //compare the data on people by using their names. 
     //returns the sorted names alphabetically. 
     static int nameCompare(People a, People b)
     {
         if (a.name.CompareTo(b.name) == 0)
             return a.age.CompareTo(b.age);
         return a.name.CompareTo(b.name);
     }
     
     //compare the data on people by using their ages. 
     //Returns the the sorted ages in descending order. If people have the same name, they are sorted alphabetically
     static int ageCompare(People a, People b)
     {
         if (a.age.CompareTo(b.age) == 0)
             return a.name.CompareTo(b.name);
         return b.age.CompareTo(a.age);
         
     }

     //Prints out array elements
     static void arrayPrinter<T>(IList<T> arr)
     {
     	System.Console.Write("The sorted float numbers are: ");
         foreach (T item in arr)
             System.Console.Write(item + " ");
     }

     //Prints out elements inside a struct
     static void structPrinter(People[]arr)
     {
         foreach (People item in arr)
             System.Console.Write("Name: " + item.name + ", Age: " + item.age + "\n");
     }

     static void Main(string[] args)
     {
         float[] numbers = {645.32f, 37.40f, 76.30f, 5.40f, -34.23f, 1.11f, -34.94f, 23.37f, 635.46f, -876.22f, 467.73f, 62.26f};
         Array.Sort(numbers);
         arrayPrinter<float>(numbers);
         System.Console.Write("\n\n");


         People[] nameAgeStruct = { new People() { name = "Hal", age = 20 },
                                 new People() { name = "Susann", age = 31},
                                 new People() { name = "Dwight", age = 19},
                                 new People() { name = "Kassandra",age = 21},
                                 new People() { name = "Lawrence", age = 25},
                                 new People() { name = "Cindy", age = 22},
                                 new People() { name = "Cory", age = 27},
                                 new People() { name = "Mac", age = 19},
                                 new People() { name = "Romana", age = 27},
                                 new People() { name = "Doretha", age = 32},
                                 new People() { name = "Danna", age = 20},
                                 new People() { name = "Zara", age = 23},
                                 new People() { name = "Rosalyn", age = 26},
                                 new People() { name = "Risa", age = 24},
                                 new People() { name = "Benny", age = 28},
                                 new People() { name = "Juan", age = 33},
                                 new People() { name = "Natalie", age = 25} };

		int choice = 0;  
		do{
			System.Console.Write("Would you like to sort by name (1) or by age (2)?: ");
			choice = Convert.ToInt32(Console.ReadLine());

			if(choice == 1){
				Array.Sort<People>(nameAgeStruct, nameCompare);
				structPrinter(nameAgeStruct);
				System.Console.Write("\n\n");
				break;
			}

			else if(choice == 2){
				Array.Sort<People>(nameAgeStruct, ageCompare);
				structPrinter(nameAgeStruct);
				System.Console.Write("\n\n");
				break;
			}
		}while(choice != 1 || choice != 2);
     }
 }