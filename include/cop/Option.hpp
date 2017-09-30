#ifndef Deefi4aw_COP_OPTION_HPP_INCLUDED
#define Deefi4aw_COP_OPTION_HPP_INCLUDED

#include <cop/Meta.hpp>
#include <cop/exc.hpp>
#include <cop/parsers.hpp>

#include <experimental/optional>

namespace cop
{
    template<typename T>
    class Option
    {
        public:
            Option(Meta & meta, char shortOpt, std::string longOpt)
                : m_shortOpt(shortOpt)
                , m_longOpt(longOpt)
            {
                meta.addOpt([this](ArgVec & args) { parse(args); });
            }

            const T& operator()() const { return m_value.value(); }
            bool isDefined() const { return bool(m_value); }
        private:
            void parse(ArgVec & args) {
                ArgConsumer consumer(args);
                parseHelper(m_shortOpt, m_longOpt, args,
                    [&consumer, &args, this](auto&& index, auto&& value)
                    {
                        if (index + 1 < args.size()) {
                            m_value = parseValue<T>(args[index + 1]);
                            consumer.markAsConsumed(index, index + 1);
                        } else {
                            throw MissingOptionArgument(args[index]);
                        }
                    }
                );
            }
            std::experimental::optional<T> m_value;
            char m_shortOpt;
            std::string m_longOpt;
    };
}

#endif
