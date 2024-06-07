#include "Flight.h"   // Include the declaration of the Flight class
#include "Airport.h"  // Include the declaration of the Airport class
#include <iostream>   // Include the necessary input/output stream

// Default constructor initializes member variables
Flight::Flight() : flightNumber("0"), seatsMax(0), arrivalLocation(nullptr), departureLocation(nullptr), flightTypeTag(flightTypeTag)
{
    seatsFilled = 0;
}

// Parameterized constructor sets member variables with provided values
Flight::Flight(std::string flightNumber, Airport* flightDeparture, Airport* FlightArrival, int seats, std::string flightTypeTag)
{
    this->flightNumber = flightNumber;
    this->seatsMax = seats;

    this->arrivalLocation = FlightArrival;
    this->departureLocation = flightDeparture;

    this->flightTypeTag = flightTypeTag;
}

// Display detailed information about the flight
void Flight::displayFlightDetails() const
{
    std::cout << "Flight Number: " << this->flightNumber << "\t";
    std::cout << "Arrival: " << arrivalLocation->getName() << "\t";
    std::cout << "Departure: " << departureLocation->getName() << "\t";
    std::cout << "Seats: " << this->seatsFilled << "/" << this->seatsMax << "\t";
}

// Set the arrival location for a flight
bool Flight::setFlightArrival(const Airport& airport)
{
    bool set = false;

    // Check if the arrival is not the same as the departure
    if (airport.getLocation() != departureLocation->getLocation())
    {
        set = true;
    }

    // Check if it's an allowed airport (could be done when trying to add the flight to the airport)

    return set;
}

// Get the arrival location for a flight
Airport Flight::getArrival() const
{
    return *arrivalLocation;
}

// Change the flight number of a flight
bool Flight::setFlightNumber(int newFlightNumber)
{
    return (departureLocation->findFlight(std::to_string(newFlightNumber)) == nullptr);
}

// Receive the flight number of a flight
std::string Flight::getFlightNumber() const
{
    return flightNumber;
}

// Receive the flightTypeTag of a flight
std::string Flight::getFlightTag() const
{
    return flightTypeTag;
}

// Modify the departure location of a flight
bool Flight::setFlightDeparture(const Airport& airport)
{
    bool set = false;

    // Check if the departure is not the same as the current location
    if (airport.getLocation() != departureLocation->getLocation())
    {
        set = true;
    }

    return set;
}

// Get the departure location for a flight
Airport* Flight::getFlightDeparture() const
{
    return departureLocation;
}

// Adding a seat to the multimap
bool Flight::addSeat(int seatNum)
{
    // Check if the seat is within the allowed range
    if (seatNum <= seatsMax && seatNum > 0)
    {
        auto it = availableSeats.find(seatNum);

        // Check if the seat exists
        if (it != availableSeats.end())
        {
            // Check if the seat is already filled
            if (it->second == false)
            {
                return false;  // Seat is already occupied
            }

            // Mark the seat as filled
            it->second = false;
            seatsFilled++;

            return true;  // Seat successfully added
        }
        else
        {
            // If the seat doesn't exist in the multimap, add it and mark as filled
            availableSeats.insert({seatNum, false});
            seatsFilled++;

            return true;  // Seat successfully added
        }
    }

    return false;  // Seat not available or does not exist
}

// Removing seat from the multipmap
void Flight::removeSeat(int seatNum)
{
    availableSeats.erase(seatNum);
    seatsFilled--;
}

void Flight::modifySeats(int currentSeat, int newSeat)
{
    // Find the iterators for the current and new seats
    auto currentSeatIt = availableSeats.find(currentSeat);
    auto newSeatIt = availableSeats.find(newSeat);

    // Check if the seats exist in the multimap
    if (currentSeatIt != availableSeats.end() && newSeatIt != availableSeats.end())
    {
        // Swap the availability of the seats
        std::swap(currentSeatIt->second, newSeatIt->second);
        std::cout << "Seats " << currentSeat << " and " << newSeat << " modified.\n";
    }
    else
    {
        // Handle the case where one or both seats are not found
        std::cout << "One or both seats not found.\n";
    }
}

int Flight::getSeatsFilled()
{
    return seatsFilled;
}

bool Flight::flightIsFull()
{
    return seatsFilled >= seatsMax;
}
