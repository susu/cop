#ifndef eeVu1aig_COP_EXC_HPP_INCLUDED
#define eeVu1aig_COP_EXC_HPP_INCLUDED

#include <exception>

namespace cop
{
    class MissingOptionArgument : public std::runtime_error
    {
        public:
            MissingOptionArgument(const std::string& argName)
                : std::runtime_error("Option needs an argument: " + argName)
                , name(argName)
            {}

            const std::string name;
    };
}

#endif
