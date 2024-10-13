// Project2_solution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

using namespace std;

enum enQuestionLevel {Easy = 1,Med = 2, Hard = 3, QMix = 4};

enum enOperationLevel {Add = 1, Sub = 2, Mul = 3, Div = 4, OMix = 5};

struct stQuestionNumbers {

	int firstNumber = 0;
	int SecondNumber = 0;
	char Operationchar;
	int Input = 0;
	short QuestionsCounter = 0;
	short QuestionsLength = 0;

};

struct stFinalResult {
	
	enQuestionLevel QuestionLevel;
	enOperationLevel OperationType;
	int CorrectCounter = 0;
	int WrongCounter = 0;

};

int ReadPositiveNumber(string msg) {

	int num = 0;

	do {
		cout << msg;
		cin >> num;
	} while (num <= 0);
	return num;

}

int RandomNumber(int From, int To) {

	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

char OperationTypeChar(enOperationLevel Operation) {
	char arrOperations[4] = {'+','-','*','/'};
	if (Operation == enOperationLevel::OMix) {
		return arrOperations[RandomNumber(1, 4) - 1];
	}
	return arrOperations[Operation - 1];
}

int GenerateNumbers(enQuestionLevel Level) {
	switch (Level) {
	case enQuestionLevel::Easy:
		return RandomNumber(1, 10);
		
	case enQuestionLevel::Med:
		return RandomNumber(11, 50);
		
	case enQuestionLevel::Hard:
		return RandomNumber(51, 100);
	case enQuestionLevel::QMix:

		return RandomNumber(1,100);
	}
}

enOperationLevel OperationTypeQuestion() {

	int num;

	do {

	cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
	cin >> num;

	} while (num < 1 || num > 5);
	return (enOperationLevel)num;
}

enQuestionLevel QuestionLevel() {

	int num;
	do {
		cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
		cin >> num;
	} while (num < 1 || num > 4);
	return (enQuestionLevel)num;
}

void DisplayQuestion(stQuestionNumbers &Numbers, enOperationLevel OperationLevel, enQuestionLevel QuestionLevel) {

	
	cout << "\n\nQuestion [" << Numbers.QuestionsCounter+1 << "/" << Numbers.QuestionsLength << "]" << "\n\n";
	Numbers.firstNumber = GenerateNumbers(QuestionLevel);
	Numbers.SecondNumber = GenerateNumbers(QuestionLevel);
	Numbers.Operationchar = OperationTypeChar(OperationLevel);
	cout << Numbers.firstNumber << endl;
	cout << Numbers.SecondNumber << " " << Numbers.Operationchar << endl;
	cout << "________\n";
	cin >> Numbers.Input;
}

int CalculateResult(stQuestionNumbers Numbers) {

	switch (Numbers.Operationchar) {
	case '+':
		return Numbers.firstNumber + Numbers.SecondNumber;
	case '-':
		return Numbers.firstNumber - Numbers.SecondNumber;
	case '/':
		return Numbers.firstNumber / Numbers.SecondNumber;
	case '*':
		return Numbers.firstNumber * Numbers.SecondNumber;
	}
}

string FinalResult(stFinalResult Final) {

	if (Final.CorrectCounter >= Final.WrongCounter) {
		return "Pass :-)";
	}
	return "Fail :-(";
}

string QuestionLevelNames(enQuestionLevel Level) {
	string arrLevel[4] = { "Easy","Med","Hard","Mix" };
	return arrLevel[Level - 1];
}

string OperationTypeNames(enOperationLevel OpType) {
	string arrOpType[5] = { "Add","Sub","Mul","Div","Mix" };
	return arrOpType[OpType - 1];
}

void FinalResultDisplay(stQuestionNumbers Numbers, stFinalResult Final) {

	cout << "\n\n______________________________________________\n\n";
	cout << "Final Result is " << FinalResult(Final) << endl;
	cout << "______________________________________________\n\n";
	cout << "Number of Questions: " << Numbers.QuestionsLength << endl;
	cout << "Question Level     : " << QuestionLevelNames(Final.QuestionLevel) << endl;
	cout << "OpType             : " << OperationTypeNames(Final.OperationType) << endl;
	cout << "Numbers of Right Answer: " << Final.CorrectCounter << endl;
	cout << "Number of Wrong Answers: " << Final.WrongCounter << endl;
}

void StartMath() {

	stQuestionNumbers Numbers;
	stFinalResult Final;

	Numbers.QuestionsLength = ReadPositiveNumber("How Many Questions do you want to answer ? ");
	
	Final.QuestionLevel = QuestionLevel();
	Final.OperationType = OperationTypeQuestion();
	

	for ( Numbers.QuestionsCounter; Numbers.QuestionsCounter < Numbers.QuestionsLength; Numbers.QuestionsCounter++) {

		DisplayQuestion(Numbers, Final.OperationType, Final.QuestionLevel);

		int CorrectAnswer = CalculateResult(Numbers);
		
		if (Numbers.Input == CorrectAnswer ) {

			Final.CorrectCounter++;
			system("color 2F");
			cout << "Right Answer :-)";

		}
		else {

			Final.WrongCounter++;
			system("color 4F");
			cout << "Wrong Answer :-(\a\n";
			cout << "The right Answer is : " << CorrectAnswer;
		}
	}
	FinalResultDisplay(Numbers, Final);	
}

void ResetScreen() {
	system("cls");
	system("color 0F");
}

void StartGame() {

	char Answer = 'Y';
	do {
		ResetScreen();
		StartMath();
		cout << "\nDo you want to Play again? Y/N  ";
		cin >> Answer;

	} while (Answer == 'Y' || Answer == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;

}


