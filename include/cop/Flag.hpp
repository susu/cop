#ifndef uN0yeBu3_COP_OPTION_HPP_INCLUDED
#define uN0yeBu3_COP_OPTION_HPP_INCLUDED

#include <cop/Meta.hpp>
#include <cop/ArgConsumer.hpp>
#include <cop/parsers.hpp>

namespace cop
{
    class Flag
    {
        public:
            Flag(Meta & meta, char shortOpt, std::string longOpt)
                : m_shortOpt(shortOpt)
                , m_longOpt(longOpt)
            { meta.addOpt([this](ArgVec & args) { parse(args); }); }

            bool isDefined() const
            { return m_defined; }

        private:
            void parse(ArgVec& args) {
                ArgConsumer consumer(args);

                parseHelper(m_shortOpt, m_longOpt, args,
                    [this, &consumer](size_t index, auto) {
                        m_defined = true;
                        consumer.markAsConsumed(index);
                    }
                );
            }

            bool m_defined = false;
            char m_shortOpt;
            std::string m_longOpt;
    };
}

#endif
