#ifndef iXae5ohG_COP_META_HPP_INCLUDED
#define iXae5ohG_COP_META_HPP_INCLUDED

#include <functional>
#include <cop/ArgConsumer.hpp>

namespace cop
{
    class Meta
    {
        public:
            void addOpt(std::function<void(ArgVec&)> fn) {
                optParser.push_back(fn);
            }

            void addPositionalArg(std::function<void(ArgVec&, size_t)> fn) {
                positionalArgParsers.push_back(
                    [this, fn](ArgVec& args) {
                        fn(args, positionalArgParsers.size());
                    }
                );
            }

            void parse(int argc, char** argv) {
                std::cout << argc << std::endl;
                ArgVec args(argv, argv+argc);
                for (auto&& o : optParser) { o(args); }
                for (auto&& p : positionalArgParsers) { p(args); }

                for (auto&& remaining : args) {
                    std::cout << "WARNING: remaining extra arg: " << remaining << std::endl;
                }
            }
        private:
            std::vector<std::function<void(ArgVec&)>> optParser;
            std::vector<std::function<void(ArgVec&)>> positionalArgParsers;
    };
}

#endif
