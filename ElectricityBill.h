#ifndef ELECTRICITYBILL_H
#define ELECTRICITYBILL_H
#include <iostream>
using namespace std;
class ElectricityBill {
private:
    int units;
    double rate;
    double totalBill;

public:
    //  Constructors Function Overloading 
    ElectricityBill() {
        units = 0;
        rate = 0;
        totalBill = 0;
    }
    ElectricityBill(int u) {
        units = u;
        rate = 5.0;
        calculateBill();
    }
    ElectricityBill(int u, double r) {
        units = u;
        rate = r;
        calculateBill();
    }
    ElectricityBill(const ElectricityBill& obj) {
        units = obj.units;
        rate = obj.rate;
        totalBill = obj.totalBill;
    }
    void calculateBill() {
        if (units <= 100) {
            totalBill = units * rate;
        }
        else if (units <= 200) {
            totalBill = (100 * rate) + (units - 100) * (rate + 2);
        }
        else {
            totalBill = (100 * rate) + (100 * (rate + 2)) + (units - 200) * (rate + 5);
        }
    }
    // (Function Overloading)
    void setData(int u) {
        units = u;
        rate = 5.0;
        calculateBill();
    }
    void setData(int u, double r) {
        units = u;
        rate = r;
        calculateBill();
    }
    void setData(const ElectricityBill& obj) {
        units = obj.units;
        rate = obj.rate;
        totalBill = obj.totalBill;
    }
    int getUnits() const { return units; }
    double getRate() const { return rate; }
    double getTotalBill() const { return totalBill; }
    // Operator Overloading
    ElectricityBill operator+(const ElectricityBill& obj) {
        ElectricityBill temp;
        temp.units = this->units + obj.units;
        temp.rate = this->rate;
        temp.calculateBill();
        return temp;
    }
    ElectricityBill operator-(const ElectricityBill& obj) {
        ElectricityBill temp;
        temp.units = this->units - obj.units;
        if (temp.units < 0) temp.units = 0;
        temp.rate = this->rate;
        temp.calculateBill();
        return temp;
    }
    ElectricityBill operator*(int months) {
        ElectricityBill temp;
        temp.units = this->units * months;
        temp.rate = this->rate;
        temp.calculateBill();
        return temp;
    }
    // to  compare the total bills
    bool operator<(const ElectricityBill& obj) const {
        return this->totalBill < obj.totalBill;
    }
    //  to check if bills are equal 
    bool operator==(const ElectricityBill& obj) const {
        return this->totalBill == obj.totalBill;
    }
    // output display (friend function)
    friend ostream& operator<<(ostream& out, const ElectricityBill& obj) {
        out << "Units : " << obj.units << endl;
        out << "Rate  : " << obj.rate << " PKR/unit" << endl;
        out << "Total: " << obj.totalBill << " PKR" << endl;
        return out;
    }
};
#endif