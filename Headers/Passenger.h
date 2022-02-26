#include <vector>
#include <string>
#include "Luggage.h"
using namespace std;

class Passenger
{

private:

    std::vector <Luggage> luggagelist;
    int id;
    string name;
    string surname;

public:

    Passenger(int id=0, string name="", string surname="");
    void add_luggage(const Luggage& luggage);
    void remove_luggage(int luggage_id);
    void print();
    Luggage* get_luggage(int id);

    int get_id() const;
    void set_id(int new_id);
    string get_name() const;
    void set_name(string new_name);
    string get_surname() const;
    void set_surname(int new_surname);

};
