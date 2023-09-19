//
// Created by BEN CISNEROS.
//

#ifndef HW5_VALUETYPE_H
#define HW5_VALUETYPE_H

#include <iostream>
#include <string>

#include "myException.h"

// An abstract class that represents different values at
// run-time (or during execution). This class is a generic
// base class that implements methods common to several
// subclasses
class valueType {
public:
    valueType(std::string = "");                // default parameterized constructor used to initialize
                                                // the value
    valueType(const valueType&);                // copy constructor used to initialize the attribute value
                                                // of this instance with the value stored in another object
                                                // of the same type
    virtual ~valueType();                       // destructor used as a workaround solution to silence
                                                // the warning message generated by g++
    virtual bool isIntegerType() const;         // returns true if the data value is a number
    virtual bool isStringType() const;          // returns true if the data value is a string
    virtual bool isCharType() const;            // returns true if the data value is a character
    virtual bool isNullType() const;            // returns true if the data value is null
    virtual int toIntegerType() throw (myException) = 0;        // converts the data stored in value to int
    virtual std::string toStringType() throw (myException) = 0; // converts the data stored in value to string (default type)
    virtual char toCharType() throw (myException) = 0;          // converts the data stored in value to char
    virtual int compare(valueType&) = 0;                    // compares the data stored in value with the argument and
                                                            // returns an integer value indicating the result of the
                                                            // comparison: a negative integer value if this value
                                                            // is less than, zero if they are equal, and a positive
                                                            // integer value if this value is greater than. Note that
                                                            // dynamic_cast should be used in order to cast a value
                                                            // type to the correct subclass (child class)
    virtual bool equals(valueType&) = 0;                    // returns true if this value is equal to that value.
                                                            // Note that you should make use of the compare function
                                                            // internally
    void setValue(std::string);                 // sets the value of a value type
    std::string realValue() const;              // returns the data stored in value as a string
    virtual void print() = 0;                   // displays the value of an instance of a valueType. The value
                                                // of an object depends on the type the object represents
                                                // during execution. The function must be overridden in the
                                                // subclass
    std::string typeAsString();                 // returns a string representation of this value type, that is,
                                                // it should return the type a value represent during execution
private:
    std::string value;  // the raw data
};

#endif //HW5_VALUETYPE_H
