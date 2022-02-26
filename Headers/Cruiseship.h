#include <vector>
#include "Trip.h"

class CruiseShip
{

private:

    std::vector <Trip> triplist;
    int lifting_capacity; //too many luggage
    int max_amount_ppl; //too many sailors + passengers and ship will sink
    //int new_trip_id = 0;
    int nr_of_trips;

public:

    ~CruiseShip();
    void add_trip(const Trip& trip);
    void remove_trip(int trip_id);
    void print();
    Trip* get_trip(int id);
    void early_adding();
    void start();
    void adding_trip();
    void ship_too_heavy(int id);
    void something_random(int id);

};
