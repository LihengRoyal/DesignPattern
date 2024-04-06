#include <iostream>
#include <string>

class PaymentStrategy {
 public:
    virtual void pay(double amount) const = 0;
};

class CashPaymentStrategy : public PaymentStrategy {
 public:
    virtual void pay(double amount) const override {
        std::cout << "Paid " << amount 
                    << " RMB in cash." << std::endl;
    } 
};

class CreditPaymentStrategy : public PaymentStrategy {
 private:
    std::string cardNumber;
    std::string cardHolder;
    std::string expirationDate;
 public:
    CreditPaymentStrategy(const std::string& number,
                          const std::string& name,
                          const std::string& data) 
        : cardNumber(number), cardHolder(name),
        expirationDate(data) { }

    virtual void pay(double amount) const override {
        std::cout << "Paid " << amount  
            << " RMB in crdit card. " << "( holder: " 
            << cardHolder << ", number: "
            << cardNumber << ", expiration time : "
            << expirationDate  << " )" << std::endl;
    }
};

class Order {
 private:
    double totalAmount;
    PaymentStrategy* myStrategy;
 public:
    Order(double amount, PaymentStrategy* strategy) 
        : totalAmount(amount), myStrategy(strategy) {}

    void processPayment() const {
        myStrategy->pay(totalAmount);
    }
};

int main() {
    PaymentStrategy* cashPay = new CashPaymentStrategy();
    Order od1(100.0, cashPay);
    od1.processPayment();

    PaymentStrategy* creditPay = new CreditPaymentStrategy("1234567",
                                                           "Heng",
                                                           "2024-3-20");
    Order od2(100.0, creditPay);
    od2.processPayment();
    return 0;
}