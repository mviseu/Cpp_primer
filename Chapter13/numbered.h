#pragma once
class numbered {
public:
	int mysn = 0;
	numbered() : mysn(ctr++) {}
	numbered(const numbered &) : mysn(ctr++) {}
private:
	static int ctr;
};