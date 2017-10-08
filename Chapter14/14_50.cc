struct LongDouble {
public:
	LongDouble(double d = 0.0) : val(d) {};
	operator double() const {return val;}
	operator float() const {return val;}

private:
	long double val = 0.0L;
};


int main() {
	LongDouble ldObj;
	//longdouble can be converted to double or float before int (ambiguous)
	//int ex1 = ldObj;

	//conversion to float is preferential since it does not require an extra built-in conversion after the user-defined conversion
	float ex2 = ldObj;

	return 0;
}