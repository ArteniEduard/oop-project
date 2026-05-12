#ifndef COURIERUNAVAILABLEEXCEPTION_H
#define COURIERUNAVAILABLEEXCEPTION_H

#include "DeliveryException.h"

class CourierUnavailableException : public DeliveryException {
public:
    CourierUnavailableException();
};

#endif
