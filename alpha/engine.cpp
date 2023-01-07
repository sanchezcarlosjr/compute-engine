/* Flex generates the lexer. See Makefile. */
#include "lexer.c"
#include <string>
#include <sstream>

/*
https://emscripten.org/docs/porting/connecting_cpp_and_javascript/Interacting-with-code.html#interacting-with-code-binding-cpp
*/
class Engine {
public:
  Engine(int x, std::string y)
  : x(x),
    y(y)
    {}
  int getX() const { return x; }
  void setX(int x_) { x = x_; }

    std::string interpret(std::string text) {
      std::ostringstream result;
      result << "\\text{Result is }";
      result << analyze(text.c_str());
      return result.str();
    }
private:
  int x;
  std::string y;
};