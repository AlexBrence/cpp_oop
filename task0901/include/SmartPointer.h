#pragma once

#include <iostream>
#include <sstream>


template <typename T>
class SmartPointer {
    private:
        T* object = nullptr;

    public:
        explicit SmartPointer(T* object) : object(object) {}
        ~SmartPointer() { if (object) delete object; }

        T& operator*() const { return *object; }    
        T* operator->() const { return object; }
};


