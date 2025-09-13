#include <iostream>
#include <cstdlib>

using namespace std;

enum kGameValues {Rock = 1, Paper = 2, Scissor = 3};

struct kScore {

    short PlayerWins = 0;
    short Draw = 0;
    short ComputerWins = 0;
    string Winner = "";
    //   short ComputerLoses = 0;
    //  short PlayerLoses = 0;
};

short InputComputerChoice()
{
    // Forumula is () % (To - From + 1) + From;
    return rand() % (3 - 1 + 1) + 1;
}

short InputPlayerChoice(string Message)
{
    short Choice = 0;

    cout << Message;
    cin >> Choice;

    while(Choice != 3 && Choice != 2 && Choice != 1) {
        cout << "\nPlease enter a number between: [1] Rock [2]Paper [3]Scissor ";
        cin >> Choice;
    }

    cout << endl;
    return Choice;
}

short ReadRounds()
{
    short Rounds;
    cout << "How Many Rounds 1 to 10: ";
    cin >> Rounds;
    cout << endl;
    return Rounds;
}

kScore Round(kScore &RoundScore, short RoundNumber)
{
    // Each round score

    short PlayerChoice = 0;

    // Computer choice is generated randomly using Random(1, 3);
    short ComputerChoice = InputComputerChoice();

    cout << "Round[" << RoundNumber << "] Begins\n" << endl;
    PlayerChoice = InputPlayerChoice("Your Choice: [1]Rock [2]Paper [3]Scissor: ");

    kGameValues Player    =  kGameValues(PlayerChoice);
    kGameValues Computer  = kGameValues(ComputerChoice);


    if (Player == Computer) {
        ++RoundScore.Draw;
        RoundScore.Winner = "No Winner";
    }

    else if (Player == Rock && Computer ==  Scissor) {
        ++RoundScore.PlayerWins;
         RoundScore.Winner = "Player";
    }

    else if (Player == Paper && Computer == Rock) {
        ++RoundScore.PlayerWins;
         RoundScore.Winner = "Player";
    }

    else if (Player == Scissor && Computer == Paper) {
        ++RoundScore.PlayerWins;
         RoundScore.Winner = "Player";
    }

    else {
        ++RoundScore.ComputerWins;
         RoundScore.Winner = "Computer";
    }

    cout << "---------------Round [" << RoundNumber << "]----------------\n" << endl;


    string p_choice = "";
    switch (Player) {
        case Rock:
            p_choice = "Rock";
            break;
        case Paper:
            p_choice = "Paper";
            break;
        case Scissor:
            p_choice = "Scissor";
            break;

    }

    string c_choice = "";
    switch (Computer) {
        case Rock:
            c_choice = "Rock";
            break;
        case Paper:
            c_choice = "Paper";
            break;
        case Scissor:
            c_choice = "Scissor";
            break;
    }


    cout << "Player   Choice: " <<  p_choice << endl;
    cout << "Computer Choice: " << c_choice << endl;
    cout << "Round Winner   : [" <<  RoundScore.Winner << "]\n";

    cout << "\n-----------------------------------------\n" << endl;  // 41 characters
    return RoundScore;
}

string Winner(kScore FinalScore)
{
    if (FinalScore.ComputerWins > FinalScore.PlayerWins)
        return "Computer";

    else if (FinalScore.ComputerWins < FinalScore.PlayerWins)
        return "Player";

    else
        return "No Winner";
}

bool GameEnding(kScore TotalScore, short Rounds)
{

    char C;
    cout << "\t\t========================================================================\n";
    cout << "\t\t                    + + +   G A M E   O V E R   + + +                   \n";
    cout << "\t\t========================================================================\n";
    cout << "\t\t                             [Game Results]                             \n";
    cout << "\t\t------------------------------------------------------------------------\n";
    cout << "\t\t  Game Rounds        :  " << Rounds << "                                \n";
    cout << "\t\t  Player won times   :  " << TotalScore.PlayerWins << "                 \n";
    cout << "\t\t  Computer won times :  " <<TotalScore.ComputerWins << "                \n";
    cout << "\t\t  Draw times         :  " << TotalScore.Draw << "                       \n";
    cout << "\t\t  Final Winner       :  " << Winner(TotalScore) << "                     \n";
    cout << "\t\t------------------------------------------------------------------------\n";
    cout << "\t\t  Do you want to play again? Type Y or N: ";
    cin >> C;
    cout << "\t\t========================================================================\n\n\n";

    if (C == 'Y' || C == 'y')
        return true;
    else
        return false;
}

void Game()
{
    kScore TotalScore;
    short Rounds = ReadRounds();

    for(int i = 1; i <= Rounds; i++) {
        Round(TotalScore, i);
    }

    if(GameEnding(TotalScore, Rounds))
        Game();

}

int main()
{
    srand((unsigned)time(NULL));

    Game();

    return 0;
}

/* This is how I think before tackling a problem/project; */

// Globally Store:
// Game roudns
// Player Won Times
// Computer Won Times
// Draw Times
// Final Winner (compares won times between both)

// 1. Take game rounds as an input
// 2. Start the round by printing "Round [i] begins:"
// 3. Prompt the user to enter his game choice RPS
// 4.                PROCESS
// 5. output Round statistics
// 6. Iterate step 2 until rounds finished
// 7. print Game as a whole statistics
// 8. prompt user if they want to play again
// 9. if so repeat the whole program.
// 10. if not terminate the program.
