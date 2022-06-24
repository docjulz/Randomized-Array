// This program creates a randomized array and offers the user
// the ability to make changes to it.

#include<iostream>
#include <cstdlib>   
#include <ctime>

using namespace std;

int arrayUpdate(int intArray[], int size);

/*****************************************************
* First, make an array to use later in the program : *
******************************************************/
int main()
{
    int newArray;
	// Array of ints of size 90 (not dynamic)
	const int SIZE = 90;

	// Init all values to 0 (that's the curly braces thing)
    int numbers[SIZE] = {};

	cout << "This is arandomized array of " << SIZE << " numbers 2-9:" << endl;

	// Loop through the array and set each value to a random number between 2 and 9
	
    srand(time(0));
    for (int &random : numbers)
    {
        random = rand() % 8 + 2;
    }

    // Print the array with a separate for loop.  
    // Put a space between each number
    for (int random : numbers)
    {
        cout << random << " " ;
    }

    newArray = arrayUpdate(numbers, SIZE);

	return 0;
}


/*******************************************
* Now use that array to do the following : *
********************************************/

int arrayUpdate(int array[], int size)
{    
    int repeat;
    
    cout << "\nThis is the original array:\n";
    for (int index = 0; index < size; index++)
        cout << array[index] << " ";

    cout << endl;
    
    do
    {
        int position, newNumber;

        // Ask the user what index they want to change If 
        // it is out of bounds, don't exit the program, just ask again.
        cout << "Enter index you would like to change: ";
        cin >> position;
        if (position > size - 1)
        {
            cout << "**This number is out of bounds**\n";
            cout << "Enter new index number 1 - " << size - 1 << ": ";
            cin >> position;
        }

        // Ask the user what the new value should be
        cout << "enter new number: ";
        cin >> newNumber;
        array[position] = newNumber;

        //Reprint the array
        cout << "\nThe new Array is:\n";
        for (int count = 0; count < size; count++)
            cout << array[count] << " ";

        // Keep doing this until they enter - 1 for the index
        cout << "\nwould you like to change again?\n";
        cout << "Enter 1 to continue or -1 to exit: ";
        cin >> repeat;

        if (repeat == -1)
            cout << "\nGoodbye\n";
        else if ((repeat != 1) || (repeat != -1))
        {
            cout << "Incorrect selection" << endl;
            cout << "Enter 1 to continue or -1 to exit: ";
            cin >> repeat;
        }

    } while (repeat != -1);

    return 0;

}