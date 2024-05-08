#include "DFS.h"
#include <stdbool.h>

#define MAX_DALYKAI 28

bool dfs(int graph[][MAX_DALYKAI], int dalyku_kiekis, int start_dalykas, int tikrinamas_dalykas, bool aplankyti[])
{
    aplankyti[tikrinamas_dalykas] = true;

    for (int i = 0; i < dalyku_kiekis; i++)
    {
        if (graph[tikrinamas_dalykas][i] && !aplankyti[i])
        {
            if (i == start_dalykas)
                return true;

            if (dfs(graph, dalyku_kiekis, start_dalykas, i, aplankyti))
                return true;
        }
    }
    return false;
}

bool ar_yra_tranzityvi_priklausomybe(int graph[][MAX_DALYKAI], int dalykas1, int dalykas2, int dalyku_kiekis)
{
    bool aplankyti[MAX_DALYKAI] = {false};
    return dfs(graph, dalyku_kiekis, dalykas1, dalykas2, aplankyti);
}
