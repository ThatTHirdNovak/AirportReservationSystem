#include <iostream>
#include "../ChallengeProject/Airport.h" // TODO: Add relative paths to headers in the main project
#include "../ChallengeProject/World.h" 
#include "../ChallengeProject/International.h" 
#include "../ChallengeProject/National.h" 
#include "../ChallengeProject/Reservation.h" 
using namespace std;

// Forward declarations
void addReservation(World& world);
void modifyReservation(World& world);
void removeReservation(World& world);
void displayFlightsForAirport(World& world);
void displayAirports(World& world);
void displaySpecificFlight(World& world);
void displayReservationDetails(World& world);

void displayMenu() {
    std::cout << "-------------------------\n";
    std::cout << "1. Add Reservation\n";
    std::cout << "2. Modify Reservation\n";
    std::cout << "3. Remove Reservation\n";
    std::cout << "4. Display Flights for an Airport\n";
    std::cout << "5. Display Airports\n";
    std::cout << "6. Display Specific Flight for an Airport\n";
    std::cout << "7. Display Reservation Details\n";
    std::cout << "8. Exit\n";
    std::cout << "-------------------------\n";
}

int getUserChoice() {
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

std::string getAirportNameFromUser() {
    std::string airportName;
    std::cout << "Enter the airport name: ";
    std::cin >> airportName;
    return airportName;
}

std::string getFlightIDFromUser() {
    std::string flightID;
    std::cout << "Enter the flight ID: ";
    std::cin >> flightID;
    return flightID;
}

int getSeatNumberFromUser() {
    int seat;
    std::cout << "Enter the desired seat number: ";
    std::cin >> seat;
    return seat;
}

int getReservationNumberFromUser() {
    int resNum;
    std::cout << "Enter Reservation Number: ";
    std::cin >> resNum;
    return resNum;
}

// Adds reservation to the airport
void addReservation(World& world) 
{
    std::string airportCase1 = getAirportNameFromUser();
    Airport* selectedAirport1 = world.getAirport(airportCase1);

    // Checks if airport is found
    if (selectedAirport1 == nullptr) {
        std::cout << "Airport not found.\n";
        return;
    }

    std::string flightID = getFlightIDFromUser();
    Flight* selectedFlight1 = selectedAirport1->findFlight(flightID);

    // Checks if that flight exists
    if (selectedFlight1 == nullptr) {
        std::cout << "Flight not found.\n";
        return;
    }

    int seat = getSeatNumberFromUser();

    // Checks to see if they inputted an int
    if (std::cin.fail() || std::cin.peek() != '\n') {
        std::cout << "Invalid input.\n";
        return;
    }

    // Checks to see if the reservation was made properly. If it fails make Reservation will return false. SO we want to ensure that the reservation is properly disposed of and doesn't affect our code. 
    Reservation reservation(seat, selectedFlight1);
    selectedAirport1->makeReservation(reservation);
}

void modifyReservation(World& world) 
{
    std::string airportCase2 = getAirportNameFromUser();
    Airport* selectedAirport1 = world.getAirport(airportCase2);

    if (selectedAirport1 == nullptr) {
        std::cout << "Airport not found.\n";
        return;
    }

    int resNum = getReservationNumberFromUser();
    selectedAirport1->modifyReservation(resNum);
}

void removeReservation(World& world) 
{
    std::string airportCase3 = getAirportNameFromUser();
    Airport* selectedAirport1 = world.getAirport(airportCase3);

    if (selectedAirport1 == nullptr) {
        std::cout << "Airport not found.\n";
        return;
    }

    int resNum = getReservationNumberFromUser();
    selectedAirport1->cancelReservation(resNum);
}

void displayFlightsForAirport(World& world) 
{
    std::string airportName = getAirportNameFromUser();
    Airport* selectedAirport2 = world.getAirport(airportName);

    if (selectedAirport2 != nullptr) {
        selectedAirport2->displayAvailableFlights();
    }
    else {
        std::cout << "Airport not found.\n";
    }
}

void displayAirports(World& world) 
{
    world.displayAirports();
}

void displaySpecificFlight(World& world) 
{
    std::string flightID = getFlightIDFromUser();
    Flight* flight = world.findFlightID(flightID);

    if (flight != nullptr) {
        flight->displayFlightDetails();
    }
    else {
        std::cout << "Flight not found.\n";
    }
}

void displayReservationDetails(World& world) 
{
    std::string airportCase7 = getAirportNameFromUser();
    Airport* selectedAirport1 = world.getAirport(airportCase7);

    if (selectedAirport1 == nullptr) {
        std::cout << "Airport not found.\n";
        return;
    }

    int resNum = getReservationNumberFromUser();
    Reservation* reservation = selectedAirport1->findReservation(resNum);

    if (reservation == nullptr) {
        std::cout << "Reservation not found.\n";
        return;
    }

    reservation->displayReservationDetails();
}

int main() {
    // Create a world with some airports and flights
    World world;

    // Displaying Airports
    std::cout << "\n\n\n" << endl;
    world.displayAirports();

    int choice;
    do {
        displayMenu();
        choice = getUserChoice();

        if (!std::cin.fail() && std::cin.peek() == '\n') {
            switch (choice) {
            case 1: addReservation(world); break;
            case 2: modifyReservation(world); break;
            case 3: removeReservation(world); break;
            case 4: displayFlightsForAirport(world); break;
            case 5: displayAirports(world); break;
            case 6: displaySpecificFlight(world); break;
            case 7: displayReservationDetails(world); break;
            case 8: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice. Please try again.\n";
            }
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter an integer please.\n";
        }
    } while (choice != 8);

    return 0;
}