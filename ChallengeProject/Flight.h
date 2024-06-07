#pragma once

#include <string>    // Include the necessary string header
#include <map>       // Include the necessary map header

// Forward declaration of Airport class
class Airport;

/**
 * Represents a flight, storing information about its departure, arrival, time, and available seats.
 *
 * The Flight class maintains flight details, including the flight number, departure and arrival locations,
 * departure time, and information about available seats. The multimap 'availableSeats' tracks seat availability,
 * using 'true' for available seats and 'false' for occupied seats.
 *
 * @Authors: Kai, Alex
 * @Version: 2023.12.12
 */
class Flight
{
public:
    // Constructors:
    // Default constructor initializes member variables
    Flight();

    /**
     * Parameterized constructor sets member variables with provided values.
     *
     * @param flightNumber: The flight number.
     * @param flightDeparture: The departure airport.
     * @param FlightArrival: The destination airport.
     * @param seats: The maximum number of seats.
     * @param flightTypeTag: International or national flight.
     */
    Flight(std::string flightNumber, Airport* flightDeparture, Airport* FlightArrival, int seats, std::string flightTypeTag);

    /**
     * Display detailed information about the flight.
     *
     * The flight details include the flight numbers, arrival, departure, and seats filled out of max seats.
     * For example: FN: 34256 Arrival: MSP Departure: Denver Seats: 30/35
     */
    void displayFlightDetails() const;

    /**
     * Set the arrival location for a flight.
     *
     * The arrival cannot be where the flight departs, and it must be an allowed airport.
     *
     * @param airport: The airport to set as the arrival location.
     * @return True if the arrival location is successfully set; otherwise, false.
     */
    bool setFlightArrival(const Airport& airport);

    /**
     * Get the arrival location for a flight.
     *
     * @return A pointer to the arrival location.
     */
    Airport getArrival() const;

    /**
     * Change the flight number of a flight.
     *
     * The flight number can't be equal to any other flight's number for the airport.
     *
     * @param newFlightNumber: The new flight number to set.
     * @return True if the flight number is successfully set; otherwise, false.
     */
    bool setFlightNumber(int newFlightNumber);

    /**
     * Receive the flight number of a flight.
     *
     * @return The flight number.
     */
    std::string getFlightNumber() const;

    /**
    * Receive the tag for the flight
    * 
    * @return the flightTypeTag
    */
    std::string getFlightTag() const;

    /**
     * Modify the departure location of a flight.
     *
     * The departure location cannot be the location it already is at.
     *
     * @param airport: The airport to set as the departure location.
     * @return True if the departure location is successfully set; otherwise, false.
     */
    bool setFlightDeparture(const Airport& airport);

    /**
     * Get the departure location for a flight.
     *
     * @return A pointer to the departure location.
     */
    Airport* getFlightDeparture() const;

    /**
    * Adding a seat to the availableSeats map
    * 
    * @return whether or not a seat could be added there.
    */
    bool addSeat(int seatNum);

    /**
    * Adding a seat to the availableSeats map
    *
    * @return whether or not a seat could be added there.
    */
    void removeSeat(int seatNum);

    /**
    * Modifying a seats number
    * 
    * @return whether or not the seat can be mofified. 
    */
    void modifySeats(int currentSeat, int newSeat);

    // Getting the total number of seats filled, returns the number of seats filled
    int getSeatsFilled();

    // Returns whether or not the flight is full, this happens when seats max is equal to seatsFilled
    bool flightIsFull();

private:
    std::string flightNumber;                     // The flight number. (100A for arrival 100D for departure)
    int seatsMax;                                 // The maximum number of seats.
    int seatsFilled;                              // The number of seats filled.

    std::string flightTypeTag;                    // International or national flight.

    Airport* departureLocation;                   // The airport where the flight departs.
    Airport* arrivalLocation;                     // The destination airport.
    std::string departureTime;                    // The departure time.
    std::multimap<int, bool> availableSeats;  // Multimap of seat availability (true for available, false for occupied).

    // Queue for waitlisted passengers
};
