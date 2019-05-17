#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/************************akinyanbolaMobolajiA2.c **************
 Student Name: Mobolaji Akinyanbola 
Email Id:  makinyan
Date: November 9th, 2018 Course Name: CIS 1500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material (data, images, ideas or words)
that I have used, whether directly quoted or paraphrased. Furthermore, I certify that this assignment was prepared by me 
specifically for this course. **********************************************************/

#define MAX_QUESTIONS 7

//function prototypes

void promptPlayerForName (char [50]);
void printWelcomeMessage (char  [50]);
int  calculateCurrentAward (int ,int);
void popUpCurrentQuestion4choices (int);
char askPlayerForLifeLine (void);
void popUpCurrentQuestion2choices (int);
char acceptPlayersFinalAnswer (void);
bool isCorrectFinalAnswer (char, int, char [MAX_QUESTIONS]);
void generateRandomGreeting (char [20]);
int calculateReducedAward (int, int);

int main(){

	char allCorrectAnswers [MAX_QUESTIONS + 1] = "CBCBACA";   // for my set of questions
	char greet [20];
	char nameForGame[50];
	int lifeLineUsed = 0; 
	int questionNumber = 1;
	char playersResponseLifeLine;
	char finalAnswer;
	int currentAwardAmount ;
    int reducedAmount;
    
	promptPlayerForName(nameForGame);
	
	printWelcomeMessage(nameForGame);
	
	while (questionNumber <= MAX_QUESTIONS)
    {
	
		currentAwardAmount = calculateCurrentAward(questionNumber, currentAwardAmount);
		
		popUpCurrentQuestion4choices(currentAwardAmount);
	
		if (lifeLineUsed == 0)
        {
			playersResponseLifeLine = askPlayerForLifeLine();
		
			if (playersResponseLifeLine == 'Y' || playersResponseLifeLine == 'y')
            {
		
				popUpCurrentQuestion2choices(currentAwardAmount);
				lifeLineUsed ++; 
				printf("\nReminder - You get only 1 50-50 lifeline - and you are using it now \n\n");
			}
		}
		
		finalAnswer = acceptPlayersFinalAnswer ();
		
		if (isCorrectFinalAnswer (finalAnswer, questionNumber, allCorrectAnswers) )
        {
		
		 	generateRandomGreeting(greet);
			printf("%s - You just won $ %d\n", greet, currentAwardAmount);
			
			if (questionNumber < MAX_QUESTIONS)
            {
				printf("Let us play the next question now\n\n"); 
			}
		}
		
		else {
			printf  ("Oops - that was incorrect.");
            
            reducedAmount = calculateReducedAward (questionNumber, currentAwardAmount);

			printf("You still won $%d. Well done.\n\n", reducedAmount);
			
            questionNumber = MAX_QUESTIONS;
		}
		questionNumber ++;
	}
	
	printf("It was fun playing with you \n\n");
	
	return 0;

}	
// This function asks the person for their name.
void  promptPlayerForName(char fullName[50]){

char firstName[25];
char lastName[25];

printf("Enter your first name: ");
scanf("%s", firstName);

printf("Enter your last name: ");
scanf("%s", lastName);

strcpy(fullName, firstName);
strcat(fullName, " ");
strcat(fullName, lastName);


}

