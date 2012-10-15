#include "QuoterC.h"

int main(int argc, char* argv[]) {
	try {
		// Initialize the ORB
		// This can fail with a CORBA::SystemException
		CORBA::ORB_var orb = CORBA::ORB_init (argc, argv, "TestClient");

		CORBA::Object_var factory_object = orb->string_to_object(argv[1]);
		CORBA::Stock_Factory_var factory = Quoter::Stock_Factory::_narrow(factory_object.in());
		// TAO supports the file: and corbaloc: 'scheme'
	
		// Read the symbols from the command-line args and fetch their prices
		for (int i=2; i!=argc; i++) {
			try {
				Quoter::Stock_var stock = factory->get_stock(ACE_TEXT_ALWAYS_CHAR(argv[i]));
				CORBA::String_var full_name = stock->full_name();
				CORBA::Double price = stock->price();

				cout << "The price of the stock " << full_name.in() << " is " << price << endl;
			} catch (Quoter::Invalid_Stock_Symbol &) {
				cerr << "Invalid stock symbol: " << argv[i] << endl;
			}
		}

		// Release resources
		orb->destroy();
	} catch (CORBA::Exception	&ex) {
		std::cerr << "CORBA	exception raised!" << std::endl;
	}

	return 0;
}
