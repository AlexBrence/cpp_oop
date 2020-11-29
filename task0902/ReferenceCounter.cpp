//
// Created by alex on 29. 11. 20.
//

#include "ReferenceCounter.h"

ReferenceCounter::ReferenceCounter() {
}

ReferenceCounter::ReferenceCounter(const ReferenceCounter& rc) : count(rc.count) {
}

ReferenceCounter::~ReferenceCounter() {
}

ReferenceCounter& ReferenceCounter::operator--() {
    --count;
    return *this;
}

ReferenceCounter ReferenceCounter::operator++(int dummy) {
    ReferenceCounter tmp(*this);
    count++;
    return tmp;
}

