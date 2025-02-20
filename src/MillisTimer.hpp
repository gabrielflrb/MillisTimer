/*
 * MillisTimer Library
 * 
 * Copyright (c) 2025 Gabriel Bernardes
 *
 * Licensed under the MIT License. See LICENSE file in the project root for more details.
 */

#ifndef MILLISCALLBACK_HPP
#define MILLISCALLBACK_HPP

#include <Arduino.h>


class MillisTimer{
    typedef void (*cb_func_t)();
    private:
        uint32_t _dur = 0;
        cb_func_t _cb = nullptr;
        uint32_t _prevMillis = 0;
        uint16_t _counter = 0;
        bool _running = false;
        bool _finite = false;

        inline void _callCallback(){ if (_cb != nullptr) _cb(); } 

        void _trigger();

        void _start(const bool fin);
    public: 
        
        MillisTimer(){}
        MillisTimer(uint32_t dur) : _dur(dur) {}
        MillisTimer(uint32_t dur, cb_func_t callback) : _dur(dur), _cb(callback) {}

        void setCallback(cb_func_t callback) { _cb = callback; }
        // void setInterval(uint32_t interval) { _interval = interval;}

        void resetMillis() { _prevMillis = millis();};

        void single();
        void single(uint32_t dur){ _dur = dur; single(); }
        void single(uint32_t dur, cb_func_t cb) { _dur = dur, _cb = cb, single(); }

        void repeat();
        void repeat(uint32_t dur) { _dur = dur; repeat(); };
        void repeat(uint32_t dur, cb_func_t cb) { _dur = dur; _cb = cb; repeat(); };

        void repeatX(uint16_t times);
        void repeatX(uint16_t times, uint32_t dur) {_dur = dur, repeatX(times); };
        void repeatX(uint16_t times, uint32_t dur, cb_func_t cb) {_dur = dur, _cb = cb; repeatX(times); };

        void stop()  { _running = false; }

        bool hasTriggered(){ return millis() - _prevMillis > _dur; }

        bool update();
};

#endif // MILLISCALLBACK_HPP