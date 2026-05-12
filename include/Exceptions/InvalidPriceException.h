#ifndef INVALIDPRICEEXCEPTION_H
#define INVALIDPRICEEXCEPTION_H

#include "DeliveryException.h"

class InvalidPriceException : public DeliveryException {
public:
    InvalidPriceException();
};

#endif
