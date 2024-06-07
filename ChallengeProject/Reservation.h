#include <string>
#include "Flight.h"
#pragma once

/**
 * Represents a flight reservation made by a passenger.
 *
 * The Reservation class stores reservation details, including a unique reservation number,
 * the associated passenger, the flight being reserved, and the seat number assigned to the reservation.
 * It provides methods to display reservation details and modify seat assignments and flight associations.
 */
class Reservation
{
public:

    // Constructors
    Reservation();

    Reservation(int seatNumber, Flight* flight);

    Flight* getFlight() const; // Gets flight of reservation
    int getSeatNum() const; // Gets seat number

    void displayReservationDetails() const; // Display detailed information about the reservation.
    bool modifySeatNumber(int seatNum); // Modify the assigned seat number.
    bool modifyFlight(Flight* flight); // Modify the associated flight.

    int getReservationNumber() const;

private:

    int reservationNumberGenerator(); // used to generate numbers for the reservation

    int reservationNumber; // A unique reservation number.
    //Passenger passenger; // The passenger making the reservation.
    Flight* flight; // The flight being reserved.
    int seatNumber; // The assigned seat number.
};