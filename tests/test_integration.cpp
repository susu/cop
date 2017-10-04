
#include <igloo/igloo_alt.h>
#include <cop/cop.hpp>

using namespace igloo;

Describe(the_cop)
{
    struct OptionsOnlyConfig {
        cop::Meta meta;
        cop::Option<int> destination = cop::Option<int>(meta, 'd', "destination");
        cop::Option<int> source = cop::Option<int>(meta, 's', "source");
    };

    It(can_parse_shortopts)
    {
        std::vector<const char*> argv = {"-d", "42", "-s", "140"};
        OptionsOnlyConfig config;
        config.meta.parse(argv.size(), &argv[0]);

        AssertThat(config.destination(), Equals(42));
        AssertThat(config.source(), Equals(140));
    }

    It(can_parse_longopts)
    {
        std::vector<const char*> argv = {"--destination", "42", "--source", "140"};
        OptionsOnlyConfig config;
        config.meta.parse(argv.size(), &argv[0]);

        AssertThat(config.destination(), Equals(42));
        AssertThat(config.source(), Equals(140));
    }

    struct PositionalsOnlyConfig {
        cop::Meta meta;
        cop::PosArg<std::string> animal = cop::PosArg<std::string>(meta, "animal");
        cop::PosArg<std::string> plant = cop::PosArg<std::string>(meta, "plant");
    };

    It(can_parse_positional_arguments)
    {
        std::vector<const char*> argv = {"dog", "tree"};
        PositionalsOnlyConfig config;
        config.meta.parse(argv.size(), &argv[0]);

        AssertThat(config.animal(), Equals("dog"));
        AssertThat(config.plant(), Equals("tree"));
    }

    struct FlagsOnlyConfig {
        cop::Meta meta;
        cop::Flag longFormat = cop::Flag(meta, 'l', "long");
        cop::Flag time = cop::Flag(meta, 't', "time");
        cop::Flag reverse = cop::Flag(meta, 'r', "reverse");
        cop::Flag all = cop::Flag(meta, 'a', "all");
    };

    It(can_parse_flags)
    {
        std::vector<const char*> argv = {"-l", "-r"};
        FlagsOnlyConfig config;
        config.meta.parse(argv.size(), &argv[0]);

        AssertThat(config.longFormat.isDefined(), Equals(true));
        AssertThat(config.time.isDefined(), Equals(false));
        AssertThat(config.reverse.isDefined(), Equals(true));
        AssertThat(config.all.isDefined(), Equals(false));
    }

    It(can_parse_flags_as_one_argument)
    {

        std::vector<const char*> argv = {"-ltra"};
        FlagsOnlyConfig config;
        config.meta.parse(argv.size(), &argv[0]);

        AssertThat(config.longFormat.isDefined(), Equals(true));
        AssertThat(config.time.isDefined(), Equals(true));
        AssertThat(config.reverse.isDefined(), Equals(true));
        AssertThat(config.all.isDefined(), Equals(true));
    }
};
