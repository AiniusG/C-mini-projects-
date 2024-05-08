#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED

#include <stdbool.h>

#define MAX_DALYKAI 28

bool dfs(int graph[][MAX_DALYKAI], int dalyku_kiekis, int start_dalykas, int tikrinamas_dalykas, bool aplankyti[]);

bool ar_yra_tranzityvi_priklausomybe(int graph[][MAX_DALYKAI], int dalykas1, int dalykas2, int dalyku_kiekis);

#endif
