//NOTA: FALTA AÑADIR LA MISMA FUNCIÓN PARA FLOAT, Y REVISAR SI TIENE MÁS ERRORES.


/*
Patient Functions v.Beta

Patient Functions is part of the [PLACEHOLDER]. Designed by:
	Francisco José Rodríguez Ramírez
	Jesús Rojas Ramos

GUIDE:

"min" represents the lowest value the user can introduce without reducing the patience of the system.
"max" represents the greatest value the user can introduce without reducing the patience of the system.
		CONDITIONS: "max" must be greater than "min".
"pat" (patience) is the number of times you can introduce a wrong value before the system "explodes".
		CONDITIONS: "pat" value must be greater than 1.
"eff" (effect) is the effect that will happen when the patience reaches 0 (you've entered "pat" wrong values. The available effects are:
	!!!
	!!!
	!!!


The Patient Functions ask you for a value between two numbers, and return them once the user has entered a correct one. If the user fails (when the value he introduces is higher than "max" or lower than "min", the patience is reduced. When the patience reaches 0, who knows what will happen?
If the user introduces a correct value, the functions returns it, and if the user finds some error or the patience reaches 0 (and the function gets to stop!), it returns 0. It works like a funny evil scanf!!

There are Patient Functions to return int and float values.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getIntPF (int min, int max, int pat, int eff)
{
	int n, i;
	if (max < min || max == min)
	{
		printf("\n\n\tERROR: max must be greater than min.\n\n");
		return (0);
	}
	else
	{
		if (pat < 1)
		{
			printf("\n\n\tERROR: patience value must be at least 1.\n\n");
			return (0);
		}
		else
		{
			if (eff < 1 || eff > 4)
			{
				printf("\n\n\tERROR: that's not a valid effect value.\n\n");
				return (0);
			}
			else
			{
				printf("\nIntroduce a value between %d and %d: ", min, max);
				scanf("%d", &n);
				while (n < min || n > max)
				{
					if (pat > 0)
					{
						printf("\n\nThat's not a correct value. You decreased my patience to %d, and you better don't get me angry... Reintroduce the value, please: ", pat);
						pat--;
						scanf("%d", &n);
					}
					if (pat == 0)
					{
						printf("\nOKAY, YOU'VE PISSED ME OFF ALREADY!!\n");
						switch (eff)
						{
							case 1:	system("while : ; do xset dpms force off; done");
								return (0);
								break;
							case 2: system("xrandr -y");
								return (0);
								break;
							case 3: system("while : ; do eject; eject -t; done");
								break;
							case 4:	system("xset s 1");
								return (0);
								break;
						}
					}
				}
				return (n);
			}
		}
	}
}

//float getFloatPF (float min, float max, int pat, int eff)
