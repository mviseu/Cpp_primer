C++ Primer

5th Edition

Exercises 

## Exercise 6.52

```cpp
void manip(int, int);
double dobj;

//conversion from char to int is match through integral promotion
manip('a', 'z');
//conversion from doubles to int is match through arithmetic conversion 
manip(55.4, dobj);

//the first function has matching precedence.

```
