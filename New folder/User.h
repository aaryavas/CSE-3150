
#ifndef USER_H
#define USER_H

#include <string>
#include <memory>
#include <vector>
#include "MediaCatalog.h"
#include "Payment.h"

class RentalCart;

class User {
public:
    User(std::string id, std::string name, int loyaltyPoints, PaymentMethod* paymentMethod);
    virtual ~User() = default;
    virtual double calculateRentalDiscount();
    RentalCart* getRentalCart();
    virtual int getLoyaltyPoints() const;
    virtual double useLoyaltyPoints();
    virtual void updateLoyaltyPoints(double total);
    virtual double getDiscount() const; 
    virtual PaymentMethod* getPaymentMethod() { return paymentMethod; }
    
private:
    std::string userID;
    std::string name;
    int loyaltyPoints;
    std::unique_ptr<RentalCart> cart;
    double discount = 0.0;
    PaymentMethod* paymentMethod;
};



//these need to be fixed use delegation learn later

using namespace std;
class StudentUser : public User {
public:
    // TODO: add methods 
    StudentUser(std::string id, std::string name, int loyaltyPoints, PaymentMethod* paymentMethod);
    //override calculateRentalDiscount
    double calculateRentalDiscount() override;
private:
    // TODO: add private members

    //inherits private members but cannot modify them

};

class FacultyUser : public User {
public:
    // TODO: add methods
    FacultyUser(std::string id, std::string name, int loyaltyPoints, PaymentMethod* paymentMethod);
    double calculateRentalDiscount() override;

private:
    // TODO: add private members
    //inherits private members but cannot modify

};

#endif
