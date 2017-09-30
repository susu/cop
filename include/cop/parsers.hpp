#ifndef Huy5jiel_COP_PARSERS_HPP_INCLUDED
#define Huy5jiel_COP_PARSERS_HPP_INCLUDED

namespace cop
{
    template<typename T>
    T parseValue(const std::string& str);

    template<>
    inline std::string parseValue<std::string>(const std::string& str)
    { return str; }

    template<>
    inline int parseValue<int>(const std::string& str)
    { return std::atoi(str.c_str()); }

    inline bool parseHelper(char shortOpt,
                            const std::string& longOpt,
                            ArgVec & args,
                            std::function<void(size_t, const std::string&)> action)
    {
        for (size_t i = 0; i < args.size(); ++i) {
            if (args[i] == "--" + longOpt) {
                action(i, args[i]);
                return true;
            }
            if (args[i] == "-" + std::string(1, shortOpt)) {
                action(i, args[i]);
                return true;
            }
        }
        return false;
    }
}


#endif
