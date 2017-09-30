
#include <igloo/igloo_alt.h>
#include <cop/ArgConsumer.hpp>

using namespace igloo;

Describe(an_ArgConsumer)
{
    std::vector<std::string> getTestData() {
        return {"-d", "1", "--asdf", "kutya"};
    }

    It(can_be_instantiated)
    {
        auto args = getTestData();
        cop::ArgConsumer consumer(args);
    }

    It(can_mark_parsed_args_and_remove_them_upon_deconstruction)
    {
        auto args = getTestData();
        {
            cop::ArgConsumer consumer(args);
            consumer.markAsConsumed(0, 1);
            AssertThat(args.size(), Equals(4));
        }
        AssertThat(args.size(), Equals(2));
        AssertThat(args[0], Equals("--asdf"));
        AssertThat(args[1], Equals("kutya"));
    }
};
