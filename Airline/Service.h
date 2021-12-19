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
    /**
     * Type of Service
     */
    ServType type;// 0 for maintenance, 1 for clean

    /**
     * Name of worker
     */
    string name;

    /**
     * Date of the Service
     */
    Date date;

    /**
     * Airplane's plate where Service is being performed
     */
    string airplane_plate;

};

#endif //PLUTOAIRLINES_SERVICE_H
