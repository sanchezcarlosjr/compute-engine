# My first compiler (aka calculator)
My first compiler (aka calculator) using Programming -- Principles and Practice Using C++ Stroustrup
https://calculator.sanchezcarlosjr.com/

# Prerequisites
1. Firebase CLI
2. clang
3. wasm-ld

# Installation
1.
```
git clone https://github.com/sanchezcarlosjr/my-first-compiler-aka-calculator.git
```

2. 
```
make
```
3. 
```
make start
```

4. 
```
Visit localhost:5000
```
5. 
```
Have fun!
```

# Testing
Sometimes if you don't want manual testing, you would like [Google Test Framework](https://google.github.io/googletest/quickstart-cmake.html).
1. 
```
cmake -S . -B build
```
2. Why do you compile every time? No, make saves your time. You should have installed [when-changed](https://github.com/joh/when-changed)  
```
make live-testing
```
