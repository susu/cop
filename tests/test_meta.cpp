
#include <igloo/igloo_alt.h>
#include <cop/Meta.hpp>

using namespace igloo;

Describe(a_Meta)
{
    It(can_be_instantiated)
    {
        cop::Meta meta;
    }

    It(can_call_registered_opt_functions)
    {
        cop::Meta meta;
        bool fun1called = false;
        bool fun2called = false;
        meta.addOpt([&fun1called](auto) { fun1called = true; });
        meta.addOpt([&fun2called](auto) { fun2called = true; });
        meta.parse(0, nullptr);

        AssertThat(fun1called, Equals(true));
        AssertThat(fun2called, Equals(true));
    }

    It(passes_the_current_number_of_positional_arg_to_posarg_function)
    { /* TODO */ }

    It(do_something_with_remaining_args)
    { /* TODO */ }

    void setCalledFlags(std::string& fst, std::string& snd, const std::string& value)
    {
        if (fst.empty()) fst = value;
        else snd = value;
    }

    It(can_call_registered_positional_arg_functions_in_the_registration_order)
    {
        cop::Meta meta;
        std::string first, second;

        meta.addPositionalArg([&](auto, auto) { setCalledFlags(first, second, "FIRST"); });
        meta.addPositionalArg([&](auto, auto) { setCalledFlags(first, second, "SECOND"); });

        meta.parse(0, nullptr);

        AssertThat(first, Equals("FIRST"));
        AssertThat(second, Equals("SECOND"));
    }
};
