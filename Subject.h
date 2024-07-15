#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
// #include "Product.h"

// Definition of the abstract class Subject
class Subject
{
public:
    virtual void attach(Observer *observer) = 0; //
    virtual void detach(Observer *observer) = 0; // Pure virtual method to attach, detach and notify an observer
    virtual void notify() = 0;                   //
    virtual ~Subject() = default;
};
#endif