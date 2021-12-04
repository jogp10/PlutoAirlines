//
// Created by john on 27/11/21.
//

#ifndef PLUTOAIRLINES_SERVICE_H
#define PLUTOAIRLINES_SERVICE_H

#include <string>

struct Service
{
    int type; // 0 for maintenance, 1 for clean
    string date, name; // date of the service, name of the employee
};

#endif //PLUTOAIRLINES_SERVICE_H
