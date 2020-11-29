//
// Created by alex on 29. 11. 20.
//

#ifndef TASK0902_REFERENCECOUNTER_H
#define TASK0902_REFERENCECOUNTER_H


class ReferenceCounter {
private:
    int count = 0;

public:
    ReferenceCounter();
    ReferenceCounter(const ReferenceCounter& rc);
    ~ReferenceCounter();

    ReferenceCounter& operator--();
    ReferenceCounter operator++(int dummy);
};


#endif //TASK0902_REFERENCECOUNTER_H
