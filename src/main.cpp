#include "pros/rtos.h"
#include <cmath>
#include <cstdint>
#include <cstdio>
#include "main.h"

#define enter_critical() asm("cpsid i"); asm("dsb"); asm("isb")
#define exit_critical() asm("cpsie i"); asm("dsb"); asm("isb")

void initialize() {
    enter_critical();
    double r[1024];
    for (int i = 0; i < 1024; i++) r[i] = random();
    volatile double sink;  // Prevents compiler from optimizing away the result
    const uint64_t start = pros::c::micros();
    for (int j = 0; j < 10000; j++) {
        for (int k = 0; k < 1024; k++) {
            sink = sin(r[k]);  // Forces the result to be stored in a volatile variable
        }
    }
    const uint64_t delta = pros::c::micros() - start;
    exit_critical();
    printf("avg: %f \n", double(10000 * 1024) / double(delta));
}