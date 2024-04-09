#include "number.h"
#include <cstring>
#include <cmath>
#include <algorithm>

int2023_t from_int(int32_t i) {
    int2023_t a;
    a.Digits[0] = i % BASE;
    a.Digits[1] = i / BASE;
    if (i > BASE - 1) {
        a.StartIndex = 1;
    } else {
        a.StartIndex = 0;
    }
    return a;
}

int2023_t from_string(const char *buff) {
    int2023_t a;
    std::string s = "";
    bool is_negative = false;
    if (buff[0] == '-') {
        is_negative = true;
        buff++;
    }
    for (int i = strlen(buff) - 1; i >= 0; --i) {
        s += buff[i];
        if (s.size() == MAX_LEN_DIGIT || i == 0) {
            std::reverse(s.begin(), s.end());
            int32_t b = stoi(s);
            a.Digits[a.StartIndex] = b;
            a.StartIndex++;
            s = "";
        }
    }
    a.StartIndex--;
    if (is_negative) {
        a.IsNegative = true;
    }
    return a;
}

int2023_t operator+(const int2023_t& lhs, const int2023_t& rhs) {
    int2023_t res;
    int32_t c = 0;
    bool is_negative = false;
    if (lhs.IsNegative && rhs.IsNegative) {
        for (int i = 0; i <= std::max(lhs.StartIndex, rhs.StartIndex) + 1; ++i) {
            int32_t temp = lhs.Digits[i] + rhs.Digits[i] + c;
            res.Digits[i] = temp % BASE;
            c = temp / BASE;
            res.StartIndex = i;
        }
        is_negative = true;
    } else if (lhs.IsNegative && !rhs.IsNegative) {
        for (int i = 0; i <= std::max(lhs.StartIndex, rhs.StartIndex) + 1; ++i) {
            int32_t temp;
            if (lhs.Digits[i] < rhs.Digits[i] + c) {
                temp = (lhs.Digits[i] + BASE) - (rhs.Digits[i] + c);
                c = 1;
            } else {
                temp = lhs.Digits[i] - rhs.Digits[i] - c;
                c = 0;
            }
            res.Digits[i] = temp % BASE;
            res.StartIndex = i;
        }
        is_negative = true;
    } else if (!lhs.IsNegative && rhs.IsNegative) {
        for (int i = 0; i <= std::max(lhs.StartIndex, rhs.StartIndex) + 1; ++i) {
            int32_t temp;
            if (lhs.Digits[i] < rhs.Digits[i] + c) {
                temp = (lhs.Digits[i] + BASE) - (rhs.Digits[i] + c);
                c = 1;
            } else {
                temp = lhs.Digits[i] - rhs.Digits[i] - c;
                c = 0;
            }
            res.Digits[i] = temp % BASE;
            res.StartIndex = i;
        }
    } else {
        for (int i = 0; i <= std::max(lhs.StartIndex, rhs.StartIndex) + 1; ++i) {
            int32_t temp = lhs.Digits[i] + rhs.Digits[i] + c;
            res.Digits[i] = temp % BASE;
            c = temp / BASE;
            res.StartIndex = i;
        }
    }
    if (is_negative) {
        res.IsNegative = true;
    }
    if (res.Digits[res.StartIndex] == 0)
        res.StartIndex--;
    return res;
}

int2023_t operator-(const int2023_t& lhs, const int2023_t& rhs) {
    int2023_t res;
    int32_t c = 0;
    bool is_negative = false;
    if ((lhs.IsNegative && rhs.IsNegative)) {
        if(lhs >= rhs)
        {
            for (int i = 0; i <= std::max(lhs.StartIndex, rhs.StartIndex) + 1; ++i) {
                int32_t temp;
                if (lhs.Digits[i] < rhs.Digits[i] + c) {
                    temp = (lhs.Digits[i] + BASE) - (rhs.Digits[i] + c);
                    c = 1;
                } else {
                    temp = lhs.Digits[i] - rhs.Digits[i] - c;
                    c = 0;
                }
                res.Digits[i] = temp % BASE;
                res.StartIndex = i;
            }
            is_negative = true;
        } else {
            for (int i = 0; i <= std::max(lhs.StartIndex, rhs.StartIndex) + 1; ++i) {
                int32_t temp;
                if (lhs.Digits[i] < rhs.Digits[i] + c) {
                    temp = (rhs.Digits[i] + BASE) - (lhs.Digits[i] + c);
                    c = 0;
                } else {
                    temp = rhs.Digits[i] - lhs.Digits[i] - c;
                    c = 1;
                }
                res.Digits[i] = temp % BASE;
                res.StartIndex = i;
            }
        }

    } else if (lhs.IsNegative && !rhs.IsNegative) {
        for (int i = 0; i <= std::max(lhs.StartIndex, rhs.StartIndex) + 1; ++i) {
            int32_t temp = lhs.Digits[i] + rhs.Digits[i] + c;
            res.Digits[i] = temp % BASE;
            c = temp / BASE;
            res.StartIndex = i;
        }
        is_negative = true;
    } else if (!lhs.IsNegative && rhs.IsNegative) {
        for (int i = 0; i <= std::max(lhs.StartIndex, rhs.StartIndex) + 1; ++i) {
            int32_t temp = lhs.Digits[i] + rhs.Digits[i] + c;
            res.Digits[i] = temp % BASE;
            c = temp / BASE;
            res.StartIndex = i;
        }
    } else {
        if(lhs >= rhs)
        {
            for (int i = 0; i <= std::max(lhs.StartIndex, rhs.StartIndex) + 1; ++i) {
                int32_t temp;
                if (lhs.Digits[i] < rhs.Digits[i] + c) {
                    temp = (lhs.Digits[i] + BASE) - (rhs.Digits[i] + c);
                    c = 1;
                } else {
                    temp = lhs.Digits[i] - rhs.Digits[i] - c;
                    c = 0;
                }
                res.Digits[i] = temp % BASE;
                res.StartIndex = i;
            }
        } else {
            for (int i = 0; i <= std::max(lhs.StartIndex, rhs.StartIndex) + 1; ++i) {
                int32_t temp;
                if (lhs.Digits[i] > rhs.Digits[i] + c) {
                    temp = (lhs.Digits[i] + BASE) - (rhs.Digits[i] + c);
                    c = 1;
                } else {
                    temp = lhs.Digits[i] - rhs.Digits[i] - c;
                    c = 0;
                }
                res.Digits[i] = temp % BASE;
                res.StartIndex = i;
            }
        }

    }

    if (is_negative) {
        res.IsNegative = true;
    }
    if (res.Digits[res.StartIndex] == 0)
        res.StartIndex--;
    return res;
}

