//
// Created by john on 27/11/21.
//

#ifndef PLUTOAIRLINES_SERVICE_H
#define PLUTOAIRLINES_SERVICE_H

#include <string>
#include "Date.h"

enum ServType {MAINTENANCE, CLEAN};
struct Service
{
    ServType type; // 0 for maintenance, 1 for clean
    string name;
    Date date;
    // date of the service, name of the employee

};

#endif //PLUTOAIRLINES_SERVICE_H
