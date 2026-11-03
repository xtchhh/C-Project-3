#include <iostream>
#include <cstdlib>

short userInput = 1;
short question;
const short totalBusSeats = 50;

//simple validation
//second stream input object reassigns userInput
short getRequestedSeats()
{
    std::cout << "\nWelcome to the XTC Bus Company!\n";
    std::cout << "How many seats would you like to reserve? (Enter 0 to terminate this session)\n";

    std::cin >> userInput;

    if (userInput <= 0)
    {
        std::cout << "Goodbye!";
        std::exit(0);
    }

    return userInput;
}

//scaling and shifting
//time function returning time_t object type
short getRemainingSeats()
{
    srand(time(NULL));

    short remainingBusSeats = 1 + rand() % totalBusSeats + 1;

    return remainingBusSeats;
}

bool canReserveSeats(short request_amount, short bus_amount)
{
    if (request_amount < bus_amount)
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
    auto requestedSeats = getRequestedSeats();
    auto remainingSeats = getRemainingSeats();

    if (canReserveSeats(requestedSeats, remainingSeats))
    {
        std::cout << "\nThere are enough for " << requestedSeats << " seats with " << remainingSeats << " free out of " << totalBusSeats << " seats\n";
        return;
    }
    else
    {
        std::cout << "\nThere are not enough for " << requestedSeats << " seats with " << remainingSeats << " free out of " << totalBusSeats << " seats\n";
        return;
    }
}

int main()
{
    while (userInput > 0)
    {
        displayPrompt();
    }

    return 0;
}