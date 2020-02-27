#include "CheckingAccount.h"

using namespace std;

	
// constructor initializes balance and transaction fee
CheckingAccount::CheckingAccount( double initialBalance, double fee ) : Account( initialBalance ) 
{
	if (free >= 0.0)
		transactionFee = fee;
	else
		transactionFee = 0.0;
} 

// credit (add) an amount to the account balance and charge fee
void CheckingAccount::credit( double amount )
{
	Account::setBalance(Account::getBalance() + amount);
	chargeFee();
} 

// debit (subtract) an amount from the account balance and charge fee
bool CheckingAccount::debit( double amount )
{
	if (Account::getBalance() - transactionFee > amount){
		Account::setBalance(Account::getBalance() - amount);
		chargeFee();
		return true;
	}else{
		return false;
	}
}

// subtract transaction fee
void CheckingAccount::chargeFee()
{
	Account::setBalance(Account::getBalance() - transactionFee);
}

void CheckingAccount::display(ostream & os) const
{
	os << "Account type: Checking" << endl;
	os << "Balance: $ " << Account::getBalance() << endl;
	os << "Transaction Fee: " << transactionFee << endl;
}
