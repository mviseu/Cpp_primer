##Exercise 7.8

```cpp
istream &read(istream &in, Sales_data &S1);
ostream &print(ostream &out, const Sales_data &S2);
```
S1 is a plain reference to Sales_data: the input stream value changes the argument that is binded to the parameter S1.
S2 can be a const &: its argument is not required to change hence S2 can take both const and implicitly converted non-const arguments.

##Exercise 7.10

```cpp
if (read(read(cin, data1), data2))

```
The code is equivalent to: 

```cpp
if(cin >> data1 >> data2)
```
if(true) is met only if cin sucessfully reads into data1 and data2.