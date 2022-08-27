#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

const int FIELD_LENGTH = 20;
const int NEW_LINE_LENGTH = 20;
string remainder;
// getline(cin, remainder)

string capitalize_fisrt_letter(string& s)
{
    if (s[0] >= 'A' && s[0] <= 'Z') return s;
    if (s[0] >= 'a' && s[0] <= 'z')
    {
        s[0] = s[0] - 32;
        return s;
    }
}

string digits_to_string(const long long& digits)
{
    ostringstream outstr;
    outstr << digits;
    return outstr.str();
}

string integers_to_string(const int& digits)
{
    ostringstream outstr;
    outstr << digits;
    return outstr.str();
}

string upper_to_lower_case(string& s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
    }
    return s;
}

bool is_part_of_my_string(const string& my_str, const string& other_str)
{
    if (other_str[0] != my_str[0])
    {
        return false;
    }
    return true;
}

int main()
{
    fstream fs;
    fs.open("driversData.txt"); // always create files in this path
    string name;
    int age;
    string gender;
    long long id;
    int licence_num;

    if (fs.fail()) return -1;

    // WRITING TITLES in file
    fs << left;
    fs << setw(FIELD_LENGTH) << "ORDER"
        << setw(FIELD_LENGTH) << "NAME"
        << setw(FIELD_LENGTH) << "AGE"
        << setw(FIELD_LENGTH) << "GENDER"
        << setw(FIELD_LENGTH) << "ID"
        << setw(FIELD_LENGTH) << "LICENSE NUMBER" << "\n";

    int i = 1;
    int more = 1;
    while (more)
    {
        // READING from console
        cout << "Please enter the (DATA) of customers (" << i << ") that rented cars before : \n";
        int flag;
        while (true)
        {
            flag = 1;
            cout << "Name (contain [ONLY] a->z, A->Z CHARACTERS): ";
            getline(cin, name);
            for (int j = 0; j < name.length(); j++)
            {
                if (!(name[j] >= 'A' && name[j] <= 'Z') && !(name[j] >= 'a' && name[j] <= 'z') && (name[j] != ' '))
                {
                    cout << "ERROR please re-enter => ";
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) break;
        }

        while (true)
        {
            cout << "Age (must be equal OR more than [18] YEARS) : ";
            cin >> age; // at most 3 digits and less than 100
            if (age <= 100 && age >= 18 && !cin.fail()) break;
            cout << "ERROR please re-enter => ";
        }

        getline(cin, remainder);

        string male = "male";
        string female = "female";
        while (true)
        {
            cout << "Gender : ";
            getline(cin, gender); // Must start with m or M or f or F
            if (is_part_of_my_string(male, upper_to_lower_case(gender)))
            {
                gender = male; cout << "We consider that you meant to enter: " << male << endl;
                break;
            }
            else if (is_part_of_my_string(female, upper_to_lower_case(gender)))
            {
                gender = female; cout << "We consider that you meant to enter: " << female << endl;
                break;
            }
            cout << "ERROR please re-enter => ";
        }



        while (true)
        {
            cout << "ID (must be [14] DIGITS) : "; // must be 14 digits
            cin >> id;
            if (digits_to_string(id).length() == (14) && !cin.fail()) break;
            cout << "ERROR please re-enter => ";
        }

        while (true)
        {
            cout << "License Number : "; // at most 3 digits
            cin >> licence_num;
            if (integers_to_string(licence_num).length() <= 3 && integers_to_string(licence_num).length() > 0 && !cin.fail()) break;
            cout << "ERROR please re-enter => ";
        }

        // WRITING DATA to a file
        fs << setw(FIELD_LENGTH) << i
            << setw(FIELD_LENGTH) << capitalize_fisrt_letter(name)
            << setw(FIELD_LENGTH) << age
            << setw(FIELD_LENGTH) << capitalize_fisrt_letter(gender)
            << setw(FIELD_LENGTH) << id
            << setw(FIELD_LENGTH) << licence_num << "\n";

        cout << "to stop writing data press any non number OR press zero: ";
        cin >> more;
        i++;
        getline(cin, remainder);
    }

    fs.close();

    return 0;
}
