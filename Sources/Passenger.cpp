#include "Passenger.h"
#include <iostream>

Passenger::Passenger(int id, string name, string surname)
{
    this->id = id;
    this->name = name;
    this->surname = surname;

}

void Passenger::add_luggage(const Luggage& luggage)
{
    bool same = false;
    int id1 = luggage.get_id();
    int kg1 = luggage.get_kg();

    if (kg1 <= 0)
    {
        cout << "You CAN'T add luggage which is lighter than 0kg!" << endl;
        return;
    }

    if(id1 <= 0)
    {
        cout << "ID has to be POSSITIVE!" << endl;
        return;
    }

    for(std::vector<Luggage>::iterator it = luggagelist.begin(); it != luggagelist.end(); ++it)
    {
        if(it->get_id() == id1)same = true;
    }

    if( same )
        {
            cout << "You CAN'T have 2 LUGGAGE with same ID!\n\n";
        }
    else
    {
        luggagelist.push_back(luggage);
    }

}

void Passenger::remove_luggage(int luggage_id)
{

    for(std::vector<Luggage>::iterator it = luggagelist.begin(); it != luggagelist.end(); ++it)
    {
        if(it->get_id() == luggage_id)
        {
            luggagelist.erase(it);
            break;
        }
    }

}

void Passenger::print()
{

    cout << "   #PASSENGER# ID: " << id << "    NAME: " << name << "    SURNAME: " << surname <<endl;

    for(std::vector<Luggage>::iterator it = luggagelist.begin(); it != luggagelist.end(); ++it)
    {
        it->print();
        //cout << endl;
    }

}

Luggage* Passenger::get_luggage(int id)
{

    for(std::vector<Luggage>::iterator it = luggagelist.begin(); it != luggagelist.end(); ++it)
    {
        if(it->get_id() == id)
        {
            return &*it;
        }
   }

   return NULL;

}

int Passenger::get_id() const
{
    return id;
}

void Passenger::set_id(int new_id)
{
    id = new_id;
}

string Passenger::get_name() const
{
    return name;
}

void Passenger::set_name(string new_name)
{
    name = new_name;
}

string Passenger::get_surname() const
{
    return surname;
}

void Passenger::set_surname(int new_surname)
{
    surname = new_surname;
}
