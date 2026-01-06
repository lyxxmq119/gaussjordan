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

#ifndef STRLIB_H
#define STRLIB_H

typedef char* str;

int len(str);
// ensure: len(str) = the number of symbols in the string

int search(str sentence, int i, char c);
// require: i in [0:len(s))
// ensure: c in s[i:len(s)) => output is the least j s.t. j>=i and s[j]=c
//         c not in s[i:len(s)) => output = len(s) 

int str2nat(str sentence, int i, int j);
// require: s[i:j) represents a number n
// ensure: output = n

double str2dou(str sentence, int i, int j);
// require: sentence[i:j] represents a real number in decimal format
// ensure: result is the numeric value of the substring sentence[i:j]

#endif
