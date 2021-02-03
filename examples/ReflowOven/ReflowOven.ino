/*
 * ReflowOven example of the AD8495 library (https://github.com/laszlodaniel/AD8495)
 * Copyright (C) 2021, Daniel Laszlo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <AD8495.h>

#define TC_PIN        A0     // must be analog input pin
#define ADC_MAX_VALUE 1023   // 10-bit ADC, 2^10 - 1 = 1023
#define ADC_SAMPLES   128    // ADC sample count
#define ADC_REF_V     5.0886 // supply voltage, the more accurate the better
#define AMP_REF_V     1.239  // reference voltage measured on the amplifier breakout board, nominally 1.25V, but the more accurate the better

uint32_t previousMillis = 0;
uint32_t currentMillis = 0;
uint16_t interval = 1000; // ms
float ovenTemperature = 0;

AD8495 thermocouple(TC_PIN, ADC_MAX_VALUE, ADC_SAMPLES, ADC_REF_V, AMP_REF_V);

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    currentMillis = millis();

    if ((uint32_t)(currentMillis - previousMillis) >= interval)
    {
        previousMillis = currentMillis;
        ovenTemperature = thermocouple.readCelsius();
        Serial.print("T=");
        Serial.print(ovenTemperature, 1);
        Serial.println("°C");
    }
}
