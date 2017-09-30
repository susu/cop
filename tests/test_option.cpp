#include <igloo/igloo_alt.h>
#include <cop/Option.hpp>
#include <cop/exc.hpp>

using namespace igloo;

Describe(an_Option)
{

    It(can_be_instantiated)
    {
        cop::Meta meta;
        cop::Option<std::string> option(meta, 'o', "output");
    }

    It(can_parse_option)
    {
        cop::Meta meta;
        cop::Option<std::string> option(meta, 'o', "output");
        std::vector<const char*> argv = {"--output", "asdf"};
        meta.parse(argv.size(), &argv[0]);

        AssertThat(option.isDefined(), Equals(true));
        AssertThat(option(), Equals("asdf"));
    }

    It(is_not_defined_if_option_was_not_provided)
    {
        cop::Meta meta;
        cop::Option<std::string> option(meta, 'o', "output");
        std::vector<const char*> argv = {};
        meta.parse(argv.size(), &argv[0]);

        AssertThat(option.isDefined(), Equals(false));
    }

    It(throws_exception_if_parameter_is_missing_after_option)
    {
        cop::Meta meta;
        cop::Option<std::string> option(meta, 'o', "output");
        std::vector<const char*> argv = {"--output"};
        AssertThrows(cop::MissingOptionArgument, meta.parse(argv.size(), &argv[0]));
        Assert::That(
            LastException<cop::MissingOptionArgument>().name,
            Equals("--output")
        );
    }

    It(throws_exception_with_shortopt_as_name_if_defined_as_short)
    {
        cop::Meta meta;
        cop::Option<std::string> option(meta, 'o', "output");
        std::vector<const char*> argv = {"-o"};
        AssertThrows(cop::MissingOptionArgument, meta.parse(argv.size(), &argv[0]));
        Assert::That(
            LastException<cop::MissingOptionArgument>().name,
            Equals("-o")
        );
    }
};
