class Luggage
{

private:

    int id;
    int kg;

public:

    Luggage(int id=0, int kg=0);
    void print();

    int get_id() const;
    void set_id(int new_id);
    int get_kg() const;
    void set_kg(int new_kg);
};
