#pragma once

#include <unistd.h>

namespace TRex {

    enum class Buttons {
        B = 0,              // groot licht
        A = 1,              // toeter         
        Y = 2,              // zwaai licht
        X = 3,              // lichten     
        L1 = 4,             // pinkers links     
        R1 = 5              // pinkers rechts                         
    };

    enum class Axes {
        leftJoystick = 1,   
        rightJoystick = 4,  
        down = 7            // onder licht
    };
}