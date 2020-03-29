#include <vector>
#include <string>
#include <time.h>
#include "Sailor.h"
#include "Passenger.h"

class Trip
{

private:

    std::vector <Sailor> sailorlist;
    std::vector <Passenger> passengerlist;
    int id;
    long date_of_beggining;
    int days;
    int km;
    string from;
    string to;

public:

    Trip(int id=0, long date_of_beg=20000101, int days=1, int km=1, string from="", string to="");
    //we do not need ~Trip
    void print();
    void add_sailor(const Sailor& sailor);
    void remove_sailor(int sailor_id);
    void add_passenger(const Passenger& Passenger);
    void remove_passenger(int passenger_id);
    Sailor* get_sailor(int id);
    Passenger* get_passenger(int id);
    int ppl_on_ship();

    int get_id() const;
    void set_id(int new_id);
    int get_days() const;
    void set_days(int new_days);
    int get_km() const;
    void set_km(int new_km);
    int get_date_of_beggining() const;
    void set_date_of_beggining(int new_date_of_beggining);
    string get_from() const;
    void set_from(string new_from);
    string get_to() const;
    void set_to(string new_to);

};
