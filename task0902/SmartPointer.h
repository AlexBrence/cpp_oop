//
// Created by alex on 29. 11. 20.
//

#ifndef TASK0902_SMARTPOINTER_H
#define TASK0902_SMARTPOINTER_H

#include "ReferenceCounter.h"

#include <iostream>


template <typename T>
class SmartPointer {
private:
    T* object = nullptr;

public:
    static ReferenceCounter* p_reference_counter;

    explicit SmartPointer(T* object) : object(object) { (*p_reference_counter)++; }
    ~SmartPointer() { if (object) delete object; --(*p_reference_counter); }

    T& operator*() const { return *object; }
    T* operator->() const { return object; }
};



#endif //TASK0902_SMARTPOINTER_H
