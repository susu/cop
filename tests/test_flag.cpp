#include <igloo/igloo_alt.h>
#include <cop/Flag.hpp>
#include <cop/exc.hpp>

using namespace igloo;

Describe(a_Flag)
{
    It(can_be_instantiated)
    {
        cop::Meta meta;
        cop::Flag flag(meta, 'd', "dry-run");
    }

    It(can_parse_argumentless_options)
    {
        cop::Meta meta;
        cop::Flag flag(meta, 'd', "dry-run");

        std::vector<const char*> argv = {"--dry-run"};
        meta.parse(argv.size(), &argv[0]);

        AssertThat(flag.isDefined(), Equals(true));
    }

    It(will_not_be_defined_if_argument_is_not_provided)
    {
        cop::Meta meta;
        cop::Flag flag(meta, 'd', "dry-run");

        std::vector<const char*> argv = {};
        meta.parse(argv.size(), &argv[0]);
        AssertThat(flag.isDefined(), Equals(false));
    }
};
