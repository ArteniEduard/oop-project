#include "../../include/Exceptions/CourierUnavailableException.h"

CourierUnavailableException::CourierUnavailableException()
    : DeliveryException("Courier is not available") {}