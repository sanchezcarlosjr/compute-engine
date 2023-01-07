/* Flex generates the lexer. See Makefile. */
#include "lexer.c"
#include <string>
#include <sstream>
#include <emscripten/bind.h>
using namespace emscripten;

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
      analyze(text.c_str());
      std::ostringstream result;
      result << "\\text{The number of chars is }";
      result << get_chars();
      return result.str();
    }
private:
  int x;
  std::string y;
};


EMSCRIPTEN_BINDINGS(engine) {
  class_<Engine>("Engine")
    .constructor<int, std::string>()
    .property("x", &Engine::getX, &Engine::setX)
    .function("interpret", &Engine::interpret);
}
