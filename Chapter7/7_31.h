#pragma once

class X {
	//declare class Y to create a pointer to a Y element
	class Y;
	Y * ptrY;
};

//class X has already been defined
class Y {
	X dataX;
};