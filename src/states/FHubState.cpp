#include "FHubState.h"

void FHubState::OnEnter()
{
    // Initialize Hub state
}

void FHubState::OnExit()
{
    // Cleanup Hub state
}

EStateTransition FHubState::Update(float DeltaTime)
{
    // TODO: Handle input to transition to Dungeon
    return EStateTransition::None;
}
