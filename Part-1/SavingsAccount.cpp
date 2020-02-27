#include "SavingsAccount.h"

using namespace std;

// constructor initializes balance and interest rate
SavingsAccount::SavingsAccount( double initialBalance, double rate ) : Account( initialBalance ) 
{
	if (rate >= 0.0)
		interestRate = rate;
	else
		interestRate = 0.0;
}

double SavingsAccount::calculateInterest() {
	return interestRate * Account::getBalance();
} 
void SavingsAccount::display(ostream & os) const
{
	os << "Account Type: Saving" << endl;
	os << "Balance: $ " << Account::getBalance() << endl;
	os << "Interest Rate (%): " << interestRate << endl;
}
