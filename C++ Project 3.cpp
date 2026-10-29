#include <iostream>

short userInput;
short question;

short getRequestedSeats()
{
    std::cout << "Welcome to XTC Bus Company\n";
    std::cout << "How many seats would you like to reserve?\n";

    std::cin >> userInput;

    while (userInput <= 0)
    {
        std::cout << "Please prove a valid amount, how many seats would you like to reserve?\n";
        std::cin >> userInput;
    }

    return userInput;
}

short getRemainingSeats()
{
    srand(time(NULL));

    const short busSeats = 1 + rand() % 51;

    return busSeats;
}

bool canReserveSeats(short amount_1, short amount_2)
{
    if (amount_1 < amount_2)
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
        std::cout << "There are enough for " << requestedSeats << " seats with " << remainingSeats << " free out of 50 seats\n";
        return;
    }
    else
    {
        std::cout << "There are not enough for " << requestedSeats << " seats with " << remainingSeats << " free out of 50 seats\n";
        return;
    }
}

int main()
{
    displayPrompt();

    return 0;
}