#pragma once

struct X
{
	//Since rem uses base, base must be initialized first.
	X (int i, int j) : base(i), rem(base % j) {}
	//rem is initialized first 
	int base, rem;
};