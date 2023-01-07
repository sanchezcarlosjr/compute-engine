#include "engine.cpp"
#include <emscripten/bind.h>
using namespace emscripten;

EMSCRIPTEN_BINDINGS(engine) {
  class_<Engine>("Engine")
    .constructor<int, std::string>()
    .property("x", &Engine::getX, &Engine::setX)
    .function("interpret", &Engine::interpret);
}
