#pragma once

#include <cinttypes>
#include <cmath>

#include "../../AgiInterpreter.h"

class ArithmeticCommands
{
public:
	static void increment(uint8_t variableID);
	static void decrement(uint8_t variableID);
	static void assignn(uint8_t variableID, uint8_t number);
	static void assignv(uint8_t variableID1, uint8_t variableID2);
	static void addn(uint8_t variableID, uint8_t number);
	static void addv(uint8_t variableID1, uint8_t variableID2);
	static void subn(uint8_t variableID, uint8_t number);
	static void subv(uint8_t variableID1, uint8_t variableID2);
	static void lindirectn(uint8_t variableID, uint8_t number);
	static void lindirectv(uint8_t variableID1, uint8_t variableID2);
	static void rindirect(uint8_t variableID, uint8_t number);
	static void muln(uint8_t variableID, uint8_t number);
	static void mulv(uint8_t variableID1, uint8_t variableID2);
	static void divn(uint8_t variableID, uint8_t number);
	static void divv(uint8_t variableID1, uint8_t variableID2);
	static void random(uint8_t variableID, uint8_t number, uint8_t k);
};