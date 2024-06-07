#pragma once
#include "Airport.h"
#include "International.h"
#include "National.h"

/**
 * Manages operations specific to a National Airport.
 *
 * The National class is responsible for overseeing and controlling activities within a national airport.
 * It enforces the rule that only national flights can arrive and depart from this airport, although they
 * may depart to international airports. This class shares certain functionalities with the base Airport class,
 * while incorporating specific behaviors tailored to national airports.
 *
 * @Authors: Alex, Kai
 * @Version: 2023.12.11
 */
class National : public Airport
{
public:
    // Constructors
    National(std::string name, std::string location, int maxSize);

    // Methods

    // Displaying the flights that are available for this airport
    void displayAvailableFlights() const override;

    // Adding a specific flight to the Airport
    bool addFlight(const Flight& flight) override;

    // REmoving a specific flight to the airport.
    void removeFlight(std::string flightID) override;
};

