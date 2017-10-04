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

                for (size_t i = 0; i < args.size(); ++i) {
                    if (args[i] == "-" + std::string(1, m_shortOpt) ||
                        args[i] == "--" + m_longOpt)
                    {
                        m_defined = true;
                        consumer.markAsConsumed(i);
                        break;
                    }
                    else if (args[i].size() > 2 && args[i][0] == '-' && args[i][1] != '-') {
                        // like -ltra
                        args[i] = parseJointArg(args[i]);
                        break;
                    }
                }
            }

            std::string parseJointArg(const std::string & arg) {
                std::string newArgument("-");
                for (size_t j = 1; j < arg.size(); ++j)
                {
                    if (arg[j] == m_shortOpt)
                        m_defined = true;
                    else
                        newArgument.push_back(arg[j]);
                }
                return newArgument;
            }

            bool m_defined = false;
            char m_shortOpt;
            std::string m_longOpt;
    };
}

#endif
