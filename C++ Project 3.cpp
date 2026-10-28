#include <iostream>

int requestedSeats;

int GetRequestedSeats()
{
    std::cout << "Welcome to XTC Bus Company\n";
    std::cout << "How many seats would you like to reserve?\n";

    std::cin >> requestedSeats;

    return requestedSeats;
}

int GetRemainingSeats()
{
    srand(requestedSeats);
    const int busSeats = 1 + rand() % 51;

    return busSeats;
}

bool CheckSeatAmt(int requestedAmt, int remainingAmt)
{
    if (requestedAmt < remainingAmt)
    {
        std::cout << "You can reserve those seats";
        return true;
    }
    else
    {
        std::cout << "There are not enough for those seats";
        return false;
    }
}

int main()
{
    CheckSeatAmt(GetRequestedSeats(), GetRemainingSeats());

    return 0;
}