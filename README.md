C++ Primer

5th Edition

Exercises 

## Exercise 6.52

```cpp
void manip(int, int);
double dobj;

//conversion from char to int is integral promotion rank 3
manip('a', 'z');
//conversion from doubles to int of rank 4 
manip(55.4, dobj);

//the first function has matching precedence.

```
