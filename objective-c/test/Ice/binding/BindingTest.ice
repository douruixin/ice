// **********************************************************************
//
// Copyright (c) 2003-present ZeroC, Inc. All rights reserved.
//
// **********************************************************************

#pragma once

["objc:prefix:TestBinding"]
module Test
{

interface TestIntf
{
    string getAdapterName();
}

interface RemoteObjectAdapter
{
    TestIntf* getTestIntf();

    void deactivate();
}

interface RemoteCommunicator
{
    RemoteObjectAdapter* createObjectAdapter(string name, string endpoints);

    void deactivateObjectAdapter(RemoteObjectAdapter* adapter);

    void shutdown();
}

}
