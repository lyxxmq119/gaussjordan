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

double str2dou(str sentence, int i, int j) {
    int k = i;
    double sign = 1.0;
    
    if (k < j && sentence[k] == '-') {
        sign = -1.0;
        k++;
    } else if (k < j && sentence[k] == '+') {
        k++;
    }
    
    int dot_pos = search(sentence, k, '.');
    
    double result = 0.0;
    
    if (dot_pos >= j) {
        result = (double)str2nat(sentence, k, j);
    } else {
        int int_part = 0;
        if (dot_pos > k) {
            int_part = str2nat(sentence, k, dot_pos);
        }
        
        double dec_part = 0.0;
        if (dot_pos + 1 < j) {
            int fraction = str2nat(sentence, dot_pos + 1, j);
            int len_frac = j - (dot_pos + 1);
            
            double divisor = 1.0;
            for(int p = 0; p < len_frac; p++) {
                divisor *= 10.0;
            }
            dec_part = fraction / divisor;
        }
        result = (double)int_part + dec_part;
    }
    
    return result * sign;
}