// This function prints the welcome message using stars and the person's name.
void printWelcomeMessage(char fullName[50]){


int fullNameLength = strlen(fullName);
int lengthOfStar = fullNameLength + 8;

int i;

	for(i = 0; i < 1; i++){
		printf("*");
	}
	printf("\n");
	for(i = 0; i < 2; i++){
		printf("*");
	}
	printf("\n");
	for(i = 0; i < 3; i++){
		printf("*");
	}
	printf("\n");

	for(i = 0; i < lengthOfStar; i++){
		printf("*");
	}
printf("\n");
printf("Welcome %s\n", fullName);
printf("Let us play WDWM!\n");
	for(i = 0; i < lengthOfStar; i++){
		printf("*");
	}
	printf("\n");
	for(i = 0; i < 3; i++){
                printf("*");
        }
        printf("\n");
        for(i = 0; i < 2; i++){
                printf("*");
        }
        printf("\n");
        for(i = 0; i < 1; i++){
                printf("*");
	}
	printf("\n");
return;

}
// This function calculates the amount the person wins for each question.
int calculateCurrentAward(int questionNumber, int awardPreviousQuestion){


int awardForQuestion;

	if(questionNumber == 1){
		awardForQuestion = 100;
	}
	else	{
		if(questionNumber % 2 == 0){
		awardForQuestion = awardPreviousQuestion * 5;
		}
		else {
		awardForQuestion = awardPreviousQuestion * 2;
		}
	}
return awardForQuestion;
}
// This function displays the questions.
void popUpCurrentQuestion4choices(int currentAwardAmount){

printf("Here is the $ %d question\n", currentAwardAmount);

switch(currentAwardAmount){
	case 100:
	printf("1. Which of the following programming language is taught in  CIS1500 at the University of Guelph?\n");
	printf("A. Python					B. Cobra\n");
	printf("C. C						D. Java\n");
	break;
	case 500:
	printf("2. Which Canadian chain first opened in Hamilton in 1964?\n");
	printf("A. McDonalds					B. Tim Hortons\n");
	printf("C. Wendys					D. Mr. Sub\n");
	break;
	case 1000:
	printf("3. What is Canada's national sport?\n");
	printf("A. Hockey					B. Lacrosse\n");
	printf("C. Hockey and Lacrosse				D. Baseball\n");
	break;
	case 5000:
	printf("4. What Canadian city ranks as most educated in the country?\n");
	printf("A. Montreal					B. Ottawa\n");
	printf("C. Vancouver					D. Toronto\n");
	break;
	case 10000:
	printf("5. What is Canada's highest mountain?\n");
	printf("A. Mount Logan, Yukon				B. Whistler Mountain, BC\n");
	printf("C. Mont Tremblant, Quebec			D. Tip Top Mountain, Ontario\n");
	break;
	case 50000:
	printf("6. What is the easternmost province of Canada?\n");
	printf("A. Ontario					B. Prince Edward Island\n");
	printf("C. Newfoundland					D. Nova Scotia\n");
	break;
	case 100000:
	printf("7. The southernmost point of mainland Canada is called Point Pelee. Which province is it in?\n");
	printf("A. Ontario					B. Quebec\n");
	printf("C. Newfoundland					D. Nova Scotia\n");
	break;
}
}
// This function asks the person if they want to use their lifeline for 1 question
char askPlayerForLifeLine(void){

char lifeLineDecision;

printf("Would you like to use a lifeline (50-50)?\n");
printf("Enter Y or y, N or n: ");
scanf(" %c", &lifeLineDecision);


while((lifeLineDecision != 'y') && (lifeLineDecision != 'Y') && (lifeLineDecision != 'n') &&(lifeLineDecision != 'N')){
	printf("Invalid option entered\n");
	printf("Enter Y or y, N or n: \n");
	scanf(" %c", &lifeLineDecision);
}
return lifeLineDecision;
}

