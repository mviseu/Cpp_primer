#include <iostream>
#include <string>

class base {
public:
	std::string name() const {return basename;}
	virtual void print(std::ostream &os) const {os << basename << " base";}
private:
	std::string basename;
};

class derived: public base {
public:
	void print(std::ostream &os) const override {base::print(os); os << " " << i << " derived";}
private:
	int i = 0;
};

int main() {
	base bobj;
	derived dobj;
	base *bp1 = &bobj;
	base *bp2 = &dobj;
	base &br1 = bobj;
	base &br2 = dobj;
	bobj.print(std::cout);
	dobj.print(std::cout);
	bp1->name();
	bp2->name();
	br1.print(std::cout);
	br2.print(std::cout);
	return 0;
}
