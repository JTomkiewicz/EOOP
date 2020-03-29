#include <iostream>
#include "Cruiseship.h"

using namespace std;

int main()
{
    CruiseShip ship1;

    ship1.start();
    ship1.early_adding();

    return 0;
}


/*

Cruiseship.early_adding() is the function to modify by user !!!

Rules:
NO 2 SAILORS/TRIPS/PASSENGERS WITH THE SAME ID
ALL DATES AFTER 20000101 //1st January 2000
ERRORS ARE SHOWN AT THE TOP OF CONSOLE
LUGGAGE KG HAS TO BE >0
NO 2 CAPTAINS ON SHIP
ALL ID's HAS TO BE POSITIVE NR BIGGER THAN 0
IF YOU ADD TOO MANY PPL (SAILORS + PASSENGERS) SHIP MIGHT SINK
PLAYER HAS TO LISTEN TO MESSAGES ON THE SCREEN (WARNINGS AND RANDOM ACTIONS)

*/
