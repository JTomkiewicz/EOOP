#include "Luggage.h"
#include <iostream>
using namespace std;

Luggage::Luggage(int id, int kg)
{
    this->id = id;
    this->kg = kg;
}

void Luggage::print()
{
    cout << "      #LUGGAGE# ID: " << id << "    KG: " << kg << endl;
}

int Luggage::get_id() const
{
    return id;
}

void Luggage::set_id(int new_id)
{
    id = new_id;
}

int Luggage::get_kg() const
{
    return kg;
}

void Luggage::set_kg(int new_kg)
{
    kg = new_kg;
}
