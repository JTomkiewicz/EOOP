#include <string>
using namespace std;

enum position
{
    HOTEL,
    ENGINE,
    BRIDGE
};

enum degree
{
    CAPTAIN,
    OLD_SAILOR,
    YOUNG_SAILOR
};

class Sailor
{

private:

    int id;
    string name;
    string surname;
    position state;
    degree state2;

public:

    Sailor(int id=0, string name="", string surname="", position state=HOTEL, degree state2=YOUNG_SAILOR);
    void print();
    string getPositionName(enum position state);
    string getDegreeName(enum degree state);

    int get_id() const;
    void set_id(int new_id);
    string get_name() const;
    void set_name(string new_name);
    string get_surname() const;
    void set_surname(int new_surname);
    position get_state() const;
    void set_state(position new_state);
    degree get_state2() const;
    void set_state2(degree new_state2);

};
