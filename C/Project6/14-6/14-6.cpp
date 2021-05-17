#include <stdio.h>
#include <stdlib.h>
#include "../input.h"

struct softball_player
{
	char first_name[128];
	char last_name[128];
	int times;
	int hits;
	int run;
	int rbi;
	double hit_rate;
};

int main(void)
{
	struct softball_player players[19] = { {'\0','\0', 0, 0, 0, 0, 0.0} };
	struct softball_player player = {'\0','\0', 0, 0, 0, 0, 0.0 };
	FILE* fp;
	char file_name[128];
	int play_num;

	printf("Please enter file name:");
	s_gets(file_name, 128);
	if ((fp = fopen(file_name, "r")) == NULL)
	{
		printf("Can't open the %s.\n", file_name);
		exit(EXIT_FAILURE);
	}

	while (feof(fp) == 0)
	{
		fscanf(fp, "%d", &play_num);
		fscanf(fp, "%s", &player.last_name);
		fscanf(fp, "%d", &player.first_name);
		fscanf(fp, "%d", &player.times);
		fscanf(fp, "%d", &player.hits);
		fscanf(fp, "%d", &player.run);
		fscanf(fp, "%d", &player.rbi);

		if (players[play_num].first_name == '\0')
			players[play_num] = player;
		else
		{
			players[play_num].hits += player.hits;
			players[play_num].rbi += player.rbi;
			players[play_num].run += player.run;
			players[play_num].times += player.times;
		}
	}

	for (int i = 0; i < 19; i++)
	{
		if (players[i].first_name != '\0')
		{
			players[i].hit_rate = (double)players[i].hits / players[i].times;
		}
	}

	for (int i = 0; i < 19; i++)
	{
		if (players[i].first_name[0] != '\0')
		{
			printf("Player:%s %s, play times: %d, hit times: %d, run barrier times: %d, rbi: %d, hit_rate: %.2lf\n",
				players[i].first_name, players[i].last_name, players[i].times, players[i].hits, players[i].run, players[i].rbi,
				players[i].hit_rate);
		}
	}

	fclose(fp);

	return 0;
}