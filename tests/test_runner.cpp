#include <igloo/igloo_alt.h>

using namespace igloo;

class LoggerTestListener : public NullTestListener
{
  public:
    LoggerTestListener()
      : m_out(std::cout)
    {}
    virtual void SpecRunStarting(const ContextBase&, const std::string& name)
    {
      m_out << "  * It " << name << std::endl;
    }
    virtual void ContextRunStarting(const ContextBase& context)
    {
      m_out << "\n# Describe " << context.Name() << std::endl;
    }
    virtual void SpecSucceeded(const ContextBase&, const std::string&)
    {
#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__))
      m_out << "    [SUCCESS!]" << std::endl;
#else
      m_out << "    \033[1;32m" << "[SUCCESS!]" << "\033[0m" << std::endl;
#endif
    }
  private:
    std::ostream & m_out;
};

int main() {
  DefaultTestResultsOutput output;
  TestRunner runner(output);
  LoggerTestListener listener;
  runner.AddListener(&listener);
  return runner.Run();
}
