#include "LedController.h"

// Création de l'objet LedController sur la broche 9, intensité initiale 0 (éteint), couleur "blanc"
LedController led(9, 0.0, "blanc");

void setup() {
  Serial.begin(9600);
  Serial.println("Test LedController");

  // Allume la LED à 100%
  led.allumer();
  Serial.println("LED allumée à 100%");
  delay(2000);

  // Baisse progressivement l'intensité de 100% à 0%
  for (float i = 1.0; i >= 0; i -= 0.05) {
    led.changeIntensite(i);
    Serial.print("Intensité : ");
    Serial.println(i);
    delay(100);
  }

  // Éteint la LED
  led.arret();
  Serial.println("LED éteinte");
}

void loop() {
  // Clignotement simple toutes les 2 secondes
  led.toggle();
  Serial.print("LED état : ");
  Serial.println(led.isOn() ? "Allumée" : "Éteinte");
  delay(2000);
}
