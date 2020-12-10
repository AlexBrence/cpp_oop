#include "ReferenceCounter.h"

ReferenceCounter::ReferenceCounter() : count(0) {
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


int ReferenceCounter::get_count() const {
    return count;
}
