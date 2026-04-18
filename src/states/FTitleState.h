#pragma once

#include "FBaseState.h"

class FTitleState : public FBaseState
{
public:
    FTitleState() = default;
    ~FTitleState() override = default;

    EStateTransition Update(float DeltaTime) override;
};
