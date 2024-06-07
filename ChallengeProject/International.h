#pragma once
#include "Airport.h"

/**
 * Manages operations specific to an International Airport.
 *
 * The International class is responsible for controlling and overseeing activities
 * within an international airport. It enforces the rule that international flights are bound
 * for other countries, while national flights operate within the host country. While this class
 * shares some functionalities with the base Airport class, it adds specific behaviors
 * tailored to international airports.
 *
 * @Authors: Alex, Kai
 * @Version: 2023.11.05
 */
class International : public Airport
{
public:
    // Constructors
    International(std::string name, std::string location, int maxSize);

    // Methods
    void displayAvailableFlights() const override;
    bool addFlight(const Flight& flight) override;
    void removeFlight(std::string flightID) override;
};

