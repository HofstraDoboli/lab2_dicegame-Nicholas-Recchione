/* Add your name here */
    
#include <iostream>
#include <cstdlib>  // contains the rand() and srand() function 
#include <ctime>    // time() function
using namespace std;


int main()
{
    srand(time(0)); // initialize random seed generator to current time: 
					// needed to generate a different sequence of random numbers
					// each time you run your program

    char startGame  = 'S'; //The character the user presses to start game
    char playGame   = 'Y'; //The character the user presses to play the game again
    char rollAgain  = 'C'; //The character the user press to roll the dice again
    int diceSum     = 0;   //Keeps track of the sum of the two dice
    int gamesWon    = 0;   //Keeps track of the total games won
    int gamesLost   = 0;   //Keeps track of the total games lost
    int timesRolled = 0;   //Keeps track of the total amount the dice were rolled
    int gamesPlayed = 0;   //Keeps track of the total games played

cout << "Welcome to my dice game!"<< endl << endl;
cout << "The game of craps is perhaps the most famous of all dice games. \nThe player begin by throwing two standard dice. If the sum of \nthese dice is 7 or 11, the player wins. If the sum is 2,3 or 12, \nthe player loses. Otherwise, the sum becomes the player’s point. \nThe player continues to roll until either the point comes up again, in which \ncase the player wins, or the player throws 7, in which case they lose." << endl << endl; 
cout << "Press S to start the game or X to exit." << endl;
cin >> startGame; //input is taken from the user on wether or not to start the game

    if(startGame == 'S') //If the user in puts S the game begins
    {
        while(playGame == 'Y') //The game will continue to repeat as long as the user keeps entering Y
        {
            int point  = 0;             //Keeps track of the user's point
            int dice1  = rand()%6+1;    //Selects a value between 1 and 6 at random
            int dice2  = rand()%6+1;
            diceSum    = dice1 + dice2; //Adds the to values of the dice together
            timesRolled += 1;            

            cout << "\nLet's roll two dice! You got " << dice1 << " and " << dice2 << "." << endl;
            cout << "Your sum is " << diceSum << "!" << endl;
            if (diceSum == 7 || diceSum == 11) //If the sum of the dice equals 7 or 11 the user wins 
            {                                  //and the variable gamesWon increases by 1
                cout << "You Win!!! \nExcellent job!!" << endl;
                gamesWon += 1;
            }
            else if (diceSum == 2 || diceSum == 3 || diceSum == 12) //If the sum of the dice equals 7 or 11 the user loses
            {                                                       //and the variable gamesLost increases by 1
                cout << "You lost!!! \nTry again!!" << endl;
                gamesLost += 1;
            }
            else
            {
                point += diceSum;                                              //adds diceSum to point
                cout << "This is you point! \nPress C to roll again!" << endl; //and allows ths user to roll again
                cin >> rollAgain;

                while (rollAgain == 'C') //secondary while loop for when the user rolls agian
                {
                    dice1      = rand()%6+1; //randomizes the dice again
                    dice2      = rand()%6+1;
                    diceSum    = dice1 + dice2;

                    cout << "\nLet's roll two dice! You got " << dice1 << " and " << dice2 << "." << endl;
                    cout << "Your sum is " << diceSum << "!" << endl;
                    cout << "Your point is " << point << "!" << endl;

                    if(point == diceSum)
                    {
                        cout << "You won! \nGreat job!!" << endl; //If the dice sum equals the users point
                        rollAgain = 'N';                          // the user wins and the secondary while loop
                        gamesWon += 1;                            // ends and gamesWon increases by 1
                    }
                    else if(diceSum == 7)
                    {
                        cout << "You Lost! \nTry agian!!" << endl; //If the dice sum equals 7 the user loses
                        rollAgain = 'N';                           //the secondary while loop ends and
                        gamesLost += 1;                            //gamesLost increases by 1
                    }
                    else
                    {
                        cout << "Press C to roll again!" << endl; //The users gets a sum other than their point
                        cin >> rollAgain;                         //or 7 they roll again and the while loop repeats
                        timesRolled += 1;                         //and timesRolled increases by 1
                    }
                }
            }
            cout << "Would you like to play again? (Y/N)" << endl; //User gets the option to replay the game
            cout << "Enter: ";                                     
            cin >> playGame;
            gamesPlayed += 1;                                      //gamesPlayed increases be 1
        } 
        cout << "\nYou played " << gamesPlayed << " games, you won " << gamesWon << " games and you lost " << gamesLost << " games!";
        cout << "You rolled " << timesRolled << "!" << endl;
    }
}