int2023_t operator*(const int2023_t& lhs, const int2023_t& rhs) {
    int2023_t res;
    int64_t c = 0;
    int64_t temp;
    bool is_negative = false;
    if (lhs.IsNegative != rhs.IsNegative) {
        is_negative = true;
    }
    for (int i = 0; i <= lhs.StartIndex; ++i) {
        for (int j = 0; j <= rhs.StartIndex || c; ++j) {
            if (j > rhs.StartIndex) {
                temp = (int64_t) res.Digits[i + j] + (int64_t) (c);
            } else {
                temp =
                        (int64_t) (lhs.Digits[i]) * (int64_t) (rhs.Digits[j]) + (int64_t) (c) + (int64_t) (res.Digits[i + j]);
            }
            c = temp / BASE;
            res.Digits[i + j] = temp % BASE;
        }
    }
    if (is_negative) {
        res.IsNegative = true;
    }
    for (int i = SIZE - 1; i >= 0; i--) {
        if (res.Digits[i] != 0) {
            res.StartIndex = i;
            break;
        }
    }
    return res;
}

int2023_t ShiftRight(int2023_t x) {
    int2023_t result;
    for (int i = 0; i <= x.StartIndex; ++i) {
        result.Digits[i + 1] = x.Digits[i];
    }
    result.StartIndex = x.StartIndex + 1;
    return result;
}

int2023_t operator/(const int2023_t& lhs, const int2023_t& rhs) {
    int2023_t result, current;
    bool is_negative = false;
    if (lhs.IsNegative != rhs.IsNegative) {
        is_negative = true;
    }
    for (int i = lhs.StartIndex; i >= 0; --i) {
        current = ShiftRight(current);
        current.Digits[0] = lhs.Digits[i];
        for (int j = SIZE - 1; j >= 0; --j) {
            if (current.Digits[j] != 0) {
                current.StartIndex = j;
                break;
            }
        }
        int32_t x = 0, l = 0, r = BASE - 1;
        while (l <= r) {
            int32_t m = (l + r) / 2;
            int2023_t t = rhs * from_int(m);
            if (t <= current) {
                x = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        result.Digits[i] = x;
        current = current - rhs * from_int(x);
    }
    if (is_negative) {
        result.IsNegative = true;
    }
    for (int i = SIZE - 1; i >= 0; --i) {
        if (result.Digits[i] != 0) {
            result.StartIndex = i;
            break;
        }
    }
    return result;
}

bool operator<(const int2023_t& lhs, const int2023_t& rhs) {
    if (lhs == rhs) {
        return false;
    }
    if (lhs.StartIndex != rhs.StartIndex) {
        return lhs.StartIndex < rhs.StartIndex;
    } else {
        for (int i = lhs.StartIndex; i >= 0; --i) {
            if (lhs.Digits[i] != rhs.Digits[i]) {
                return lhs.Digits[i] < rhs.Digits[i];
            }
        }
        return false;
    }
}

bool operator>=(const int2023_t& lhs, const int2023_t& rhs) {
    if (!(lhs < rhs)) {
        return true;
    } else {
        return false;
    }
}

bool operator>(const int2023_t& lhs, const int2023_t& rhs) {
    if ((lhs >= rhs && lhs != rhs)) {
        return true;
    } else {
        return false;
    }
}

bool operator<=(const int2023_t& lhs, const int2023_t& rhs) {
    if ((lhs < rhs || lhs == rhs)) {
        return true;
    } else {
        return false;
    }
}

bool operator==(const int2023_t& lhs, const int2023_t& rhs) {
    bool t = true;
    if (lhs.StartIndex == rhs.StartIndex) {
        for (int i = 0; i < std::size(lhs.Digits); ++i) {
            if (lhs.Digits[i] != rhs.Digits[i]) {
                t = false;
            }
        }
    } else {
        t = false;
    }
    if (t) {
        return true;
    } else {
        return false;
    }
}

bool operator!=(const int2023_t& lhs, const int2023_t& rhs) {
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& stream, const int2023_t& value) {
    std::string s;
    if (value.IsNegative) {
        s += "-";
    }
    for (int i = 0; i <= value.StartIndex; ++i) {
        if (std::to_string(value.Digits[i]).size() < MAX_LEN_DIGIT && i != value.StartIndex) {
            std::string st = "";
            for (int j = 0; j < MAX_LEN_DIGIT - std::to_string(value.Digits[i]).size(); ++j)
                st += '0';
            s = st + std::to_string(value.Digits[i]) + s;
            st = "";
        } else {
            s += std::to_string(value.Digits[i]);
        }
    }
    stream << s;
    return stream;
}
