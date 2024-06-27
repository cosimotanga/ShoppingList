//OBSERVER
//

#ifndef OBSERVER_H
#define OBSERVER_H
#include "ShoppingList.h"
#include <string>


class Observer {
    public:
        virtual void update(std::string name) = 0;
        virtual ~Observer () = default;
    
};
#endif
