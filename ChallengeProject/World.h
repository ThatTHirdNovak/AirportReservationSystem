#include <string>
#include <map>
#include "Airport.h"
#include "International.h"
#include "National.h"

#pragma once

/**
 * Represents the collection of all airports in the world.
 *
 * The World class maintains a collection of airports around the world, organized alphabetically by name
 * in a multimap. It provides methods for retrieving specific airports, adding new airports to the collection,
 * and displaying information about the airports.
 *
 * @Authors: Alex, Kai
 * @Version: 2023.12.8
 */
class World
{
public:

    // Constructor

    World();

    Airport* getAirport(std::string airport) const; // Get information about a specific airport.
    bool addAirport(Airport* airport); // Add an airport to the collection.
    void displayAirports() const; // Display information about the airports.

    Flight* findFlightID(std::string flightID) const; // Finding a flight using it's flight id

    // Reads a file with airports.
    void processLine(const std::string& line);
    void initializeAirports();

private:
    std::multimap<std::string, Airport*> airports; // Multimap storing all the airports.
    int airportCount; // The count of airports in the world (consider if it's necessary to store this explicitly).
};