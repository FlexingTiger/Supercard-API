/*
 * This file is part of the DS communication library for the Supercard DSTwo.
 *
 * Copyright 2017 Nebuleon Fumika <nebuleon.fumika@gmail.com>
 *
 * It is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * It is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with it.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <stdlib.h>

void* bsearch(const void* key, const void* base, size_t n, size_t size,
	int (*comparison) (const void*, const void*))
{
	size_t lo = 0, hi = n;

	while (lo != hi) {
		size_t i = lo + (hi - lo) / 2;
		void* element = (uint8_t*) base + i * size;

		/* The first argument when called from bsearch shall equal key.
		 * - C99 */
		int order = (*comparison) (key, element);
		if (order < 0)
			hi = i;
		else if (order > 0)
			lo = i + 1;
		else
			return element;
	}

	return NULL;
}
