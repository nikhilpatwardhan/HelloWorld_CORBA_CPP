#include "QuoterS.h"

class Quoter_Stock_i : public POA_Quoter::Stock {
public:
	Quoter_Stock_i (const char* symbol, const char* full_name, CORBA::Double price);

	char* symbol();
	char* full_name();
	CORBA::Double price();

private:
	std::string symbol_;
	std::string full_name_;
	CORBA::Double price_;
};
