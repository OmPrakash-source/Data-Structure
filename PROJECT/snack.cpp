#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

int BOARD_SIZE = 100;

// roll the dice
int rollDice()
{
    return (rand() % 6) + 1;
}

// check for snakes or ladders using switch
int checkPosition(int position)
{
    switch (position)
    {
    // Ladders: start -> end
    case 3:
        return 22;
    case 5:
        return 8;
    case 11:
        return 26;
    case 20:
        return 29;
    case 27:
        return 84;
    case 36:
        return 44;
    case 51:
        return 67;
    case 71:
        return 91;
    case 80:
        return 99;

    // Snakes: start -> end
    case 17:
        return 4;
    case 19:
        return 7;
    case 21:
        return 9;
    case 28:
        return 1;
    case 54:
        return 34;
    case 62:
        return 18;
    case 64:
        return 60;
    case 87:
        return 24;
    case 93:
        return 73;
    case 95:
        return 75;
    case 98:
        return 79;

    // Default: No change in position
    default:
        return position;
    }
}

// Function to print the board
// void printBoard(int playerPosition)
// {
//     cout << "\nSnakes and Ladders Board:\n";
//     for (int i = 100; i > 0; i--)
//     {
//         if (i == playerPosition)
//         {
//             cout << "[P] "; // Mark player's position
//         }
//         else
//         {
//             cout << i << " ";
//         }
//         if (i % 10 == 1)
//         {
//             cout << "\n"; // New line after every 10 numbers
//         }
//     }
//     cout << "\n";
// }

int main()
{
    // srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    int playerPosition = 0;

    cout << "Welcome to Snakes and Ladders!\n\n";
    cout << "Press Enter to roll the dice...\n";

    while (playerPosition < BOARD_SIZE)
    {
        // printBoard(playerPosition); // Print the board
        cin.get();                  // Wait for user to press Enter
        int diceRoll = rollDice();
        cout << "You rolled a " << diceRoll << "!\n";

        // Move the player
        playerPosition += diceRoll;

        // Check if the player exceeds the board size
        if (playerPosition > BOARD_SIZE)
        {
            playerPosition -= diceRoll;
            cout << "Roll exceeds board size! Stay at " << playerPosition << ".\n";
        }
        else
        {
            cout << "You moved to " << playerPosition << ".\n";

            // Check for snakes or ladders using switch
            int newPosition = checkPosition(playerPosition);
            if (newPosition != playerPosition)
            {
                if (newPosition > playerPosition)
                    cout << "Ladder! Climbing up to --> " << newPosition << ".\n";
                else
                    cout << "Snake! Sliding down to <-- " << newPosition << ".\n";
                playerPosition = newPosition;
            }

            cout << "Your current position: " << playerPosition << ".\n";
        }

        // Check for win
        if (playerPosition == BOARD_SIZE)
        {
            cout << "Congratulations! You reached 100 and won the game!\n";
            break;
        }
    }

    return 0;
}
