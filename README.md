# wasm-rock-paper-scissors

Proof of concept web game made with C++ and WebAssembly

## Compiling C++ into Wasm

I used [Emscripten](https://emscripten.org/docs/getting_started/downloads.html#platform-notes-installation-instructions-sdk) to compile the C++ code into WebAssembly.
If you change `rock_paper_scissors.cpp` file you will need to have Emscripten installed in order to re-compile and generate the assets once again. Follow the installation steps in the link.

In order to compile the C++ file run:
```sh
emcc rock_paper_scissors.cpp -o rock_paper_scissors.js \
    -s EXPORTED_FUNCTIONS='["_playGame"]' \
    -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' \
    -s MODULARIZE=1 -s EXPORT_ES6=1 -s ENVIRONMENT=web
```

This will generate:

- rock_paper_scissors.wasm → WebAssembly binary
- rock_paper_scissors.js → JavaScript glue code

## Serving locally

To serve the app locally you can simply

```sh
python3 -m http.server 8080
```

Then, open http://localhost:8080 in your browser.
