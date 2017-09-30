#ifndef uoNie1ub_COP_ARGCONSUMER_HPP_INCLUDED
#define uoNie1ub_COP_ARGCONSUMER_HPP_INCLUDED

#include <cop/types.hpp>

namespace cop
{
    class ArgConsumer
    {
        public:
            ArgConsumer(ArgVec & args)
                : m_args(args)
                , m_markedArgs(args.size(), 0)
            {}

            ~ArgConsumer()
            {
                ArgVec newArgs;
                for (size_t i = 0; i < m_args.size(); ++i)
                {
                    if (m_markedArgs[i] == 0)
                        newArgs.push_back(m_args[i]);
                }
                m_args = std::move(newArgs);
            }

            void markAsConsumed(size_t i, size_t j)
            {
                markAsConsumed(i);
                markAsConsumed(j);
            }

            void markAsConsumed(size_t i)
            {
                m_markedArgs[i] = 1;
            }
        private:
            ArgVec & m_args;
            std::vector<int> m_markedArgs;
    };
}

#endif
