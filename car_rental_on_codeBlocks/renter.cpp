#include <iostream>
#include "renter.h"

using namespace std;

// Constructors
Renter::Renter()
{
    national_id = 0;
    age = 0;
    license_number = 0;
}

Renter::Renter(string new_name, int new_age, string new_gender, long long new_id, int new_licence_num)
{
    name = new_name;
    age = new_age;
    gender = new_gender;
    national_id = new_id;
    license_number = new_licence_num;
}

// Getters
long long Renter::get_national_id() const
{
    return national_id;
}

string Renter::get_name() const
{
    return name;
}

int Renter::get_age() const
{
    return age;
}

string Renter::get_gender() const
{
    return gender;
}

int Renter::get_license_number() const
{
    return license_number;
}

// Setters
void Renter::set_national_id(long long new_id)
{
    national_id = new_id;
}

void Renter::set_name(string new_name)
{
    name = new_name;
}

void Renter::set_age(int new_age)
{
    age = new_age;
}

void Renter::set_gender(string new_gender)
{
    gender = new_gender;
}

void Renter::set_license_number(int new_licence_num)
{
    license_number = new_licence_num;
}
