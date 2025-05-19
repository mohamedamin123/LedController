#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include <Arduino.h>

class LedController {
public:
    LedController(int pin, float intensity = 0.0, String color = "Inconnu");

    void allumer();
    void arret();
    void changeIntensite(float intensity);
    void toggle();

    float getIntensite() const;
    String getColor() const;
    bool isOn() const;

private:
    int _pin;
    float _intensity;
    String _color;
    bool _isOn;

    void appliquerIntensite();
};

#endif
