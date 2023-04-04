#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)
        return true;
    return false;
}

//date1>date2·µ»Ø1 , date1<date2·µ»Ø-1 , date1==date2·µ»Ø0
int JudgeDate(int date1,int date2) {
    int year1 = date1 / 10000, month1 = date1 / 100 % 100, day1 = date1 % 100;
    int year2 = date2 / 10000, month2 = date2 / 100 % 100, day2 = date2 % 100;
    if (year1 > year2) {
        return 1;
    } else if (year1 == year2) {
        if (month1 > month2) {
            return 1;
        } else if (month1 < month2) {
            return -1;
        } else {
            if (day1 > day2) {
                return 1;
            } else if (day1 < day2) {
                return -1;
            } else {
                return 0;
            }
        }
    } else {
        return -1;
    }
}

int SubDay(int date1,int date2) {
    int arr[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

    int year1 = date1 / 10000, month1 = date1 / 100 % 100, day1 = date1 % 100;
    int year2 = date2 / 10000, month2 = date2 / 100 % 100, day2 = date2 % 100;

    int days = 0;

    int ret = JudgeDate(date1, date2);

    if (ret == 1) {
        if(isLeapYear(year2)){
            arr[2]+=1;
        }
        while ((year1 != year2) || (month1 != month2) || (day1 != day2)) {
            ++day2;
            ++days;
            if (day2 > arr[month2]) {
                ++month2;
                day2=1;
                if(month2>12){
                    ++year2;
                    month2=1;
                }
            }
        }
    } else if (ret == -1) {
        if(isLeapYear(year1)){
            arr[2]+=1;
        }
        while ((year1 != year2) || (month1 != month2) || (day1 != day2)) {
            ++day1;
            ++days;
            if (day1 > arr[month1]) {
                ++month1;
                day1=1;
                if(month1>12){
                    ++year1;
                    month1=1;
                }
            }
        }
    } else {
        days = 0;
    }
    return days + 1;
}

int main(){
    int date1,date2;
    cin>>date1>>date2;

    int ret=SubDay(date1,date2);
    cout<<ret<<endl;


    return 0;
}