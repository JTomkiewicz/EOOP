#include "Cruiseship.h"
#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <ctime>

CruiseShip::~CruiseShip()
{
    triplist.clear();
}

void CruiseShip::add_trip(const Trip& trip)
{
    bool same = false;

    int id1 = trip.get_id();

    if(id1 <=0 )
    {
    cout << "ID has to be POSSITIVE!" << endl;
    return;
    }

    for(std::vector<Trip>::iterator it = triplist.begin(); it != triplist.end(); ++it)
        {
            if(it->get_id() == id1)same = true;
        }

    if(trip.get_date_of_beggining() < 20000101)
    {
        cout << "All dates AFTER 1st Jan 2000!\n";
        return;
    }

    if( same )
    {
        cout << "You CAN'T have 2 TRIPS with same ID!\n\n";
    }
    else
    {
        triplist.push_back(trip);
        //triplist.back().set_id(++new_trip_id);
    }

}

void CruiseShip::remove_trip(int trip_id)
{

    for(std::vector<Trip>::iterator it = triplist.begin(); it != triplist.end(); ++it)
    {
        if(it->get_id() == trip_id)
        {
            triplist.erase(it);
            break;
        }
    }

}

void CruiseShip::print()
{
    cout << "-----------------------------SHIPINFO-----------------------------" << endl;
    cout << "MAX LIFT: " << lifting_capacity << "    MAX PPL: " << max_amount_ppl << endl << endl;

    for(std::vector<Trip>::iterator it = triplist.begin(); it != triplist.end(); ++it)
    {
        it->print();
    }

}

Trip* CruiseShip::get_trip(int id)
{

    for(std::vector<Trip>::iterator it = triplist.begin(); it != triplist.end(); ++it)
    {
        if(it->get_id() == id)
        {
            return &*it;
        }
   }

   return NULL;

}

void CruiseShip::start()
{
    int option;
    bool ok;

    cout << "#### CRUISESHIP BY JAKUB TOMKIEWICZ ####\n\n";

    do
    {
        ok = false;
        do
        {
            cout << "You are chosen to work in ship management of your dream cruiseship!\nDo you take up the challange?\n[1] Yes, bring it on!\n[0] No, I want to leave" << endl;
            cin >> option;

            if (cin.good() == true)
                    if (option > -1 && option < 2) ok = true;

                    else
                    {
                        system("clear");
                        cout << "Wrong number, try again!" << endl;
                        cin.clear();
                    }
            else
            {
                system("clear");
                cout << "Not a number, try again!" << endl;
                cin.clear();
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if(option == 0)
            {
                system("clear");
                cout << "Thank you for using my program\nWritten By Jakub Tomkiewicz" << endl;
                exit(0);
            }

        }
        while(ok != true);
    }
    while(option != 1);
    system("clear");

}

void CruiseShip::ship_too_heavy(int id)
{
    int ppl = get_trip(id)->ppl_on_ship();

    if(ppl > max_amount_ppl)
    {
        cout << "\n!!! CRITICAL WARNING: SHIP TOO HEAVY DURING TRIP " << id << "!!!\n\n";
    }
}

void CruiseShip::something_random(int id)
{
    srand(time(0));

    int a = 1+rand()%3;

    if(a == 1)
    {
        cout << "\nShip is being attacted by pirates!!!\nYou have to throw some of the luggage out of the ship!\n\n\n";
    }

    if(a == 2)
    {
        cout << "\nYour captain died!!!\nYou have to make the best sailor the new captain!\n\n\n";
    }

    if(a == 3)
    {
        cout << "Nothing happened during your trip\n\n\n";
    }

}

void CruiseShip::early_adding()
{
    lifting_capacity = 20;   //ship variables
    max_amount_ppl = 6;

    Trip trip1(1, 20030330, 13, 110, "New York", "London");
    add_trip(trip1);

    Sailor s1(1,"Robert", "Pattinson", BRIDGE, CAPTAIN);
    Sailor s2(2,"Michael", "Jordan", ENGINE, YOUNG_SAILOR);
    Sailor s3(3,"Johny", "Bravo", ENGINE, OLD_SAILOR);
    get_trip(1)->add_sailor(s1);       //adding
    get_trip(1)->add_sailor(s2);
    get_trip(1)->add_sailor(s3);

    Passenger pass1(1, "Miley", "Cyrus");
    Passenger pass2(2, "Margot", "Robbie");
    get_trip(1)->add_passenger(pass1);   //adding
    get_trip(1)->add_passenger(pass2);

    Luggage lug1(1, 10);
    Luggage lug2(2, 20);
    Luggage lug3(1, 50);
    get_trip(1)->get_passenger(1)->add_luggage(lug1);  //adding
    get_trip(1)->get_passenger(1)->add_luggage(lug2);
    get_trip(1)->get_passenger(2)->add_luggage(lug3);


    Trip trip2(2, 20120312, 7, 330, "Washington", "Hong Kong");
    add_trip(trip2);



    Trip trip3(3, 20151211, 40, 1100, "Gdansk", "Helsinki");
    add_trip(trip3);


    print();

    ship_too_heavy(1); //too many ppl on ship during trip, warning will be shown

    get_trip(1)->get_passenger(1)->remove_luggage(1);    //removing
    get_trip(1)->get_passenger(1)->set_name("Jackob");     //setting

    something_random(1);

    print();

     //some random actions during trip, user has to listen to them


}

