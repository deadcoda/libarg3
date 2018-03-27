//
// Created by Ryan Jennings on 2018-03-26.
//

#include "output.h"

namespace rj
{
    namespace terminal {

        // output related functions
        namespace output
        {
            // utility for variadic print
            std::ostream &print(std::ostream &os)
            {
                return os;
            }

            // output functions have their own mutex
            Mutex &get_mutex()
            {
                static Mutex m;
                return m;
            }
        }
    }
}