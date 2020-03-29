#include "Trip.h"
#include <iostream>

Trip::Trip(int id, long date_of_beg, int days, int km, string from, string to)
{
    this->id = id;
    this->date_of_beggining = date_of_beg;
    this->days = days;
    this->km = km;
    this->from = from;
    this->to = to;

}

void Trip::print()
{
    cout << "\n-------------------------------TRIP-------------------------------\nID: " << id << "    DATE OF BEG: " << date_of_beggining << "    DAYS: " << days << "    KM: " << km << "    FROM: " << from << "    TO: " << to << endl;
    cout << "------------------------------------------------------------------" << endl;

    for(std::vector<Sailor>::iterator it = sailorlist.begin(); it != sailorlist.end(); ++it)
    {
        it->print();
        cout << endl;
    }

    for(std::vector<Passenger>::iterator it = passengerlist.begin(); it != passengerlist.end(); ++it)
    {
        it->print();
        cout << endl;
    }
}

void Trip::add_sailor(const Sailor& sailor)
{
    bool exist = false;
    int id1 = sailor.get_id();

    if(id1 <= 0)
    {
        cout << "ID has to be POSSITIVE!" << endl;
        return;
    }

    bool captain_exist = false;

    for(std::vector<Sailor>::iterator it = sailorlist.begin(); it != sailorlist.end(); ++it)
    {
        if(it->get_state2() == sailor.get_state2())captain_exist = true;
    }

    if(captain_exist)
    {
        cout << "NO 2 CAPTAINS on ship!" << endl;
        return;
    }

    for(std::vector<Sailor>::iterator it = sailorlist.begin(); it != sailorlist.end(); ++it)
    {
        if(it->get_id() == id1)exist = true;
    }

    if( exist )
        {
            cout << "You CAN'T have 2 SAILORS with same ID!\n\n";
        }
    else
    {
        sailorlist.push_back(sailor);
    }

}

void Trip::remove_sailor(int sailor_id)
{

    for(std::vector<Sailor>::iterator it = sailorlist.begin(); it != sailorlist.end(); ++it)
    {
        if(it->get_id() == sailor_id)
        {
            sailorlist.erase(it);
            break;
        }
    }

}

void Trip::add_passenger(const Passenger& passenger)
{
    bool same = false;
    int id1 = passenger.get_id();

    if(id1 <= 0)
    {
        cout << "ID has to be POSSITIVE!" << endl;
        return;
    }

    for(std::vector<Passenger>::iterator it = passengerlist.begin(); it != passengerlist.end(); ++it)
    {
        if(it->get_id() == id1)same = true;
    }

    if( same )
        {
            cout << "You CAN'T have 2 PASSENGERS with same ID!\n\n";
        }
    else
    {
        passengerlist.push_back(passenger);
    }

}

void Trip::remove_passenger(int passenger_id)
{

  for(std::vector<Passenger>::iterator it = passengerlist.begin(); it != passengerlist.end(); ++it)
    {
        if(it->get_id() == passenger_id)
        {
            passengerlist.erase(it);
            break;
        }
    }

}

Sailor* Trip::get_sailor(int id)
{

    for(std::vector<Sailor>::iterator it = sailorlist.begin(); it != sailorlist.end(); ++it)
    {
        if(it->get_id() == id)
        {
            return &*it;
        }
   }

   return NULL;

}

Passenger* Trip::get_passenger(int id)
{

    for(std::vector<Passenger>::iterator it = passengerlist.begin(); it != passengerlist.end(); ++it)
    {
        if(it->get_id() == id)
        {
            return &*it;
        }
   }

   return NULL;

}

int Trip::ppl_on_ship()
{
    int sum=0;
    sum += sailorlist.size();
    sum += passengerlist.size();

    return sum;
}

int Trip::get_id() const
{
    return id;
}

void Trip::set_id(int new_id)
{
    id = new_id;
}

int Trip::get_days() const
{
    return days;
}

void Trip::set_days(int new_days)
{
    days = new_days;
}

int Trip::get_km() const
{
    return km;
}

void Trip::set_km(int new_km)
{
    km = new_km;
}

int Trip::get_date_of_beggining() const
{
    return date_of_beggining;
}

void Trip::set_date_of_beggining(int new_date_of_beggining)
{
    date_of_beggining = new_date_of_beggining;
}

string Trip::get_from() const
{
    return from;
}

void Trip::set_from(string new_from)
{
    from = new_from;
}

string Trip::get_to() const
{
    return to;
}

void Trip::set_to(string new_to)
{
    to = new_to;
}
