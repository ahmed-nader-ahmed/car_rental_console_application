#include <iostream>
#include "renter.h"
#include <vector>
#include <fstream>

using namespace std;

string remainder;
const int FIELD_LENGTH = 20;
const int NEW_LINE_LENGTH = 2;
const int RECORD_LENGTH = FIELD_LENGTH * 6 + NEW_LINE_LENGTH; // 122

int main()
{
    vector<Renter> renter_data;
    fstream renter_file;
    renter_file.open("driversData.txt");

    // Reading Variables
    string renter_name;
    int renter_age;
    string renter_gender;
    long long renter_id;
    int renter_lic_num;

    string name_container;
    string gender_container;

    renter_file.seekg(0, ios::end);
    const int MAX_LENGTH_OF_FILE = renter_file.tellg();

    int i = RECORD_LENGTH + FIELD_LENGTH; // i initialized with RECORD_LENGTH + FIELD_LENGTH to avoid the titles of data and avoid numbers of order column
    renter_file.seekg(i, ios::beg);

    cout << "out of loop" << endl;
    char ch;

    while (i <= MAX_LENGTH_OF_FILE)
    {
        // Read Name
        renter_file >> renter_name;
        cout << "####" << renter_name << endl;
        name_container = renter_name;
        cout << "####" << name_container << endl;
        ch = renter_file.peek();
        cout << "####" << ch << endl;
        while (ch == ' ')
        {
            ch = renter_file.get();
            cout << "####" << ch << endl;
            ch = renter_file.peek();
            cout << "####" << ch << endl;
            if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
            {
                renter_file >> renter_name;
                name_container = name_container + " " + renter_name;
                cout << "####" << name_container << endl;
                ch = renter_file.peek();
                cout << "####" << ch << endl;
            }
            else break;
        }
        cout << "####" << name_container << endl;

        // Read Age
        renter_file >> renter_age;
        cout << renter_age << endl;

        // Read Gender
        renter_file >> renter_gender;
        cout << "####" << renter_gender << endl;
        gender_container = renter_gender;
        cout << "####" << renter_gender << endl;
        ch = renter_file.peek();
        cout << "####" << ch << endl;
        while (ch == ' ')
        {
            ch = renter_file.get();
            cout << "####" << ch << endl;
            ch = renter_file.peek();
            cout << "####" << ch << endl;
            if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
            {
                renter_file >> renter_gender;
                gender_container = gender_container + " " + renter_gender;
                cout << "####" << gender_container << endl;
                ch = renter_file.peek();
                cout << "####" << ch << endl;
            }
            else break;
        }
        cout << "####" << gender_container << endl;

        // Read ID
        renter_file >> renter_id;
        cout << renter_id << endl;

        // Read License Number
        renter_file >> renter_lic_num;
        cout << renter_lic_num << endl;

        // Construct Object in vector
        renter_data.push_back(Renter(name_container, renter_age, gender_container, renter_id, renter_lic_num));

        i = i + RECORD_LENGTH;
        renter_file.seekg(i, ios::beg);
    }

    renter_file.close();
    cout << "Hello world!" << endl;
    return 0;
}
