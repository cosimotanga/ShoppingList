#ifndef OBSERVER_H
#define OBSERVER_H

// #include "ShoppingList.h"

// Definition of the abstract class Observer
class Observer
{
public:
    virtual void update(std::string name) = 0;
    virtual ~Observer() = default;
};

#endif