#include "Stock_Factory_i.h"

int ACE_TMAIN (int argc, char* argv[]) {
	try {
		CORBA::ORB_var orb = CORBA::ORB_init(argc,argv);
		CORBA::Object_var poa_object = orb->resolve_initial_references("RootPOA");
		PortableServer::POA_var poa = PortableServer::POA::_narrow(poa_object.in());
		PortableServer::POAManager_var poa_manager = poa->the_POAManager();
		poa_manager->activate();

		Quoter_Stock_Factory_i stock_factory_i;

		Quoter::Stock_Factory_var stock_factory = stock_factory_i._this();

		CORBA::String_var ior = orb->object_to_string(stock_factory.in());

		cout << ior.in() << endl;

		orb->run();

		poa->destroy(1,1);
		orb->destroy();
	} catch (CORBA::Exception &) {
		cerr << "CORBA exception raised!" << endl;
	}

	return 0;
}
