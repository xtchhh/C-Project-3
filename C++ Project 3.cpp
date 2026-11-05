#include <iostream>
#include <cstdlib>

short userInput = 1;
short remainingTotal;
const short totalBusSeats = 50;

//simple validation
short getRequestedSeats()
{
    std::cout << "\nWelcome to the XTC Bus Company!\n";
    std::cout << "How many seats would you like to reserve? (Enter 0 to terminate this session)\n";

    std::cin >> userInput;

    remainingTotal += userInput;

    return remainingTotal;
}

bool canReserveSeats(short request_total_amount, short bus_amount)
{
    if (request_total_amount < bus_amount)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void displayPrompt()
{
    while (userInput > 0)
    {
        auto requestedSeats = getRequestedSeats();

        if (userInput <= 0)
        {
            std::cout << "Goodbye!";
            return;
        }

        if (canReserveSeats(requestedSeats, totalBusSeats))
        {
            std::cout << "\nThere are enough seats for you to reserve, there are " << totalBusSeats - requestedSeats << " seats left. Thank you.\n";
        }
        else
        {
            std::cout << "\nThere are not enough seats for you to reserve, there are " << totalBusSeats - requestedSeats << " seats left. Thank you\n";
        }
    }
    return;
}

int main()
{
    displayPrompt();

    return 0;
}