#include <tgmath.h>

#include "userfunctions.h"

long double f(long double t, long double c) {
    return t + (c/10);
}
long double g(long double t, long double c) {
    return tanl(t)/(sinl(c/10));
}
