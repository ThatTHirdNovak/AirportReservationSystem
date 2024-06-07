#include "National.h"
#include <iostream> // Include any necessary headers for displaying information.

// Constructor
National::National(std::string name, std::string location, int maxSize)
    : Airport(name, location, maxSize) // Call the base class constructor
{
    type = "national";
}

// Methods

void National::displayAvailableFlights() const
{
    std::cout << "National Airport Displaying Available Flights:\n";
    for (const auto& flight : flightsMap)
    {
        flight.second.displayFlightDetails();
        std::cout << "\n";
    }
}

bool National::addFlight(const Flight& flight)
{
    // Add national-specific logic for adding a flight. (Can only be National Flights)
    
    if (flight.getFlightTag() != "national")
    {
        return false;
    }

    if (location != flight.getArrival().getLocation())
    {
        return false;
    }

    //std::cout << "National Airport Adding Flight:\n";
    flight.displayFlightDetails();
    flightsMap[flight.getFlightNumber()] = flight;

    return true;
}

void National::removeFlight(std::string flightID)
{
    std::cout << "International Airport " << getInfo() << " Removal of flight ";

    Airport::removeFlight(flightID);
}
