/*
 * This file is part of the Winter 2025 edition of the
 * Introduction to Computer Science course taught at the
 * Guangdong Technion Israel Institute of Technology, Shantou, China
 * 
 * copyright (C) 2025 Valentin Cassano, Santiago Figueira, & Agustin Borda

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <strlib.h>
#include <array.h>

int len(str sentence) 
{
    int i = 0;

    while (sentence[i] != '\0')
    {
        i++;
    };

    return i;
}

int search(str sentence, int i, char c)
{
    int n = len(sentence);
    int k = i;
    int found = 0;

    while (k < n && !found)
    {
        found = (sentence[k] == c);
        k     = k+(1-found);
    };

    return k;
}

int str2nat(str sentence, int i, int j)
{
    int r = 0;
    int k = i;

    while (k < j)
    {
        r = 10*r + (sentence[k]-'0');
        k++;
    };

    return r;
}

str slice(str s, int start, int end) {
    int length = end - start;
    str result = new(char, length + 1); // +1 for '\0'
    for (int i = 0; i < length; i++) {
        result[i] = s[start + i];
    }
    result[length] = '\0'; // terminating symbol
    return result;
}