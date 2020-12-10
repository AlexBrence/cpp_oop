#pragma once

#include <iostream>

class ReferenceCounter {
    private:
        int count;

    public:
        ReferenceCounter();
        ReferenceCounter(const ReferenceCounter& rc);
        ~ReferenceCounter();

        ReferenceCounter& operator--();
        ReferenceCounter operator++(int dummy); 

        int get_count() const;
};


