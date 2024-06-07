#include "Reservation.h"
#include <iostream> // Include any necessary headers for displaying information.

// Constructor
Reservation::Reservation()
{
    seatNumber = -1;
    reservationNumber = -43;
}

Reservation::Reservation(int seatNumber, Flight* flight)
    : seatNumber(seatNumber), flight(flight)
{
    // Generate a unique reservation number 
    // For simplicity, a placeholder is used here for now.
    reservationNumber = reservationNumberGenerator();
}

Flight* Reservation::getFlight() const
{
    return flight;
}

int Reservation::getSeatNum() const
{
    return seatNumber;
}

// Methods

void Reservation::displayReservationDetails() const
{
    std::cout << "Reservation Number: " << reservationNumber << "\n";
    std::cout << "Flight Details: ";
    flight->displayFlightDetails();
    std::cout << "Seat Number: " << seatNumber << "\n";
}

// Modifying the seat
// Seat num is the desired seat seatNumber is the current seat.
bool Reservation::modifySeatNumber(int seatNum)
{
    if (flight->addSeat(seatNum))
    {
        flight->removeSeat(seatNumber);
        seatNumber = seatNum;
        flight->addSeat(seatNumber);
        std::cout << "Seat number modified for Reservation " << reservationNumber << "\n";
        return true;
    }
    else
    {
        std::cout << "New seat number is the same as the current seat number for Reservation or taken" << reservationNumber << "\n";
        return false;
    }
}

bool Reservation::modifyFlight(Flight* newFlight)
{
    if (newFlight->getFlightNumber() != flight->getFlightNumber())
    {
        // Modify the flight information

        if (newFlight->addSeat(seatNumber))
        {
            flight->removeSeat(seatNumber);
            flight = newFlight;
            std::cout << "Flight modified for Reservation " << reservationNumber << "\n";
            return true;
        }

        std::cout << "New flight has that seat already taken " << reservationNumber << "\n";
        return false;

    }
    else
    {
        std::cout << "New flight is the same as the current flight for Reservation " << reservationNumber << "\n";
        return false;
    }
}

int Reservation::getReservationNumber() const
{
    return reservationNumber;
}



// Placeholder for generating a unique reservation number (you may implement your logic)
int Reservation::reservationNumberGenerator()
{
    static int reservationCounter = 1;
    return reservationCounter++;
}
