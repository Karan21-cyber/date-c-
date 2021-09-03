#include <iostream>
#include <string>
using namespace std;

string monthNames[12]= {"January", "February", "March", "April", "May", "June", "July", "August", "September", "Octuber", "November", "December"};

class Date
{
int day, month, year;
public:
    void setDate(int month,int day,int year);
    void getDate();
    void format1();
    void format2();
    void format3();
    void operator ++();
    void operator ++(int);
    void operator --();
    void operator --(int);
    friend int operator-(const Date d1, const Date d2);
};

void Date::setDate(int month,int day,int year){
    this-> month = month;
    this-> day = day;
    this-> year = year;
}
void Date::getDate(){
    do {cout << "Enter month between (1-12):";
    cin>>month;
    }
    while(month < 1 || month > 12);

     do {cout << "Enter day between(1-31):";
    cin >> day;
    }
    while(day < 1 || day > 31);

    do {cout << "Enter year:";
    cin >> year;
    }
    while(year < 1);

    setDate(month,day,year);
}

void Date::format1()
{
    cout << month << "/" << day << "/" << year << endl;
}
void Date::format2()
{
    cout << monthNames[month -1] << " " << day << "," << year << endl;
};
void Date::format3()
{
    cout << day << " " << monthNames[month-1] << " " << year << endl;
};

void  Date::operator++()
{
    if (day == 31){
        month = month + 1;
        day = 1;
        if (month > 12){
            year = year + 1;
            month = 1;
        }
    }
    else {
        day++;
    }
}

void Date::operator++(int)
{
    if (day == 31){
        month = month + 1;
        day = 1;
        if (month > 12){
            year = year + 1;
            month = 1;
        }
    }
    else{
        ++day;
    }

}

void Date::operator--()
{
    if(day == 1){
        if(month == 1){
            year = year - 1;
            month = 12;
        }
        else{
            month = month -1;
        }
        day = 31;
    }
    else{
        day--;
    }
}

void Date::operator--(int)
{
    if(day == 1){
        if(month == 1){
            year = year - 1;
            month = 12;
        }
        else{
            month = month -1;
        }
        day = 31;
    }
    else{
        --day;
    }
}

int operator-(Date d1, Date d2)
{
    int date_yy, date_mm, date_dd;
    date_yy = (d1.year - d2.year)*365;
    date_mm = ((d1.month - d2.month)*31*0.981);
    date_dd = d1.day - d2.day;
    date_dd = date_yy + date_mm + date_dd;
    if (date_dd < 0){
        date_dd = -date_dd;
    }
     return date_dd; 
}

int main()
{
    Date d1;
    cout << "Condition 1:"<< endl;
    cout << "Getting the information of Date 1 "<< endl;
    d1.getDate();
    cout << endl;
    cout << "----Display the Date 1 in 3 format----" << endl;
    cout << "----Format 1---" << endl;
    d1.format1();
    cout << "----Format 2---" << endl;
    d1.format2();
    cout << "----Format 3---" << endl;
    d1.format3();
    cout<<endl;

    cout << "Condition 2"<< endl;
    cout << "\nAfter Increment" << endl;
    cout << "Prefix increment"<< endl;
    ++d1;
    d1.format3();
    cout << "Postfix increment"<< endl;
    d1++;
    d1.format3();
    cout << endl;

    Date d2;
    cout << "Getting the information of Date 2 "<< endl;
    d2.getDate();
    cout << endl;
    cout << "----Display the Date 1 in 3 format----" << endl;
    cout << "----Format 1---" << endl;
    d2.format1();
    cout << "----Format 2---" << endl;
    d2.format2();
    cout << "----Format 3---" << endl;
    d2.format3();
    cout<<endl;

    cout << "\nAfter Decrement" << endl;
    cout << "Prefix Decrement"<< endl;
    --d2;
    d2.format3();
    cout << "Postfix Decrement"<< endl;
    d2--;
    d2.format3();
    cout << endl;

    cout << "Difference between two dates" << endl;
    cout << "Date1 : ";
    d1.format3();
    cout << "Date 2: ";
    d2.format3();
    cout << endl;
    cout << "Duration between two date is : "<< d1-d2 <<" days\n" << endl ;

    return 0;
}
