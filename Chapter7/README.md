## Exercise 7.8

```cpp
istream &read(istream &in, Sales_data &S1);
ostream &print(ostream &out, const Sales_data &S2);
```
S1 is a plain reference to Sales_data: the input stream value changes the argument that is binded to the parameter S1.
S2 can be a const &: its argument is not required to change hence S2 can take both const and implicitly converted non-const arguments.

## Exercise 7.10

```cpp
if (read(read(cin, data1), data2))

```
The code is equivalent to: 

```cpp
if(cin >> data1 >> data2)
```
if(true) is met only if cin sucessfully reads into data1 and data2.


## Exercise 7.25
The Screen class can safely rely on the default versions of copy assignment, where copying/assigning the class object copies/assigns each one of its data members. Classes that need dynamic memory generally cannot rely on the default versions of copy/assign. However, the default version of copy/assign works correctly for vector and string members such as the *contents* member of class screen.

## Exercise 7.47

Explicit Sales_data constructor that takes string argument

Drawbacks
1. Cannot be implicitly converted, i.e., a string cannot be used where a Sales_data object is expected (less flexible)
2. A string cannot be copied and assigned to create a Sales_data object

Benefits
1. Avoids creation of a temp Sales_data object that is destroyed after its use
