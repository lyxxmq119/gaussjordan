/*
 * This file is part of the Winter 2025 edition of the
 * Introduction to Computer Science course taught at the
 * Guangdong Technion Israel Institute of Technology, Shantou, China
 * 
 * copyright (C) 2025 Valentin Cassano & Santiago Figueira

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

#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <strlib.h>

#define arr(content_type__) \
    content_type__*

#define new(content_type__, size) \
    (arr(content_type__))malloc((size)*sizeof(content_type__))

arr(int) build(arr(str) array, int n);

void printa(arr(int) a, int n);
void printda(arr(double) a, int n);

arr(double) build_double(str s, int n);
// require: s contains n space-separated real numbers
// ensure: result contains the n parsed numbers in order

#endif
