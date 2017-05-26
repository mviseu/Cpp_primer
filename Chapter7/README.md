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

## Exercise 7.51
*Vector* defines its single argument constructor as explicit because we do not want implicit conversions that create a temporary value-initialized vector exclusively based on its size information. On the other hand, a user will probably want to use a const char * and string interchangeably and therefore this constructor cannot be explicit.

## Exercise 7.56
A *static* class member is common to all objects of that class type, rather than being associated with the individual objects. For example, we may want to define a common interest rate in an Account class, which is common to all objects of type Account. 

Advantages
1. If there is a change in the value of a static member, all the objects of that class type will use this new value.
2. From an efficiency standpoint it is better to use a static member than have each object store the member (less important though than 1.).

Ways in which static class members differ from ordinary members
* A static data member can be of incomplete type;
* A static data member can be used as a default argument

