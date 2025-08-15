#pragma once

class IAppEvents {
public:
    virtual ~IAppEvents() = default;
    virtual void requestExit() = 0;
};