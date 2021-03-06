// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class BankAccount {

protected:
	int accountNumber;
	double interestRate;
	double balance;
	double monthlyInterest;
public:
	BankAccount() {}
	BankAccount(int a, double e, double c,double d) { accountNumber = a;  balance = c;  }

	void set_AccountNumber(int a) { accountNumber = a; }
	virtual void WithdrawFunds(double value) = 0;
	virtual void DepositFunds(double value) = 0;
	virtual void DisplayAttributes() = 0;
	virtual void calculateInterestRate() = 0;
	void calculatemonthlyInterest() { monthlyInterest = 0;  }
};

class SavingsAccount : public BankAccount {

public:
	SavingsAccount() {} 
	SavingsAccount(int d, double e , double f, double g) : BankAccount(d, e, f,g) { }

	
	void calculateInterestRate()
	{
	 if (balance < 10000 )
	{
	  interestRate = 1;
	}
	 if (balance >=10000 )
	{
	  interestRate = 2;
	}
	}
	
	void calculatemonthlyInterest()
	{
	calculateInterestRate();
	monthlyInterest = (interestRate / 100) * balance;
	balance = balance + monthlyInterest;
	cout << (interestRate / 100) * balance;
	}

	void WithdrawFunds(double value) 
	{
	
	double balancechecker = balance - value;

	if(balancechecker > 0)
	{ 
	balance = (balance - value)-2;
	cout<<"transaction was a success"<<endl;
	}
	else{ cout<<"transcation was a failure"<<endl;}
	}

	void DepositFunds(double value) 
	{
	balance = balance + value;
	}

	void DisplayAttributes() {
		cout << "Account Number: ";
		cout << accountNumber << endl;
		cout << "Interest Rate: ";
		cout << interestRate << endl;
		cout << "Balance: ";
		cout << balance << endl;
	}
	
};

class CheckingAccount : public BankAccount {


public:
	CheckingAccount() {}
	CheckingAccount(int d, double e,  double f, double g) : BankAccount(d,e,f,g ) { }

	void calculateInterestRate() { interestRate = 0; }
	
	void orderCheck(){balance=balance-15;}
	

	void WithdrawFunds(double value) 
	{ 
	double balancechecker = balance - value;

	if(balancechecker > 0)
	{ 
	balance = (balance - value);
	cout<<"transaction was a success"<<endl;
	}
	else{ cout<<"transcation was a failure"<<endl;}
	
	if(balancechecker<500){ balance = balance-5;}
	}

	void DepositFunds(double value) { balance = balance + value;}
	void DisplayAttributes() {
		cout << "Account Number: ";
		cout << accountNumber << endl;
		cout << "Interest Rate: ";
		cout << interestRate << endl;
		cout << "Balance: ";
		cout << balance << endl;
	}
};

class CDAccount : public BankAccount {

protected:
		int term;

		

public:
	CDAccount() {} 
	CDAccount (int d, double e, double f, double g,int h) : BankAccount(d,e,f,g) { term=g;  }

	int setTerm(int theterm) { term = theterm; return term; }
	
	void calculatemonthlyInterest()
	{
	monthlyInterest = (interestRate/100) * balance;
	balance = balance + monthlyInterest;
	cout << (interestRate / 100) * balance;
	}

    void calculateInterestRate(){if (term >=5 ){interestRate = 10;} else {interestRate=5;}}

	void WithdrawFunds(double value) {
		double balancechecker = balance - value;
		int aterm;
		int earlytermwidthrawlyear = 2;
	if(balancechecker > 0)
	{ 
	cout<<"transaction was a success (0)"<<endl;
	

	aterm = setTerm(3);

	// takes preset values aterm and earlytermwidthdraw to simulate the consequence of widthdrawing money before the term is done

	if (aterm > earlytermwidthrawlyear){balance= balance - (balance*.01); } else{ balance = balance - value; }
	}
	else{ cout<<"transcation was a failure (-1)"<<endl;}
	
	}

	void DepositFunds(double value) { balance = balance + value; }
	void DisplayAttributes() {
		cout << "Account Number: ";
		cout << accountNumber << endl;
		cout << "Interest Rate: ";
		cout << interestRate << endl;
		cout << "Balance: ";
		cout << balance << endl;
	}
};

int main ()
{

string displayoutput;
SavingsAccount one;
CheckingAccount two;
CDAccount three;

BankAccount * oneptr = new SavingsAccount(0,0,0,0);
BankAccount * twoptr = new CheckingAccount(0,0,0,0);
BankAccount * threeptr = new CDAccount(0,0,0,0,0);

oneptr->DepositFunds(10000);
twoptr->DepositFunds(600);
threeptr->DepositFunds(10000);

oneptr->calculateInterestRate();
twoptr->calculateInterestRate();
threeptr->calculateInterestRate();


oneptr->set_AccountNumber(1111);
twoptr->set_AccountNumber(2222);
threeptr->set_AccountNumber(3333);


//Displays attributes for all accounts

oneptr->DisplayAttributes();
twoptr->DisplayAttributes();
threeptr->DisplayAttributes();
cout << " ";


// calculate monthly interest for savings acount
cout << "Monthly interest of the savings account:  ";
 oneptr->calculatemonthlyInterest();
 cout << " ";
//need to calculate monthly interest for Certificate of Deposit account
cout << "Monthly interest of the savings account:  ";
threeptr->calculatemonthlyInterest();
cout << " ";
//______________________________________________
//Then display attribures again after calculation

oneptr->DisplayAttributes();
twoptr->DisplayAttributes();
threeptr->DisplayAttributes();
cout << " ";
//______________________________________________

//Order Checks
two.orderCheck();

//withdrawl of 200 dollars from checking
twoptr->WithdrawFunds(200);

//widthdraw1 of 1000 dollars from savings
oneptr->WithdrawFunds(1000);

//perform early widthrawl of 2000 from the CD account
threeptr->WithdrawFunds(20000);
cout << " ";
//______________________________________________
//Display attribures again after widthdrawls
oneptr->DisplayAttributes();
twoptr->DisplayAttributes();
threeptr->DisplayAttributes();
//______________________________________________

delete oneptr;
delete twoptr;
delete threeptr;

// This is here so output stays on.
cin >> displayoutput;

}