void popUpCurrentQuestion2choices(int currentAwardAmount){

		switch(currentAwardAmount){
		case 100:
		printf("OK - here are your 2 choices after using the 50-50 lifeline\n");
		printf("C. C\n");
		printf("D. Java\n");
		break;
		case 500:
		printf("OK - here are your 2 choices after using the 50-50 lifeline\n");
		printf("A. McDonalds\n");
		printf("B. Tim Hortons\n");
		break;
		case 1000:
		printf("OK - here are your 2 choices after using the 50-50 lifeline\n");
		printf("B. Lacrosse\n");
		printf("C. Hockey and Lacrosse\n");
		break;
		case 5000:
                printf("OK - here are your 2 choices after using the 50-50 lifeline\n");
                printf("B. Ottawa\n");
                printf("D. Toronto\n");
                break;
		case 10000:
                printf("OK - here are your 2 choices after using the 50-50 lifeline\n");
                printf("A. Mount Logan, Yukon\n");
                printf("B. Whistler Mountain, BC\n");
                break;
		case 50000:
                printf("OK - here are your 2 choices after using the 50-50 lifeline\n");
                printf("C. Newfoundland\n");
                printf("D. Nova Scotia\n");
                break;
		case 100000:
                printf("OK - here are your 2 choices after using the 50-50 lifeline\n");
                printf("A. Ontario\n");
                printf("D. Nova Scotia\n");
                break;
		}



}
// The function accepts the person's answers and stores them
char acceptPlayersFinalAnswer(){

char finalAnswer;

printf("Enter your FINAL ANSWER ('A','B','C', or 'D'): ");
scanf(" %c", &finalAnswer);


while((finalAnswer != 'A') && (finalAnswer != 'B') && (finalAnswer != 'C') && (finalAnswer != 'D')){
	printf("Enter your FINAL ANSWER ('A', 'B', 'C' OR 'D'): \n");
	scanf(" %c", &finalAnswer);
	
}
return finalAnswer;
}
/*** This function compares the person's answers to the correct answers stored in the allCorrectAnswers variable. If
the user is wrong, the program ends but if the person is right, the program continues.***/
bool isCorrectFinalAnswer(char finalAnswer, int questionNumber, char allCorrectAnswers[MAX_QUESTIONS]){
if(questionNumber == 1){
	if(finalAnswer == allCorrectAnswers[0]){
	return true;
	}
	else{
	return false;
	}
}
if(questionNumber == 2){
        if(finalAnswer == allCorrectAnswers[1]){
        return true;
        }
        else{
        return false;
        }
}
if(questionNumber == 3){
        if(finalAnswer == allCorrectAnswers[2]){
        return true;
        }
        else{
        return false;
        }
}
if(questionNumber == 4){
        if(finalAnswer == allCorrectAnswers[3]){
        return true;
        }
        else{
        return false;
        }
}
if(questionNumber == 5){
        if(finalAnswer == allCorrectAnswers[4]){
        return true;
        }
        else{
        return false;
        }
}
if(questionNumber == 6){
        if(finalAnswer == allCorrectAnswers[5]){
        return true;
        }
        else{
        return false;
        }
}
if(questionNumber == 7){
        if(finalAnswer == allCorrectAnswers[6]){
        return true;
        }
        else{
        return false;
        }
}
return 0;
}
// This function is used to generate a random greeting for whenever the person gets the right answer.
void generateRandomGreeting(char greet[20]){

int randomNum = (rand() % 5) + 1;

if (randomNum == 1){
	greet = "Bravo";
	printf("%s", greet);
}
else if (randomNum == 2){
	greet = "Congrats";
	printf("%s", greet);
}
else if (randomNum == 3){
	greet = "Well done";
	printf("%s", greet);
}
else if (randomNum == 4){
	greet = "Very nice";
	printf("%s", greet);
}
else if (randomNum == 5){
	greet = "Proud of you";
	printf("%s", greet);
}
return;
}
// This function calculates the amount that the player gets if they get an answer wrong.
int calculateReducedAward(int questionNumber, int currentAwardAmount){
int reducedAward;
if (questionNumber % 2 == 0) {
	
	reducedAward = currentAwardAmount / 5;
	
}
else {
	reducedAward = currentAwardAmount / 2;
}
return reducedAward;
}

/******************** Compiling the program ************************************
The program should be compiled using the following flags: 
-std=c99
-Wall
compiling: gcc WhoWantsToBeAMillionaire.c -std=c99 -Wall -o WhoWantsToBeAMillionaire
*********************************************************
Running the Program
*********************************************************
 running: ./WhoWantsToBeAMillionaire
The user is prompted for 10 different inputs before the output is generated.
*********************************************************/

