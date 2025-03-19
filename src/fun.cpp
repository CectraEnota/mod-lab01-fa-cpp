// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    unsigned int cnt = 0;
    bool inWord = false;
    bool hasDigit = false;

    for (; *str; ++str) {
        if (isspace(*str)) {
            if (inWord && !hasDigit) {
                ++cnt;
            }
            inWord = false;
            hasDigit = false;
        }
        else {
            inWord = true;
            if (isdigit(*str)) {
                hasDigit = true;
            }
        }
    }

    if (inWord && !hasDigit) {
        ++cnt;
    }

    return cnt;
}

unsigned int faStr2(const char *str) {
    unsigned int cnt = 0;
    bool inWord = false;
    bool capitaLetter = false;
    bool rightWord = true;

    for (; *str; ++str) {
        if (isspace(*str)) {
            if (inWord && capitaLetter && rightWord) {
                ++cnt;
            }
            inWord = false;
            capitaLetter = false;
            rightWord = true;
        }
        else {
            if (!inWord) {
                inWord = true;
                capitaLetter = isupper(*str);
            }
            if (inWord && !islower(*str) && !isupper(*str)) {
                rightWord = false;
            }
        }
    }

    if (inWord && capitaLetter && rightWord) {
        ++cnt;
    }
    return cnt;
}

unsigned int faStr3(const char *str) {
    unsigned int minLength = -1;
    unsigned int curLenght = 0;
    bool inWord = false;
    for (; *str; ++str) {
        if (isspace(*str) && inWord) {
            if (curLenght < minLength) {
                minLength = curLenght;
            }
            curLenght = 0;
            inWord = false;
        }
        else if (!isspace(*str)) {
            inWord = true;
            ++curLenght;
        }
    }
    if (inWord && (curLenght < minLength)) {
        minLength = curLenght;
    }
    return static_cast<unsigned int>(round(minLength));
}
