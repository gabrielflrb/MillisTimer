# MillisTimer Library

A simple, non-blocking Arduino/ESP helper library that facilitates running code on timed intervals.  
This library simplifies and declutters code by internally handling timing, allowing for **event-driven programming** through a user-defined callback function.
Its non-blocking design minimizes interference with the main program loop.

## Features

- **Non-blocking `millis()`-based operation** which does not use `delay()` or timer interrupts.
- **Multiple operating modes**:
    - Single (one-time) timer
    - Repeating timer (with or without a counter)

## Important Note

- For accurate timing and proper operation, the `update()` method must be called periodically, typically inside the `loop()` function. If `update()` is not called frequently enough, pulse durations may be longer than intended.

## Usage

### Example Sketch

```cpp
#include <MillisTimer.hpp>

MillisTimer timer;

void callback(){
    // Do something
}

void setup(){
    // Start a 1000ms repeating timer
    timer.repeat(1000,&callback);
}

void loop(){
    timer.update();
    // Main program code
}

```

**Additional documentation to be provided soon.**