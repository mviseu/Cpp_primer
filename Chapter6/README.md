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

## Exercise 6.53

These two declarations are different since const is low-level. int arguments will be taken by the first function and const int arguments by the second.
```cpp
int calc(int&, int&);
int calc(const int&, const int&);
```
These two declarations are also different for the reason mentioned above. Pointer to char arguments will be taken by the first function and pointer to const char arguments will be taken by the second function.
```cpp
int calc(char*, char*);
int calc(const char *, const char *);
```
These two declarations are equivalent (top-level const is ignored in the second case).
```cpp
int calc(char*, char*);
int calc(char* const, char* const);
```
