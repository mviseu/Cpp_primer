struct CAD {
	virtual void fnc1(int) = 0;

};

struct Vehicle {
	virtual void fnc2() = 0; 
};

// allowed to not specify any access specifier for Vehicle
class CADVehicle: public CAD, Vehicle {
public: 
	void fnc1(int i) override {}
};

/*
Not allowed to specify the same direct base class more than once
class CADVehicle: public CAD, public CAD {
public: 
	void fnc1(int i) override {}
};
*/
int main() {
	CADVehicle;
	return 0;
}