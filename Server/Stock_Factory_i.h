#include "Stock_i.h"

class Quoter_Stock_Factory_i : public POA_Quoter::Stock_Factory {
public:
	Quoter_Stock_Factory_i ();
	Quoter::Stock_ptr get_stock(const char* symbol);

private:
	Quoter_Stock_i rhat_;
	Quoter_Stock_i msft_;
};
