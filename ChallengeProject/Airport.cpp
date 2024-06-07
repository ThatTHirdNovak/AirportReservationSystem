#include "Airport.h"
#include <iostream>

// Last modified 12/20/23

// Constructors
Airport::Airport() : maxSize(0) {}

Airport::Airport(std::string name, std::string location, int maxSize)
    : name(name), location(location), maxSize(maxSize)
{
    type = "default";
}

// Methods

std::string Airport::getName() const
{
    return name;
}

std::string Airport::getLocation() const
{
    return location;
}

std::string Airport::getInfo() const
{
    return name + ", " + location;
}

std::string Airport::getType() const
{
    return type;
}

Flight* Airport::findFlight(std::string flightNumber)
{
    for (auto& pair : flightsMap)
    {
        if (pair.second.getFlightNumber() == flightNumber)
        {
            return &pair.second;
        }
    }
    return nullptr;
}

Reservation* Airport::findReservation(int reservationNumber)
{
    auto it = reservations.find(reservationNumber);

    // Check if the reservation is found and return a pointer
    if (it != reservations.end())
    {
        return it->second;
    }
    else
    {
        // If the reservation is not found, return nullptr
        return nullptr;
    }
}

void Airport::displayAvailableFlights() const
{
    std::cout << "Available flights at " << getInfo() << ":\n";
    for (const auto& pair : flightsMap)
    {
        pair.second.displayFlightDetails();
        std::cout << "\n";
    }
}

bool Airport::addFlight(const Flight& flight)
{
    flightsMap[flight.getFlightNumber()] = flight;
    return true;
}

void Airport::removeFlight(std::string flightID)
{
    // Searching for the flight to see if it is there.
    auto it = flightsMap.find(flightID);

    if (it != flightsMap.end())
    {
        flightsMap.erase(it);
        std::cout << flightID << " was successful." << "\n";
    }
    else
    {
        std::cout << flightID << " was unsuccessful, flight not found." << "\n";
    }
}

bool Airport::makeReservation(const Reservation& reservation)
{
    int reservationID = reservation.getReservationNumber();

    // Check if the reservation with the given ID already exists
    if (reservations.find(reservationID) == reservations.end())
    {
        // Find the flight associated with the reservation
        auto it = flightsMap.find(reservation.getFlight()->getFlightNumber());

        // Check if the flight is found and not full
        if (it != flightsMap.end())
        {
            Flight* flight = &it->second;

            if (!flight->flightIsFull())
            {
                if (flight->addSeat(reservation.getSeatNum()))
                {
                    // Add the reservation to the reservations map
                    // Note: Use new to allocate a dynamic Reservation object
                    reservations[reservationID] = new Reservation(reservation);

                    std::cout << "Reservation with ID " << reservationID << " made at " << getInfo() << "\n";
                    return true;
                }
            }
        }

        // If any condition fails, print a message and return false
        std::cout << "Reservation with ID " << reservationID << " failed at " << getInfo() << "\n";

        return false;
    }
    else
    {
        // If the reservation with the given ID already exists, print a message and return false
        std::cout << "Reservation with ID " << reservationID << " already exists at " << getInfo() << "\n";
        return false;
    }
}

bool Airport::cancelReservation(int reservationID)
{
    // Finding the reservation
    auto it = reservations.find(reservationID);
    if (it != reservations.end())
    {
        // Now we are finding the Flight
        Reservation* reservation = it->second;

        auto i = flightsMap.find(reservation->getFlight()->getFlightNumber());

        if (i != flightsMap.end())
        {
            // In here we are cancelling the reservation

            Reservation* temp = reservation;
            reservations.erase(it);

            Flight* flight = &i->second;
            flight->removeSeat(temp->getSeatNum());

            // Delete the Reservation object
            delete temp;

            std::cout << "Reservation with ID " << reservationID << " canceled at " << getInfo() << "\n";
            return true;
        }
    }
    else
    {
        std::cout << "Reservation with ID " << reservationID << " not found at " << getInfo() << "\n";
        return false;
    }
    return false;
}

bool Airport::modifyReservation(int reservationID)
{
    auto it = reservations.find(reservationID);
    if (it != reservations.end())
    {
        Reservation* reservation = it->second;
        std::cout << "Here is your current reservation: " << "\n";
        reservation->displayReservationDetails();

        std::cout << "What would you like to modify: \n1) flight\n2) seat number\n3) cancel" << "\n";

        int choice;
        std::cin >> choice;

        if (!std::cin.fail() && std::cin.peek() == '\n')
        {
            switch (choice)
            {
            case 1:
            {
                std::cout << "Enter flight number for desired change: " << "\n";

                std::string flightID;
                std::cin >> flightID;

                Flight* selectedFlight1 = findFlight(flightID);
                if (selectedFlight1 == nullptr)
                {
                    std::cout << "Flight not found.\n";
                    break;
                }

                reservation->modifyFlight(selectedFlight1);
                break;
            }
            case 2:
            {
                std::cout << "Enter new seat number: " << "\n";

                int seat;
                std::cin >> seat;

                if (std::cin.fail() || std::cin.peek() != '\n')
                {
                    std::cout << "Invalid input.\n";
                    break;
                }

                // Find the flight associated with the reservation
                auto it = flightsMap.find(reservation->getFlight()->getFlightNumber());

                reservation->modifySeatNumber(seat); // Note: Use -> for pointers
                break;
            }
            case 3:
                cancelReservation(reservationID); // Reuse the existing logic
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter an integer please.\n";
        }

        return true;
    }
    else
    {
        std::cout << "Reservation with ID " << reservationID << " not found at " << getInfo() << "\n";
        return false;
    }
}

int Airport::getPlaneCount() const
{
    int count = 0;

    for (auto it = flightsMap.begin(); it != flightsMap.end(); it++)
    {
        count++;
    }

    return count;
}

int Airport::getReservationCount() const
{
    int count = 0;

    for (auto it = reservations.begin(); it != reservations.end(); it++)
    {
        count++;
    }

    return count;
}
