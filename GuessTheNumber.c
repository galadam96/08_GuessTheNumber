/*Date: 2023.06.06
Purpose: Guess the number from 0 to 20 game*/

#include <stdio.h>
#include <stdlib.h> //for srand() function
#include <time.h> // for the seed for the random number

int main() {

	//variables
	int myNum = 0;
	int guess = 0;

	//generating random number between 0 and 20-------------

	time_t t = 0; //create time variable
	srand((unsigned) time(&t)); // initialize the random number generator
	myNum = rand() % 21; //random number generation between 0 and 20
	printf("DEBUG: Number is: %i\n", myNum);
	//------------------------------------------------------

	//starting message
	printf("This is a guessing game! \nI have chosen a number between 0 and 20 which you must guess.\n");

	
	//user input 

	for (int tries = 5; tries > 0; tries--) {
		printf("\nYou have %d tries left.\nEnter a guess: ", tries);
		scanf_s("%i", &guess);

		//number check between 0 and 20
		while ( (guess < 0) || (guess > 20) ) {
			printf("\nNumbers only between 0 and 20!\nEnter a new number:");
			scanf_s("%i", &guess);
		}
	
		//win condition
		if (guess == myNum) {
			break;
		}

		//guess is too less
		else if (guess < myNum)
		{
			printf("\nSorry, %i is wrong. My number is more than that.", guess);
		}

		//guess is too much
		else if (guess > myNum)
		{
			printf("\nSorry, %i is wrong. My number is less than that.", guess);
		}

	}

	//exit messages
	if (guess == myNum) {
		printf("\nCongratulations. You guessed it!\n\n"); // can be also in the else in the loop
	}
	else {
		printf("\nSorry, you didn't guess the number. It was %i.\n\n", myNum);
	}
	
	return 0;
}