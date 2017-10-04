#include <igloo/igloo_alt.h>
#include <cop/PosArg.hpp>
#include <cop/Meta.hpp>

using namespace igloo;

Describe(a_PosArg)
{
    It(can_be_instantiated)
    {
        cop::Meta meta;
        cop::PosArg<std::string> posArg(meta, "target");
    }

    It(can_parse_single_positional_argument)
    {
        cop::Meta meta;
        cop::PosArg<std::string> posArg(meta, "target");
        std::vector<const char*> argv = {"fortytwo"};
        meta.parse(argv.size(), &argv[0]);

        AssertThat(posArg(), Equals("fortytwo"));
    }

    It(can_parse_two_positional_argument)
    {
        cop::Meta meta;
        cop::PosArg<std::string> targetArg(meta, "target");
        cop::PosArg<std::string> sourceArg(meta, "source");
        std::vector<const char*> argv = {"someTarget", "a-source"};
        meta.parse(argv.size(), &argv[0]);

        AssertThat(targetArg(), Equals("someTarget"));
        AssertThat(sourceArg(), Equals("a-source"));
    }
};
