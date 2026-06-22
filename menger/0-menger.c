#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge
 * @level: The level of the Menger Sponge to draw
 */
void menger(int level)
{
	int size, row, col, r, c;
	char character;

	if (level < 0)
		return;

	/* Calculate the total size of the grid: 3^level */
	size = pow(3, level);

	/* Iterate through every cell of the grid */
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			character = '#';
			r = row;
			c = col;

			/* Check if the current cell falls in the empty center of any 3x3 block */
			while (r > 0 || c > 0)
			{
				if (r % 3 == 1 && c % 3 == 1)
				{
					character = ' ';
					break;
				}
				r /= 3;
				c /= 3;
			}
			putchar(character);
		}
		putchar('\n');
	}
}
