#include <iostream>

using namespace std;

// 5 and 4 up/down means mix later on..
enum kQuestionLevel {Easy = 1, Mid = 2, Hard = 3, MixLevel = 4};
enum kOperationType {Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5};

struct kMathQuiz {
    int QuestionsNumber = 0;
    kOperationType Operation;
    kQuestionLevel QuestionLevel; 
};

struct kPlayerScore {
    int CorrectAnswers = 0;
    int WrongAnswers = 0;
};

int RandomNum(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

short ReadNum(string Message)
{
    // No validation because idgaf and we already know how to!!
    short Num = 0;
    cout << Message;
    cin >> Num;

    return Num;
}

kOperationType InputOperation(string Message)
{
    short Operator = 0; 
    cout << Message;
    cin >> Operator;
    return kOperationType(Operator);  // Cast and return in one line
}

kQuestionLevel InputQuestionLevel(string Message)
{
    short Level = 0; 
    cout << Message;
    cin >> Level;
    return kQuestionLevel(Level);  // Cast and return in one line
}

kMathQuiz InputQuizInfo(kMathQuiz &Quiz)
{
    Quiz.QuestionsNumber = ReadNum("How many questions would you like? ");
    cout << endl;
    Quiz.QuestionLevel = InputQuestionLevel("Select difficulty level:\n  1) Easy\n  2) Medium\n  3) Hard\n  4) Mixed\nYour choice: ");
    cout << endl;
    Quiz.Operation = InputOperation("Select operation type:\n  1) Addition\n  2) Subtraction\n  3) Multiplication\n  4) Division\n  5) Mixed\nYour choice: ");

    return Quiz;
} 

void GenQuestions(int &Num1, int &Num2, kQuestionLevel QuizLevel)
{
    if(QuizLevel == kQuestionLevel::MixLevel)
        QuizLevel = kQuestionLevel(RandomNum(1,3));

    switch (QuizLevel) {

        case kQuestionLevel::Easy: {
            Num1 = RandomNum(1, 10);
            Num2 = RandomNum(1, 10);
        }
            break;

        case kQuestionLevel::Mid:  {
            Num1 = RandomNum(10, 100);
            Num2 = RandomNum(10, 100);
        }
            break;

        case kQuestionLevel::Hard: {
            Num1 = RandomNum(100, 1000);
            Num2 = RandomNum(100, 1000);
        }
            break;

        default:
            break;
    }
}

char OperatorSymbol (kOperationType Operator)
{
    if(Operator == kOperationType::MixOp)
        Operator = kOperationType(RandomNum(1,4));

    char Op = ' ';
    switch (Operator) {

        case kOperationType::Add:
            return Op = '+';

        case kOperationType::Sub:
           return Op = '-';

        case kOperationType::Mult:
            return Op = 'x';

        case kOperationType::Div:
            return Op = '/';

        default:
            break;
    }

    return Op;
}

void QuestionFormat(int i, int j, int Num1, int Num2, char Op)
{
    cout << "Question [" << i << "/" << j << "]\n" << endl;
    cout << Num1 << endl;
    cout << Num2 << "   " << Op << endl;
    cout << "------------------------------------------" << endl;
}

bool CheckAnswer(int &Num1, int &Num2, char Op, int Answer)
{
    switch (Op) {

        case '+':
            return (Num1 + Num2 == Answer);

        case '-':
            return (Num1 - Num2 == Answer);

        case 'x':
            return (Num1 * Num2 == Answer);

        case '/':
            return (Num1 / Num2 == Answer);

        default:
            break;
    }

    return -1;
}

string StQuestionLevel(kMathQuiz Quiz)
{
    switch (Quiz.QuestionLevel) {
        case kQuestionLevel::Easy:
            return "Easy";
        case kQuestionLevel::Mid:
            return "Mid";
        case kQuestionLevel::Hard:
            return "Hard";
        case kQuestionLevel::MixLevel:
            return "Mix";
    }
    return "Chico Balah";
}

void QuizResults(kMathQuiz Quiz, kPlayerScore Player)
{
    double ScorePercentage = (double) Player.CorrectAnswers / Quiz.QuestionsNumber * 100;

    cout << "\n------------------------------------------" << endl;
    if (ScorePercentage >= 60)
        cout << "Final Result is PASS :-)" << endl;
    else
        cout << "Final Result is FAIL :-(" << endl;

    string Operator = "";

    if (Quiz.Operation == kOperationType::MixOp)
        Operator = "Mix";
    else
        Operator = OperatorSymbol(Quiz.Operation);

    string QuestionsLevel = StQuestionLevel(Quiz);

    cout << "------------------------------------------" << endl;
    cout << "Score is %" << ScorePercentage << endl;
    cout << "Number of Questions: " << Quiz.QuestionsNumber << endl;
    cout << "Questions Level: " << QuestionsLevel << endl;
    cout << "Operation Type: " << Operator << endl;
    cout << "Number Of Correct Answers: " << Player.CorrectAnswers << endl;
    cout << "Number Of Wrong Answesrs: " << Player.WrongAnswers << endl;
    cout << "------------------------------------------" << endl;
}

void StartQuiz()
{
    char PlayChoice = ' ';
           do {

               kMathQuiz Quiz;
               kPlayerScore Player;
               
               InputQuizInfo(Quiz);

               int Num1 = 0;
               int Num2 = 0;
               int Answer = 0;
    
               for (int i = 1; i <= Quiz.QuestionsNumber; i++) {
                   
                   char Op = OperatorSymbol(Quiz.Operation);

                   GenQuestions(Num1, Num2, Quiz.QuestionLevel);
                   QuestionFormat(i, Quiz.QuestionsNumber, Num1, Num2, Op);

                   cin >> Answer;
                   cout << endl;

                   // cout << "----------------\n" ;
                   // cout << Num1 << '\n';
                   // cout << Num2 << '\n';
                   // cout << Op << endl;
                   // cout << Answer << endl;
                   // cout << "----------------\n" ;
                   
                   if (CheckAnswer(Num1, Num2, Op, Answer))
                       ++Player.CorrectAnswers;
                   else
                       ++Player.WrongAnswers;
               }
               
               QuizResults(Quiz, Player);
               cout << "Do you want to Play Again: Y/N: ";
               cin >> PlayChoice;
               cout << endl;
           
           }  while (PlayChoice == 'y' || PlayChoice == 'Y');
}

int main()
{
    srand((unsigned)time(NULL));

    StartQuiz();

    return 0;
}

// 1- How many questions do you want to answer:
// 2- Enter the questions difficulty: [1:Easy 2:Mid 3:Hard 4:Mix]
// 3- Enter Operation Type (for questions):  [1:Add 2:Sub 3:Mult 4:Div 5:Mix]
//
// Question [1/5]
//
// Number1
// Number2  Operation
//
// -------------------
// [input]
//
// Correct Answer/Wrong Answer Feedback
//
//
// Question [2/5]
//
// Number1
// Number2  Operation
//
// -------------------
// [input]
//
// Correct Answer/Wrong Answer Feedback
//
// -----------------------------------------
// Final Result is PASS/FAIL :-) :-(
// -----------------------------------------
//
// Number of Questions: N
// Questions Level:
// OpType:
// Number Of Correct Answers:
// Number Of Wrong Answesrs:
//
// -----------------------------------------
// Do you want to Play Again: Y/N: Y; Repeat

// For those wondering about these comments; This is how I think before I program.
// As you can see I analyzed the program into: [Data - Process - Output]
// Then I also sketched some functions I'd need (while thinking about what i wrote).
// After I've done that the rest is history, I just go and implement what's in my head
// Since the Idea has become very clear

/*
 *           Data:
 *           Number of Questions:  (Globally saved)
 *           Difficulty Level:     (Globally Saved)
 *           Operation  Type:      (Globally Saved)
 *
 *           Answers to the questions (Saved temporarily for judge)
 *           Number of Correct Answers (Globally Saved)
 *           Number of Wrong Answers   (Globally Saved)
 *
 *           Process:
 *                   Random(); Function
 *                   Determine the number of questions 
 *                   Determine the difficulty 
 *                   Determine the operatior 
 *                   Determine Answer Correct/Wrong
 *                   Determine the Final result (Pass/Fail)
 *                   Print the Result Header 
 *           
 *           Enum that contains: Operations + - * / 
 *           Struct that contains:
 *                               Total Questions being asked
 *                               (Questions Level)
 *                               (Questions Type)
 *                               Correct Answers count
 *                               Wrong   Answers count
 *                               Result Pass/Fail 
 *
 *          One function to convert the enum of operator to "+"
 *          One function to generate the questions based of difficulty
 */
