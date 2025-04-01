#include "ECCalculator.hpp"
#include "ECNumbers.hpp"

using namespace ECNumbers;

int ECFourTimesN(int n){
    return ECDoubleN(ECDoubleN(n)); 
}
