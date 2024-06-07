#include "World.h"
#include <sstream>
#include <iostream>
#include <fstream>

// Constructor
World::World() : airportCount(0) 
{
    initializeAirports();
}

// Get information about a specific airport.
Airport* World::getAirport(std::string airportName) const
{
    auto it = airports.find(airportName);

    if (it != airports.end()) 
    {
        return (it->second);
    }

    // If the airport is not found returning a nullptr.
    return nullptr;
}

// Add an airport to the collection.
bool World::addAirport(Airport* airport)
{
    // Check if the airport pointer is valid (not null)
    if (airport == nullptr)
    {
        // Handle the case where the provided airport pointer is null.
        return false;
    }

    auto result = airports.insert({ airport->getName(), airport });

    if (result != airports.end())
    {
        // Airport was successfully added
        ++airportCount;
        return true;  // Return true if the airport was added successfully
    }
    else
    {
        return false;  // Return false if the airport already exists
    }
}


// Display information about the airports.
void World::displayAirports() const
{
    // Implement logic to display information about all airports in the multimap.

    for (auto it = airports.begin(); it != airports.end(); ++it)
    {
        const Airport* airport = it->second;

        // Print airport information (use the display method in the Airport class)
        std::cout << "Airport: " << airport->getName() << ", Location: " << airport->getLocation() << "\n";
        
        if (airport->getPlaneCount() == 0)
        {
            std::cout << "No flights available" << "\n\n";
        }
        else
        {
            airport->displayAvailableFlights();
            std::cout << "\n";
        }
    }
}

Flight* World::findFlightID(std::string flightID) const
{
    // TODO Loop through the airports multimap
    // Check each airport for that flightID until it is found, once found, return it. 

    for (auto it = airports.begin(); it != airports.end(); ++it)
    {
        Airport* airport = it->second;

        Flight* flight = airport->findFlight(flightID);

        if (flight != nullptr)
        {
            return flight;
        }
    }

    return nullptr;
}

void World::initializeAirports()
{
    std::ifstream inputFile("../Challengeproject/WorldCreation.txt");
    std::string line;

    while (std::getline(inputFile, line)) {
        processLine(line);
    }

    inputFile.close();  // Close the file when done
}

void World::processLine(const std::string& line) {
    std::istringstream iss(line);
    std::string objectType;

    if (iss >> objectType) {
        if (objectType == "Airport") {
            // Parse Airport details
            std::string name, location, type;
            int maxSize;

            iss >> name >> location >> type >> maxSize;

            Airport* airport = nullptr;

            if (type == "national") {
                airport = new National(name, location, maxSize);
            }
            else if (type == "international") {
                airport = new International(name, location, maxSize);
            }
            else {
                std::cout << "Error: Unknown airport type in line: " << line << std::endl;
                return;
            }

            // Add the airport to the world
            if (!addAirport(airport)) {
                std::cout << "Failed to add airport: " << airport->getName() << std::endl;
                delete airport; // Cleanup if the addition fails
            }
        }
        else if (objectType == "Flight") {
            // Parse Flight details
            std::string flightNumber, departureAirportName, arrivalAirportName, flightType;
            int seats;

            iss >> flightNumber >> departureAirportName >> arrivalAirportName >> seats >> flightType;

            // Find departure and arrival airports
            Airport* departureAirport = getAirport(departureAirportName);
            Airport* arrivalAirport = getAirport(arrivalAirportName);

            // Check if airports exist
            if (departureAirport && arrivalAirport) {
                // Create a Flight object
                Flight* flight = new Flight(flightNumber, departureAirport, arrivalAirport, seats, flightType);

                // Add the flight to the departure airport
                if (departureAirport->addFlight(*flight)) {
                    std::cout << "Flight added: " << flight->getFlightNumber() << std::endl;
                }
                else {
                    std::cout << "Failed to add flight: " << flight->getFlightNumber() << std::endl;
                    delete flight; // Cleanup if the addition fails
                }
            }
            else {
                std::cout << "Error: Invalid airports for flight: " << flightNumber << std::endl;
            }
        }
        else {
            std::cout << "Error: Unknown object type in line: " << line << std::endl;
        }
    }
    else {
        std::cout << "Error: Unable to read object type from line: " << line << std::endl;
    }
}

