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

#include <AD8495.h>

AD8495::AD8495(uint8_t analogPin, uint16_t adcMaxValue, uint16_t numSamples, float adcRefV, float ampRefV)
{
    _analogPin = analogPin;
    _adcMaxValue = adcMaxValue;
    _numSamples = numSamples;
    _adcRefV = adcRefV;
    _ampRefV = ampRefV;
    pinMode(_analogPin, INPUT);
}

void AD8495::readADC()
{
    uint32_t adcValue = 0;
    for (uint16_t i = 0; i < _numSamples; i++) adcValue += analogRead(_analogPin);
    adcValue /= _numSamples;
    _voltage = (adcValue * _adcRefV) / _adcMaxValue;
    _celsius = (_voltage - _ampRefV) / 0.005;
    _fahrenheit = _celsius * 1.8 + 32.0;
}

float AD8495::readVoltage(void)
{
    readADC();
    return _voltage;
}

float AD8495::readCelsius(void)
{
    readADC();
    return _celsius;
}

float AD8495::readFahrenheit(void)
{
    readADC();
    return _fahrenheit;
}