/***************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (directui@nokia.com)
**
** This file is part of applauncherd
**
** If you have questions regarding the use of this file, please contact
** Nokia at directui@nokia.com.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/

#include "boosterfactory.h"
#include "booster.h"
#include "mbooster.h"
#include "qtbooster.h"
#include "wrtbooster.h"
#include "monitorbooster.h"

BoosterFactory::BoosterFactory()
{}

Booster * BoosterFactory::create(char type)
{
    if (type == MBooster::type())
    {
        return new MBooster();
    }
    else if (type == QtBooster::type())
    {
        return new QtBooster();
    }
    else if (type == WRTBooster::type())
    {
        return new WRTBooster();
    }
    else if (type == MonitorBooster::type())
    {
        return new MonitorBooster();
    }
    else
    {
        return NULL;
    }
}

void BoosterFactory::setProcessIdToBooster(char type, pid_t pid)
{
    if (type == MBooster::type())
    {
        MBooster::setProcessId(pid);
    }
    else if (type == QtBooster::type())
    {
        QtBooster::setProcessId(pid);
    }
    else if (type == WRTBooster::type())
    {
        WRTBooster::setProcessId(pid);
    }
    else if (type == MonitorBooster::type())
    {
        MonitorBooster::setProcessId(pid);
    }
}

char BoosterFactory::getBoosterTypeForPid(pid_t pid)
{
    if (pid == MBooster::processId())
    {
        return MBooster::type();
    }
    else if (pid == QtBooster::processId())
    {
        return QtBooster::type();
    }
    else if (pid == WRTBooster::processId())
    {
        return WRTBooster::type();
    }
    else if (pid == MonitorBooster::processId())
    {
        return MonitorBooster::type();
    }
    else
    {
        return 0;
    }
}

pid_t BoosterFactory::getBoosterPidForType(char type)
{
    if (MBooster::type() == type)
    {
        return MBooster::processId();
    }
    else if (QtBooster::type() == type)
    {
        return QtBooster::processId();
    }
    else if (WRTBooster::type() == type)
    {
        return WRTBooster::processId();
    }
    else
    {
        // not used for MonitorBooster
        return 0;
    }
}