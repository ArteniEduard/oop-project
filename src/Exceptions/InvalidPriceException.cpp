#include "../../include/Exceptions/InvalidPriceException.h"

InvalidPriceException::InvalidPriceException()
    : DeliveryException("Pretul unei comenzi trebuie sa fie pozitiv") {
}
