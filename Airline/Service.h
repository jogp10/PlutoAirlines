//
// Created by john on 27/11/21.
//

#ifndef PLUTOAIRLINES_SERVICE_H
#define PLUTOAIRLINES_SERVICE_H

#include <string>
#include "Date.h"

enum ServType {MAINTENANCE, CLEAN};
static unordered_map<string, ServType> const servtable = {{"CLEAN", ServType::CLEAN},
                                                       {"MAINTENANCE", ServType::MAINTENANCE}};


struct Service
{
    ServType type; // 0 for maintenance, 1 for clean
    string name;
    Date date;
    // date of the service, name of the employee
    string airplane_plate;

};

#endif //PLUTOAIRLINES_SERVICE_H
