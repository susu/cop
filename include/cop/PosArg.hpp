#ifndef AiQu4IeP__COP_HPP_INCLUDED
#define AiQu4IeP__COP_HPP_INCLUDED

#include <cop/Meta.hpp>
#include <cop/parsers.hpp>
#include <cop/ArgConsumer.hpp>

#include <experimental/optional>

namespace cop
{
    template<typename T>
    class PosArg
    {
        public:
            PosArg(Meta & meta, const std::string & name)
                : m_name(name)
            {
                meta.addPositionalArg([this](ArgVec& args, size_t pos) {
                    parse(args, pos);
                });
            }

            const T& operator()() const
            { return m_value.value(); }
        private:
            void parse(ArgVec& args, size_t position) {
                ArgConsumer consumer(args);
                m_value = parseValue<T>(args[0]);
                consumer.markAsConsumed(0);
            }

            std::experimental::optional<T> m_value;
            std::string m_name;
    };
}

#endif
