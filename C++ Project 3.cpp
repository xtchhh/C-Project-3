#include <iostream>

int requestedSeats;

int GetUserInput()
{
    std::cout << "Welcome to XTC Bus Company\n";
    std::cout << "How many seats would you like to reserve?\n";

    std::cin >> requestedSeats;

    return requestedSeats;
}

int GetBusSeats()
{
    const int busSeats = rand() % 51;

    return busSeats;
}

bool CheckSeats(int seats, int remainingSeats)
{
    if (seats > remainingSeats)
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
    CheckSeats(GetUserInput(), GetBusSeats());

    return 0;
}