#pragma once

class State
{

public:
    virtual void Render() = 0;
    virtual void Update() = 0;
    virtual ~State() = 0;
};