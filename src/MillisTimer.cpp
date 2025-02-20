/*
 * MillisTimer Library
 * 
 * Copyright (c) 2025 Gabriel Bernardes
 *
 * Licensed under the MIT License. See LICENSE file in the project root for more details.
 */

#include "MillisTimer.hpp"

void MillisTimer::_start(const bool fin){
    _finite = fin;
    resetMillis(); 
    _running = true;
}

void MillisTimer::_trigger(){
    if (_finite){
        if (--_counter == 0)
            stop();
    }
    
    resetMillis();
    _callCallback();
}

void MillisTimer::single(){
    _counter = 1;
    _start(true);
}

void MillisTimer::repeat(){
    _start(false);
}

void MillisTimer::repeatX(uint16_t times){
    if (times == 0)
        return;
    _counter = times;
    _start(true);
}

bool MillisTimer::update(){
    if(_running && hasTriggered()){
        _trigger();
        return true;
    }
    return false;
}