#pragma once
#include <map>
#include <unordered_map>
#include "Flight.h"
#include "Reservation.h"

/**
 * Control the events happening in the airport.
 *
 * This class is responsible for managing airport operations.
 *
 * @Authors: Alex, Kai
 * @Version: 2023.12.8
 */
class Airport
{
protected:
    std::string name;
    std::string location;
    std::map<std::string, Flight> flightsMap; // map of flights going out
    std::unordered_map<int, Reservation*> reservations; // Passenger reservations.
    std::string type;

    int maxSize; // maximum number of planes allowed at airport.

public:

    // Constructors
    Airport();
    Airport(std::string name, std::string location, int maxSize);

    // Methods
    std::string getName() const; // get the name
    std::string getLocation() const; // get the location of the airport
    std::string getInfo() const; // gets information about the airport
    std::string getType() const;

    int getPlaneCount() const; // Returns the total number of planes at the airport
    int getReservationCount() const; // Returnsx the total numbert of reseravatiuons at the airprt

    Flight* findFlight(std::string flightNumber); // Searches to see if that flight already exists
    Reservation* findReservation(int reservationNumber); // Attempts to find a reservation to see if it already exists

    virtual void displayAvailableFlights() const; // Displays the flights available from the airport
    virtual bool addFlight(const Flight& flight); // Adding a flight to the airport if it matches the parameters in the method.
    virtual void removeFlight(std::string flightID); // Removes a flight from the airport

    bool makeReservation(const Reservation& reservation); // Creatres a reservation
    bool cancelReservation(int reservationID); // Cancels a reservation
    bool modifyReservation(int reservationID); // Modifies some information about the resrevation
};

