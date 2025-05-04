
#ifndef PAYMENT_H
#define PAYMENT_H

class PaymentMethod {
public:
    virtual bool processPayment(double amount) = 0;
    virtual ~PaymentMethod() = default;
    virtual double getBalance() const = 0;
};

class CreditCard : public PaymentMethod {
public:
    ... // TODO: add methods

private:
    ... // TODO: add private members
};

class PayPal : public PaymentMethod {
public:
    ... // TODO: add methods

private:
    ... // TODO: add private members
};

#endif
