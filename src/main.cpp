#include "pros/rtos.h"
#include <cstdint>
#include <stdio.h>
#include <math.h>
#include "main.h"

// macros to enter / exit critical section
#define enter_critical() asm volatile("cpsid i\n\tdsb\n\tisb")
#define exit_critical() asm volatile("cpsie i\n\tdsb\n\tisb")
#define CONSUME(x) asm volatile("" :: "r,m" (x))

// constants
constexpr int array_length = 1024;
constexpr int num_tests = 20000;

void test_pow() {
// announce start of program
    pros::c::delay(1000);
    printf("\nstarting... \n");
    pros::c::delay(50);

    // generate random numbers
    double array[array_length];
    double brray[array_length];
    for (int i = 0; i < array_length; i++) {
        array[i] = random();
        brray[i] = random();
    }
    printf("done generating random numbers... \n");
    pros::c::delay(50);

    // run the computations
    enter_critical();
    const uint64_t start = pros::c::micros();
    for (int i = 0; i < num_tests; i++) {
        for (int j = 0; j < array_length; j++) {
            double cpp_makes_me_sad = pow(array[j], brray[j]);
            CONSUME(cpp_makes_me_sad);
        }
    }
    const uint64_t current = pros::c::micros();
    exit_critical();

    // announce computation results
    const uint64_t duration = current - start;
    printf("pow:\n");
    printf("Number of tests: %i \n", num_tests * array_length);
    printf("Duration of tests: %lli \n", duration);
    printf("computations per microsecond: %f \n", double(num_tests * array_length) / double(duration));
}

void test_hypot() {
// announce start of program
    pros::c::delay(1000);
    printf("\nstarting... \n");
    pros::c::delay(50);

    // generate random numbers
    double array[array_length];
    double brray[array_length];
    for (int i = 0; i < array_length; i++) {
        array[i] = random();
        brray[i] = random();
    }
    printf("done generating random numbers... \n");
    pros::c::delay(50);

    // run the computations
    enter_critical();
    const uint64_t start = pros::c::micros();
    for (int i = 0; i < num_tests; i++) {
        for (int j = 0; j < array_length; j++) {
            double cpp_makes_me_sad = hypot(array[j], brray[j]);
            CONSUME(cpp_makes_me_sad);
        }
    }
    const uint64_t current = pros::c::micros();
    exit_critical();

    // announce computation results
    const uint64_t duration = current - start;
    printf("hypot:\n");
    printf("Number of tests: %i \n", num_tests * array_length);
    printf("Duration of tests: %lli \n", duration);
    printf("computations per microsecond: %f \n", double(num_tests * array_length) / double(duration));
}

void test_exp() {
// announce start of program
    pros::c::delay(1000);
    printf("\nstarting... \n");
    pros::c::delay(50);

    // generate random numbers
    double array[array_length];
    for (int i = 0; i < array_length; i++) array[i] = random();
    printf("done generating random numbers... \n");
    pros::c::delay(50);

    // run the computations
    enter_critical();
    const uint64_t start = pros::c::micros();
    for (int i = 0; i < num_tests; i++) {
        for (int j = 0; j < array_length; j++) {
            double cpp_makes_me_sad = exp(array[j]);
            CONSUME(cpp_makes_me_sad);
        }
    }
    const uint64_t current = pros::c::micros();
    exit_critical();

    // announce computation results
    const uint64_t duration = current - start;
    printf("exp:\n");
    printf("Number of tests: %i \n", num_tests * array_length);
    printf("Duration of tests: %lli \n", duration);
    printf("computations per microsecond: %f \n", double(num_tests * array_length) / double(duration));
}

void test_log() {
// announce start of program
    pros::c::delay(1000);
    printf("\nstarting... \n");
    pros::c::delay(50);

    // generate random numbers
    double array[array_length];
    for (int i = 0; i < array_length; i++) array[i] = random();
    printf("done generating random numbers... \n");
    pros::c::delay(50);

    // run the computations
    enter_critical();
    const uint64_t start = pros::c::micros();
    for (int i = 0; i < num_tests; i++) {
        for (int j = 0; j < array_length; j++) {
            double cpp_makes_me_sad = log(array[j]);
            CONSUME(cpp_makes_me_sad);
        }
    }
    const uint64_t current = pros::c::micros();
    exit_critical();

    // announce computation results
    const uint64_t duration = current - start;
    printf("log:\n");
    printf("Number of tests: %i \n", num_tests * array_length);
    printf("Duration of tests: %lli \n", duration);
    printf("computations per microsecond: %f \n", double(num_tests * array_length) / double(duration));
}

