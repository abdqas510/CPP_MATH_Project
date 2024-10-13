Math Quiz Game

This project is a C++ Math Quiz Game that allows users to answer random math questions based on difficulty level and operation type. The user can select the level of questions (Easy, Medium, Hard, or Mixed) and choose the type of operation (Addition, Subtraction, Multiplication, Division, or Mixed).

Features

- Random Question Generation: Questions are randomly generated based on the selected difficulty and operation type.
- Multiple Operation Types: Includes addition, subtraction, multiplication, and division questions.
- Difficulty Levels: Users can choose from easy, medium, hard, or mixed-level questions.
- Result Tracking: After each question, the number of correct and wrong answers is tracked, and a final result is displayed at the end of the game.
- Replayable: Users can choose to replay the game after finishing.
  
Enums and Structs Used

1. Enums:

- enQuestionLevel: Represents the difficulty level of the questions (Easy, Medium, Hard, or Mixed).
- enOperationLevel: Represents the type of mathematical operation (Add, Sub, Mul, Div, or Mixed).
  
2. Structs:
  

- stQuestionNumbers: Holds the numbers for each question, operation character, user input, and question counter.
- stFinalResult: Tracks the final result, including correct and wrong answers, question level, and operation type.

  
How to Play


1. Select the number of questions you want to answer.
2. Choose the difficulty level (Easy, Medium, Hard, or Mixed).
3. Choose the operation type (Addition, Subtraction, Multiplication, Division, or Mixed).
4. Answer each question by inputting the correct result.
5. At the end of the game, view your final result: pass or fail based on the number of correct answers.

   
How to Run

To compile and run the program, use the following commands in the terminal:


g++ Project2_solution.cpp -o MathQuizGame
./MathQuizGame


Project Structure:

- main(): Initializes the game and starts the quiz.
- StartGame(): Main loop to play the game, with an option to replay.
- StartMath(): Generates questions, displays them, and checks user answers.
- FinalResultDisplay(): Displays the result summary after the quiz ends.

  

