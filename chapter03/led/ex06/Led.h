#ifndef LED_H
#define LED_H

#pragma once

class Led
{
protected:
    // 멤버 변수
    int pin;

public:
    Led(int pin); // 생성자
    ~Led();       // 소멸자

private:
};

#endif