void test_log10() {
// announce start of program
    pros::c::delay(1000);
    printf("\nstarting... \n");
    pros::c::delay(50);

    // generate random numbers
    double array[array_length];
    for (int i = 0; i < array_length; i++) array[i] = random();
    printf("done generating random numbers... \n");
    pros::c::delay(50);

    // run the computations
    enter_critical();
    const uint64_t start = pros::c::micros();
    for (int i = 0; i < num_tests; i++) {
        for (int j = 0; j < array_length; j++) {
            double cpp_makes_me_sad = log10(array[j]);
            CONSUME(cpp_makes_me_sad);
        }
    }
    const uint64_t current = pros::c::micros();
    exit_critical();

    // announce computation results
    const uint64_t duration = current - start;
    printf("log10:\n");
    printf("Number of tests: %i \n", num_tests * array_length);
    printf("Duration of tests: %lli \n", duration);
    printf("computations per microsecond: %f \n", double(num_tests * array_length) / double(duration));
}

void test_sin() {
// announce start of program
    pros::c::delay(1000);
    printf("\nstarting... \n");
    pros::c::delay(50);

    // generate random numbers
    double array[array_length];
    for (int i = 0; i < array_length; i++) array[i] = random();
    printf("done generating random numbers... \n");
    pros::c::delay(50);

    // run the computations
    enter_critical();
    const uint64_t start = pros::c::micros();
    for (int i = 0; i < num_tests; i++) {
        for (int j = 0; j < array_length; j++) {
            double cpp_makes_me_sad = sin(array[j]);
            CONSUME(cpp_makes_me_sad);
        }
    }
    const uint64_t current = pros::c::micros();
    exit_critical();

    // announce computation results
    const uint64_t duration = current - start;
    printf("sin:\n");
    printf("Number of tests: %i \n", num_tests * array_length);
    printf("Duration of tests: %lli \n", duration);
    printf("computations per microsecond: %f \n", double(num_tests * array_length) / double(duration));
}

void test_cos() {
// announce start of program
    pros::c::delay(1000);
    printf("\nstarting... \n");
    pros::c::delay(50);

    // generate random numbers
    double array[array_length];
    for (int i = 0; i < array_length; i++) array[i] = random();
    printf("done generating random numbers... \n");
    pros::c::delay(50);

    // run the computations
    enter_critical();
    const uint64_t start = pros::c::micros();
    for (int i = 0; i < num_tests; i++) {
        for (int j = 0; j < array_length; j++) {
            double cpp_makes_me_sad = cos(array[j]);
            CONSUME(cpp_makes_me_sad);
        }
    }
    const uint64_t current = pros::c::micros();
    exit_critical();

    // announce computation results
    const uint64_t duration = current - start;
    printf("cos:\n");
    printf("Number of tests: %i \n", num_tests * array_length);
    printf("Duration of tests: %lli \n", duration);
    printf("computations per microsecond: %f \n", double(num_tests * array_length) / double(duration));
}

void test_tan() {
// announce start of program
    pros::c::delay(1000);
    printf("\nstarting... \n");
    pros::c::delay(50);

    // generate random numbers
    double array[array_length];
    for (int i = 0; i < array_length; i++) array[i] = random();
    printf("done generating random numbers... \n");
    pros::c::delay(50);

    // run the computations
    enter_critical();
    const uint64_t start = pros::c::micros();
    for (int i = 0; i < num_tests; i++) {
        for (int j = 0; j < array_length; j++) {
            double cpp_makes_me_sad = tan(array[j]);
            CONSUME(cpp_makes_me_sad);
        }
    }
    const uint64_t current = pros::c::micros();
    exit_critical();

    // announce computation results
    const uint64_t duration = current - start;
    printf("tan:\n");
    printf("Number of tests: %i \n", num_tests * array_length);
    printf("Duration of tests: %lli \n", duration);
    printf("computations per microsecond: %f \n", double(num_tests * array_length) / double(duration));
}

