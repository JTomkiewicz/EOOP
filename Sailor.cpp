#include "Sailor.h"
#include <iostream>
#include <string>
using namespace std;

Sailor::Sailor(int id, string name, string surname, position state, degree state2)
{
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->state = state;
    this->state2 = state2;
}

void Sailor::print()
{
    cout << "   #SAILOR# ID: " << id << "    NAME: " << name << "    SURNAME: " << surname << "    POSITION: " << getPositionName(state) << "    DEGREE: " << getDegreeName(state2);
}

string Sailor::getPositionName(enum position state)
{
   if(state == HOTEL)return "Hotel";
   if(state == ENGINE)return "Engine";
   if(state == BRIDGE)return "Bridge";

   return "";
}

string Sailor::getDegreeName(enum degree state)
{
    if(state == CAPTAIN)return "Captain";
    if(state == OLD_SAILOR)return "Old sailor";
    if(state == YOUNG_SAILOR)return "Young sailor";

    return "";
}

int Sailor::get_id() const
{
    return id;
}

void Sailor::set_id(int new_id)
{
    id = new_id;
}

string Sailor::get_name() const
{
    return name;
}

void Sailor::set_name(string new_name)
{
    name = new_name;
}

string Sailor::get_surname() const
{
    return surname;
}

void Sailor::set_surname(int new_surname)
{
    surname = new_surname;
}

position Sailor::get_state() const
{
    return state;
}

void Sailor::set_state(position new_state)
{
    state = new_state;
}

degree Sailor::get_state2() const
{
    return state2;
}

void Sailor::set_state2(degree new_state2)
{
    state2 = new_state2;
}
