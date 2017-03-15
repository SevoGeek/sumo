/****************************************************************************/
/// @file    TraCI_POI.h
/// @author  Daniel Krajzewicz
/// @author  Mario Krumnow
/// @author  Jakob Erdmann
/// @author  Michael Behrisch
/// @author  Robert Hilbrich
/// @date    30.05.2012
/// @version $Id$
///
// C++ TraCI client API implementation
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.dlr.de/
// Copyright (C) 2017-2017 DLR (http://www.dlr.de/) and contributors
/****************************************************************************/
//
//   This file is part of SUMO.
//   SUMO is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include "../../config.h"
#endif

#include <utils/shapes/PointOfInterest.h>
#include <utils/shapes/ShapeContainer.h>
#include <microsim/MSNet.h>
#include "TraCI_POI.h"

#ifdef CHECK_MEMORY_LEAKS
#include <foreign/nvwa/debug_new.h>
#endif // CHECK_MEMORY_LEAKS


// ===========================================================================
// member definitions
// ===========================================================================
std::vector<std::string>
TraCI_POI::getIDList() {
    std::vector<std::string> ids;
    ShapeContainer& shapeCont = MSNet::getInstance()->getShapeContainer();
    shapeCont.getPOIs().insertIDs(ids);
    return ids;
}

int
TraCI_POI::getIDCount() {
    return (int)getIDList().size();
}

std::string
TraCI_POI::getType(const std::string& poiID) {
    return getPoI(poiID)->getType();
}

TraCIColor
TraCI_POI::getColor(const std::string& poiID) {
    TraCIColor col;
    PointOfInterest* p = getPoI(poiID);
    col.r = p->getColor().red();
    col.g = p->getColor().green();
    col.b = p->getColor().blue();
    col.a = p->getColor().alpha();
    return col;
}

TraCIPosition
TraCI_POI::getPosition(const std::string& poiID) {
    TraCIPosition pos;
    PointOfInterest* p = getPoI(poiID);
    pos.x = p->x();
    pos.y = p->y();
    pos.z = p->z();
    return pos;
}

void
TraCI_POI::setType(const std::string& poiID, const std::string& setType) {
}

void
TraCI_POI::setPosition(const std::string& poiID, double x, double y) {
}

void
TraCI_POI::setColor(const std::string& poiID, const TraCIColor& c) {
}

void
TraCI_POI::add(const std::string& poiID, double x, double y, const TraCIColor& c, const std::string& type, int layer) {
}

void
TraCI_POI::remove(const std::string& poiID, int layer) {
}

PointOfInterest*
TraCI_POI::getPoI(const std::string& id) {
    return MSNet::getInstance()->getShapeContainer().getPOIs().get(id);
}


/****************************************************************************/
