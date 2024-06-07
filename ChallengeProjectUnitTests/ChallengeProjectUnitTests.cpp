#include "pch.h"
#include "CppUnitTest.h"
#include "../ChallengeProject/MyClass.h" // TODO: Add relative paths to headers in the main project
#include "../ChallengeProject/Flight.h"
#include "../ChallengeProject/Airport.h"
#include "../ChallengeProject/National.h"
#include "../ChallengeProject/International.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChallengeProjectUnitTests
{
	TEST_CLASS(ChallengeProjectUnitTests)
	{
	public:

        TEST_METHOD(TestFlightConstructorAndGetters)
        {
            // Create an Airport instance using new, which returns a pointer
            Airport arrive = Airport("Home", "Minnesota", 30);

            // Create an Airport instance without new, directly as an object
            Airport depart = Airport("Not Home", "Menomonie", 10);

            // Create a Flight instance using the constructor
            // Flight(std::string flightNumber, Airport flightDeparture, Airport FlightArrival, int seats, std::string flightTypeTag);
            Flight flight1("100A", &depart, &arrive, 50, "National");

            // getArrival
            // Check if the getArrival method returns the correct airport reference
            // Assert::AreEqual(arrive, flight1.getArrival(), L"Arrival"); // look at lab 8
            Assert::AreEqual(arrive.getInfo().c_str(), flight1.getArrival().getInfo().c_str(), L"Arrival");

            // getFlightNumber
            // Check if the getFlightNumber method returns the correct flight number
            Assert::AreEqual("100A", flight1.getFlightNumber().c_str(), L"Flight Number");

            // Test the setFlightDeparture and setFlightArrival methods
            Assert::IsFalse(flight1.setFlightDeparture(depart), L"Set departure location");
            Assert::IsTrue(flight1.setFlightArrival(arrive), L"Set arrival location");

            // Test the removeSeat method
            //Assert::IsTrue(flight1.removeSeat(1), L"Remove seat 1");

            // Test the addSeat method
            Assert::IsTrue(flight1.addSeat(2), L"Add seat 2");
            Assert::IsFalse(flight1.addSeat(2), L"Add already occupied seat 2");
            Assert::IsFalse(flight1.addSeat(60), L"Add seat out of range (should be false)");
            Assert::IsTrue(flight1.addSeat(3), L"Add seat 3");
        }

        // AIRPORT ********************************************************************************
        TEST_METHOD(TestAddFlightAirport)
        {
            Airport test1 = Airport("TestAirport1", "TestLocation", 100);
            Airport test2 = Airport("TestAirport2", "TestLocation2", 100);

            Flight flight("123A", &test1, &test2, 50, "National");
            Flight flight2("123B", &test1, &test2, 50, "International");

            Assert::IsTrue(test1.addFlight(flight), L"Adding flight 1 true");
            Assert::IsTrue(test1.addFlight(flight2), L"Adding flight 2 true");

            Assert::AreEqual(2, test1.getPlaneCount(), L"Two flights added");

            test1.removeFlight("123A");
            Assert::AreEqual(1, test1.getPlaneCount(), L"One flight removed");
        }

        TEST_METHOD(TestMakeReservationAirport)
        {
            Airport test1 = Airport("TestAirport1", "TestLocation", 100);
            Airport test2 = Airport("TestAirport2", "TestLocation2", 100);

            Flight flight("123A", &test1, &test2, 50, "National");

            test1.addFlight(flight);

            Reservation res1 = Reservation(1, &flight);

            Assert::IsTrue(test1.makeReservation(res1));
            Assert::AreEqual(1, test1.getReservationCount());

            // Test cancelling a reservation
            Assert::IsTrue(test1.cancelReservation(1), L"Cancel reservation 1");
            Assert::IsFalse(test1.cancelReservation(2), L"Cancel non-existent reservation 2");
            Assert::AreEqual(0, test1.getReservationCount(), L"All reservations canceled");
        }

        // International ********************************************************************************

        TEST_METHOD(TestAddFlightInternational)
        {
            International test1 = International("TestAirport1", "TestLocation", 100);
            International test2 = International("TestAirport2", "TestLocation", 100);

            Flight flight("123A", &test1, &test2, 50, "international");
            Flight flight2("123B", &test1, &test2, 50, "international");

            Assert::IsTrue(test1.addFlight(flight), L"Adding flight 1 true");
            Assert::IsTrue(test1.addFlight(flight2), L"Adding flight 2 true");

            Assert::AreEqual(2, test1.getPlaneCount(), L"Two flights added");

            test1.removeFlight("123A");
            Assert::AreEqual(1, test1.getPlaneCount(), L"One flight removed");
        }

        TEST_METHOD(TestMakeReservationInternational)
        {
            International test1 = International("TestAirport1", "TestLocation", 100);
            International test2 = International("TestAirport2", "TestLocation", 100);

            Flight flight("123A", &test1, &test2, 50, "international");

            test1.addFlight(flight);

            Reservation res1 = Reservation(1, &flight);
            Reservation res2 = Reservation(2, &flight);

            Assert::IsTrue(test1.makeReservation(res1));
            Assert::AreEqual(1, test1.getReservationCount());

            Assert::IsTrue(test1.makeReservation(res2));
            Assert::AreEqual(2, test1.getReservationCount());

            // Test cancelling a reservation
            Assert::IsTrue(test1.cancelReservation(res1.getReservationNumber()), L"Cancel reservation 1");
            Assert::AreEqual(1, test1.getReservationCount());
            Assert::IsFalse(test1.cancelReservation(1), L"Cancel non-existent reservation 1");

            Assert::IsTrue(test1.cancelReservation(res2.getReservationNumber()), L"Cancel reservation 2");
            Assert::AreEqual(0, test1.getReservationCount());
            Assert::IsFalse(test1.cancelReservation(2), L"Cancel non-existent reservation 2");

            Assert::AreEqual(0, test1.getReservationCount(), L"All reservations canceled");
        }
        
        // National *******************************************************************************

        TEST_METHOD(TestAddFlightNational)
        {
            National test1 = National("TestAirport1", "TestLocation", 100);
            National test2 = National("TestAirport2", "TestLocation", 100);

            Flight flight("123A", &test1, &test2, 50, "national");
            Flight flight2("123B", &test1, &test2, 50, "national");

            Assert::IsTrue(test1.addFlight(flight), L"Adding flight 1 true");
            Assert::IsTrue(test1.addFlight(flight2), L"Adding flight 2 false");

            Assert::AreEqual(2, test1.getPlaneCount(), L"Two flight added");

            // Test adding a national flight with invalid arrival location
            Flight flightInvalid("456A", &test1, &test1, 50, "National");
            Assert::IsFalse(test1.addFlight(flightInvalid), L"Adding flight with invalid arrival location");

            // Test removing a flight
            test1.removeFlight("123A");
            Assert::AreEqual(1, test1.getPlaneCount(), L"One flight removed");
        }


        TEST_METHOD(TestMakeReservationNational)
        {
            National test3 = National("TestAirport1", "TestLocation", 100);
            Airport test4 = Airport("TestAirport2", "TestLocation", 100);

            Flight flight("123A", &test3, &test4, 3, "national");

            test3.addFlight(flight);

            Reservation res1 = Reservation(1, &flight);
            Reservation res2 = Reservation(2, &flight);
            Reservation res3 = Reservation(3, &flight);
            Reservation res4 = Reservation(4, &flight);

            Flight* flightTest = test3.findFlight(flight.getFlightNumber());

            Assert::IsTrue(test3.makeReservation(res1));
            Assert::AreEqual(1, test3.getReservationCount());
            Assert::AreEqual(1, flightTest->getSeatsFilled(), L"One seat should be filled");

            Assert::IsTrue(test3.makeReservation(res2), L"Reservation Failed");
            Assert::AreEqual(2, test3.getReservationCount(), L"One reservation");
            Assert::AreEqual(2, flightTest->getSeatsFilled(), L"Two seats should be filled");

            Assert::IsTrue(test3.makeReservation(res3));
            Assert::AreEqual(3, test3.getReservationCount());
            Assert::AreEqual(3, flightTest->getSeatsFilled(), L"Three seats should be filled");

            Assert::IsFalse (test3.makeReservation(res4), L"Reservations should be full, so no more should get added.");
            Assert::AreEqual(3, test3.getReservationCount());
            Assert::AreEqual(3, flightTest->getSeatsFilled(), L"Three seats should be filled");

            Reservation res5 = Reservation(2, &flight);
            
            Assert::IsFalse(test3.makeReservation(res4), L"Reservation at that seat already made, so no more should get added.");
            Assert::AreEqual(3, test3.getReservationCount());
            Assert::AreEqual(3, flightTest->getSeatsFilled(), L"Three seats should be filled");

            // Removing Reservations

            Assert::IsTrue(test3.cancelReservation(res1.getReservationNumber()), L"Should have been succesfully removed");
            Assert::AreEqual(2, test3.getReservationCount(), L"Should be two reservations");
            Assert::AreEqual(2, flightTest->getSeatsFilled(), L"Should be two seats filled");

            Assert::IsFalse(test3.cancelReservation(res4.getReservationNumber()), L"Should have not removed anything");
            Assert::AreEqual(2, test3.getReservationCount(), L"Should be two reservations");
            Assert::AreEqual(2, flightTest->getSeatsFilled(), L"Should be two seats filled");

            Assert::IsTrue(test3.cancelReservation(res2.getReservationNumber()), L"Should have been succesfully removed");
            Assert::AreEqual(1, test3.getReservationCount(), L"Should be one reservations");
            Assert::AreEqual(1, flightTest->getSeatsFilled(), L"Should be one seats filled");

            Assert::IsTrue(test3.cancelReservation(res3.getReservationNumber()), L"Should have been succesfully removed");
            Assert::AreEqual(0, test3.getReservationCount(), L"Should be zero reservations");
            Assert::AreEqual(0, flightTest->getSeatsFilled(), L"Should be zero seats filled");

            Assert::IsFalse(test3.cancelReservation(res4.getReservationNumber()), L"Should have not removed anything");
            Assert::AreEqual(0, test3.getReservationCount(), L"Should be zero reservations");
            Assert::AreEqual(0, flightTest->getSeatsFilled(), L"Should be zero seats filled");
        }

        TEST_METHOD(TestFlightCreation)
        {
            National national = National("National", "USA", 2);
            International international = International("International", "USA", 2);
            International international2 = International("International", "USB", 2);

            // National flights are only allowed to fly to airports within the same country.
            // International flighst are only allowed to fly to airports that are international.

            Flight nationalFlight = Flight("123A", &national, &international, 20, "national");
            Flight internationalFlight = Flight("123B", &international, &national, 30, "international");

            // Test creating a national flight with invalid arrival location
            Flight nationalFlightInvalid("789A", &national, &international2, 20, "national");
            Assert::IsFalse(national.addFlight(nationalFlightInvalid), L"Adding national flight with invalid arrival location");

            // Test creating an international flight with invalid arrival location
            Flight internationalFlightInvalid("789B", &international, &national, 30, "international");
            Assert::IsFalse(international.addFlight(internationalFlightInvalid), L"Adding international flight with invalid arrival location");
        }
	};
}
