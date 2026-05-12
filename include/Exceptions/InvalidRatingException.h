#ifndef INVALIDRATINGEXCEPTION_H
#define INVALIDRATINGEXCEPTION_H

#include "DeliveryException.h"

class InvalidRatingException : public DeliveryException {
public:
    InvalidRatingException();
};

#endif
