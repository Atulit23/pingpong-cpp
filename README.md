#  WebAssembly Pong Game

This is a simple **Pong game** built using **C++** and **WebAssembly (WASM)**, rendered on an **HTML5 Canvas**.  
The game logic is implemented in C++ and compiled to WebAssembly using **Emscripten**.

---

## ** Setup and Installation**

### **1️. Install Emscripten SDK (emsdk)**  
First, **clone and install** the Emscripten SDK:  

```bash
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh  # (Linux/macOS)
emsdk_env.bat  # (Windows)
emcc game.cpp -o game.js -s EXPORTED_FUNCTIONS='["_updateGame", "_movePaddle", "_getBallX", "_getBallY", "_getPaddle1Y", "_getPaddle2Y"]' -s EXPORTED_RUNTIME_METHODS='["cwrap"]' -s MODULARIZE=1 -s ENVIRONMENT=web -O3
```

