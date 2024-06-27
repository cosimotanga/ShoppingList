//SUBJECT

#ifndef SUBJECT_H

#define SUBJECT_H
#include "Observer.h"
#include <iostream>

class Subject {
    public:
        virtual void attach(Observer* observer) = 0;
        virtual void detach(Observer* observer) = 0;
        virtual void notify() = 0;
        virtual ~Subject() = default;
};
#endif