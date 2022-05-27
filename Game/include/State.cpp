#include "State.h"
static int keyState = 0;
static int keyLevel = 0;

    // Chuyển sang trạng thái tiếp theo
void changeState(int nextState)
{
    keyState = nextState;
}
    // Trạng thái hiện tại
int getCurrentState ()
{
    return keyState;
};
    // Level 
void startLevel(int gotLevel)
{
    keyLevel = gotLevel;
};
int getLEVEL()
{
    return keyLevel;
}