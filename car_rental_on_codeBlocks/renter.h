#include <iostream>

using namespace std;

class Renter
{
public:
    // Constructors
    /**
    */
    Renter();

    /**
    */
    Renter(string new_name, int new_age, string new_gender, long long new_id, int new_licence_num);

    // Getters
    /**
    */
    long long get_national_id() const;

    /**
    */
    string get_name() const;

    /**
    */
    int get_age() const;

    /**
    */
    string get_gender() const;

    /**
    */
    int get_license_number() const;

    // Setters
    /**
    */
    void set_national_id(long long new_id);

    /**
    */
    void set_name(string new_name);

    /**
    */
    void set_age(int new_age);

    /**
    */
    void set_gender(string new_gender);

    /**
    */
    void set_license_number(int new_licence_num);
private:
    long long national_id;
    string name;
    int age;
    string gender;
    int license_number;
};
