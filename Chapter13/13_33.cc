#include "Message.h"
#include "Folder.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
	Message m("hi"), m2("bye");
	Folder f1, f2;
	m.save(f1);
	m2.save(f1);
	m.save(f2); 
	{
		Message m_scope("OutScope");
		m_scope.save(f2);
	}
	{
		Folder f_scope;
		m.save(f_scope);
	}
/*
	m.print_folders();
	Folder f3;
	f3 = f1;
	cout << endl;
	m.print_folders();
	cout << endl; */

	/*f1.print_messages();
	cout << endl;
	Message m4;
	m4 = m;

	f1.print_messages();
	cout << endl;*/
	/*
	m.print_folders() ;
	cout << endl;
	m2.print_folders() ;
	cout << endl;
	f2.print_messages() ; 
	swap(m2, m);
	f2.print_messages() ; 
	cout << endl;
	m2.print_folders() ;
	cout << endl;
	m.print_folders() ;
	cout << endl;*/
	return 0;
}