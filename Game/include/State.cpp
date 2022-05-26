#include "State.h"
static int keyState = 0;

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