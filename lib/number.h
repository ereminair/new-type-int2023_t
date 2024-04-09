#pragma once
#include <cinttypes>
#include <iostream>

const int SIZE = 31;
const int BASE = 1000000000;
const int MAX_LEN_DIGIT = 9;

struct int2023_t {
    int32_t Digits[SIZE] = {0};
    int StartIndex = 0;
    bool IsNegative = false;
};

static_assert(sizeof(int2023_t) <= 253, "Size of int2023_t must be no higher than 253 bytes");

int2023_t from_int(int32_t i);

int2023_t from_string(const char* buff);

int2023_t operator+(const int2023_t& lhs, const int2023_t& rhs);

int2023_t operator-(const int2023_t& lhs, const int2023_t& rhs);

int2023_t operator*(const int2023_t& lhs, const int2023_t& rhs);

int2023_t operator/(const int2023_t& lhs, const int2023_t& rhs);

bool operator==(const int2023_t& lhs, const int2023_t& rhs);

bool operator>(const int2023_t& lhs, const int2023_t& rhs);

bool operator>=(const int2023_t& lhs, const int2023_t& rhs);

bool operator<(const int2023_t& lhs, const int2023_t& rhs);

bool operator<=(const int2023_t& lhs, const int2023_t& rhs);

bool operator!=(const int2023_t& lhs, const int2023_t& rhs);

int2023_t ShiftRight(int2023_t x);

std::ostream& operator<<(std::ostream& stream, const int2023_t& value);