void test_asin() {
// announce start of program
    pros::c::delay(1000);
    printf("\nstarting... \n");
    pros::c::delay(50);

    // generate random numbers
    double array[array_length];
    for (int i = 0; i < array_length; i++) array[i] = random();
    printf("done generating random numbers... \n");
    pros::c::delay(50);

    // run the computations
    enter_critical();
    const uint64_t start = pros::c::micros();
    for (int i = 0; i < num_tests; i++) {
        for (int j = 0; j < array_length; j++) {
            double cpp_makes_me_sad = asin(array[j]);
            CONSUME(cpp_makes_me_sad);
        }
    }
    const uint64_t current = pros::c::micros();
    exit_critical();

    // announce computation results
    const uint64_t duration = current - start;
    printf("asin:\n");
    printf("Number of tests: %i \n", num_tests * array_length);
    printf("Duration of tests: %lli \n", duration);
    printf("computations per microsecond: %f \n", double(num_tests * array_length) / double(duration));
}

void test_acos() {
// announce start of program
    pros::c::delay(1000);
    printf("\nstarting... \n");
    pros::c::delay(50);

    // generate random numbers
    double array[array_length];
    for (int i = 0; i < array_length; i++) array[i] = random();
    printf("done generating random numbers... \n");
    pros::c::delay(50);

    // run the computations
    enter_critical();
    const uint64_t start = pros::c::micros();
    for (int i = 0; i < num_tests; i++) {
        for (int j = 0; j < array_length; j++) {
            double cpp_makes_me_sad = acos(array[j]);
            CONSUME(cpp_makes_me_sad);
        }
    }
    const uint64_t current = pros::c::micros();
    exit_critical();

    // announce computation results
    const uint64_t duration = current - start;
    printf("acos:\n");
    printf("Number of tests: %i \n", num_tests * array_length);
    printf("Duration of tests: %lli \n", duration);
    printf("computations per microsecond: %f \n", double(num_tests * array_length) / double(duration));
}

void test_atan() {
// announce start of program
    pros::c::delay(1000);
    printf("\nstarting... \n");
    pros::c::delay(50);

    // generate random numbers
    double array[array_length];
    for (int i = 0; i < array_length; i++) array[i] = random();
    printf("done generating random numbers... \n");
    pros::c::delay(50);

    // run the computations
    enter_critical();
    const uint64_t start = pros::c::micros();
    for (int i = 0; i < num_tests; i++) {
        for (int j = 0; j < array_length; j++) {
            double cpp_makes_me_sad = atan(array[j]);
            CONSUME(cpp_makes_me_sad);
        }
    }
    const uint64_t current = pros::c::micros();
    exit_critical();

    // announce computation results
    const uint64_t duration = current - start;
    printf("atan:\n");
    printf("Number of tests: %i \n", num_tests * array_length);
    printf("Duration of tests: %lli \n", duration);
    printf("computations per microsecond: %f \n", double(num_tests * array_length) / double(duration));
}

void test_atan2() {
// announce start of program
    pros::c::delay(1000);
    printf("\nstarting... \n");
    pros::c::delay(50);

    // generate random numbers
    double array[array_length];
    double brray[array_length];
    for (int i = 0; i < array_length; i++) {
        array[i] = random();
        brray[i] = random();
    }
    printf("done generating random numbers... \n");
    pros::c::delay(50);

    // run the computations
    enter_critical();
    const uint64_t start = pros::c::micros();
    for (int i = 0; i < num_tests; i++) {
        for (int j = 0; j < array_length; j++) {
            double cpp_makes_me_sad = atan2(array[j], brray[j]);
            CONSUME(cpp_makes_me_sad);
        }
    }
    const uint64_t current = pros::c::micros();
    exit_critical();

    // announce computation results
    const uint64_t duration = current - start;
    printf("atan2:\n");
    printf("Number of tests: %i \n", num_tests * array_length);
    printf("Duration of tests: %lli \n", duration);
    printf("computations per microsecond: %f \n", double(num_tests * array_length) / double(duration));
}

void initialize() {
    test_pow();
    test_hypot();
    test_exp();
    test_log();
    test_log10();
    test_sin();
    test_cos();
    test_tan();
    test_asin();
    test_acos();
    test_atan();
    test_atan2();
}
