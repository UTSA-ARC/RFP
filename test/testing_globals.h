#pragma once

#include <unity.h>

#include "globals.h"

#ifndef ARDUINO_TC

  #include <ArduinoFake.h>
  #define mock_arduino( method, return_value ) When( Method( ArduinoFake(), method ) ).AlwaysReturn( return_value )
  using namespace fakeit;

#else

  #include <Arduino.h>
  #define ARDUINO_TEST_DELAY 2000

#endif


void print_result( Result res );

void setUp( void );
void tearDown( void );
int runUnityTests( const void* tests, const uint8_t numTests );

#ifdef NATIVE_TC

  int main( void );

#endif

#ifdef ARDUINO_TC
  
  void setup();
  void loop();

#endif