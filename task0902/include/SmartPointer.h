#pragma once

#include <iostream>
#include "ReferenceCounter.h" 

template <typename T>
class SmartPointer {
    private:
        T* object = nullptr;
        ReferenceCounter* p_reference_counter = nullptr;

    public:
        explicit SmartPointer(T* object) : object(object) {  }        

        SmartPointer(const SmartPointer& sp) : object(sp.object), p_reference_counter(sp.p_reference_counter) {
            (*p_reference_counter)++;
        }

        ~SmartPointer() { 
            if (use_count() == 1) {
                delete object;
                delete p_reference_counter;
                return;
            }
            --(*p_reference_counter);
        }


        T& operator*() const { return *object; }    
        T* operator->() const { return object; }
        SmartPointer& operator=(const SmartPointer& other) {
            if (object == other.object) {
                return *this;
            } 
            if (use_count() == 1) {
                delete object;
                delete p_reference_counter;
            }

            p_reference_counter = other.p_reference_counter;
            object = other.object;
            (*p_reference_counter)++;
            
            return *this;
        }

        int use_count() { return p_reference_counter->get_count(); }
};
