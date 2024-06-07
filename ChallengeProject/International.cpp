#include "International.h"
#include <iostream> // Include any necessary headers for displaying information.

// Constructor
International::International(std::string name, std::string location, int maxSize)
    : Airport(name, location, maxSize) // Call the base class constructor
{
    type = "international";
}

// Methods

void International::displayAvailableFlights() const
{
    std::cout << "International Airport Displaying Available Flights:\n";
    for (const auto& flight : flightsMap)
    {
        flight.second.displayFlightDetails();
        std::cout << "\n";
    }
}

bool International::addFlight(const Flight& flight)
{
    if (flight.getFlightTag() != "international")
    {   
        // It is a national flight we need to check if it is trying to go somewhere in the same location.
        if (flight.getArrival().getLocation() == location)
        {
            flight.displayFlightDetails();
            flightsMap[flight.getFlightNumber()] = flight;
            return true;
        }

        return false;
    }

    if (flight.getArrival().getType() != "international")
    {
        return false;
    }

    //std::cout << "International Airport Adding Flight:\n";
    flight.displayFlightDetails();
    flightsMap[flight.getFlightNumber()] = flight;

    return true;
}

// possbilt change to boolean and use the parent class to do some of this.
void International::removeFlight(std::string flightID)
{
    std::cout << "International Airport " << getInfo() << " Removal of flight ";
    
    Airport::removeFlight(flightID);
}