/*
 * AD8495 (https://github.com/laszlodaniel/AD8495)
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

#ifndef AD8495_H
#define AD8495_H

#include <Arduino.h>

class AD8495
{
    public:
        AD8495(uint8_t analogPin, uint16_t adcMaxValue = 1023, uint16_t numSamples = 128, float adcRefV = 5.0, float ampRefV = 1.25);
        float readVoltage(void);
        float readCelsius(void);
        float readFahrenheit(void);

    private:
        uint8_t _analogPin;
        uint16_t _adcMaxValue = 1023;
        uint16_t _numSamples = 128;
        float _adcRefV = 5.0;
        float _ampRefV = 1.25;
        float _voltage = 0;
        float _celsius = 0;
        float _fahrenheit = 0;
        void readADC();
};

#endif