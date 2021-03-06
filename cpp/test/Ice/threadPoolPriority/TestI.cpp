// **********************************************************************
//
// Copyright (c) 2003-present ZeroC, Inc. All rights reserved.
//
// **********************************************************************

#include <Ice/Ice.h>
#include <TestI.h>

using namespace Test;
using namespace std;

PriorityI::PriorityI(const Ice::ObjectAdapterPtr& adapter) :
    _adapter(adapter)
{
}

void
PriorityI::shutdown(const Ice::Current&)
{
    _adapter->getCommunicator()->shutdown();
}

int
PriorityI::getPriority(const Ice::Current&)
{
#ifdef _WIN32
    return GetThreadPriority(GetCurrentThread());
#else
    sched_param param;
    int sched_policy;
    pthread_t thread = pthread_self();
    pthread_getschedparam(thread, &sched_policy, &param);
    return param.sched_priority;
#endif
}
