#include "LedController.h"

LedController::LedController(int pin, float intensity, String color) {
    _pin = pin;
    _color = color;
    _intensity = 0.0;
    _isOn = false;
    pinMode(_pin, OUTPUT);

    changeIntensite(intensity);  // applique intensité initiale
}

void LedController::allumer() {
    _intensity = 1.0;
    appliquerIntensite();
    _isOn = true;
}

void LedController::arret() {
    _intensity = 0.0;
    appliquerIntensite();
    _isOn = false;
}

void LedController::changeIntensite(float intensity) {
    if (intensity < 0.0) intensity = 0.0;
    if (intensity > 1.0) intensity = 1.0;

    _intensity = intensity;
    appliquerIntensite();

    _isOn = (_intensity > 0);
}

void LedController::toggle() {
    if (_isOn) {
        arret();
    } else {
        allumer();
    }
}

float LedController::getIntensite() const {
    return _intensity;
}

String LedController::getColor() const {
    return _color;
}

bool LedController::isOn() const {
    return _isOn;
}

void LedController::appliquerIntensite() {
    int pwmValue = (int)(255 * _intensity);
    analogWrite(_pin, pwmValue);
}
