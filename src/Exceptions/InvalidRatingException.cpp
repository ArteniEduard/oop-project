#include "../../include/Exceptions/InvalidRatingException.h"


InvalidRatingException::InvalidRatingException()
    : DeliveryException("Invalid rating: must be between 0 and 5") {}