#pragma once
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date() // Default constructor
    {
        day = 0;
        month = 0;
        year = 0;
    }
    Date(int day, int month, int year) // Full Date Constructor
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    // Setters
    void setDay(int day)
    {
        this->day = day;
    }
    void setMonth(int month)
    {
        this->month = month;
    }
    void setYear(int year)
    {
        this->year = year;
    }
    // Getters
    int getDay()
    {
        return this->day;
    }
    int getMonth()
    {
        return this->month;
    }
    int getYear()
    {
        return this->year;
    }
};
struct Time {
    int min, hour;
};