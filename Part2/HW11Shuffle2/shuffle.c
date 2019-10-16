#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void printDeck(CardDeck deck)
{
	int ind;
	for (ind = 0; ind < deck.size; ind ++)
	{
		printf("%c ", deck.cards[ind]);
	}
	printf("\n");
}

void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
	for(int j=0; j < (origDeck.size - 1);j++)
	{
		strncpy(leftDeck[j].cards, origDeck.cards, j + 1);
		strncpy(rightDeck[j].cards, origDeck.cards + (j + 1), origDeck.size - j - 1);

		leftDeck[j].size = j + 1;
		rightDeck[j].size = origDeck.size - j - 1;
	}
}

void shuffleAgain(CardDeck origDeck, int i)
{
	if(i <= 0)
	{
		printDeck(origDeck);
		return;
	}
	shuffle(origDeck, i);
	return;
}

void help(CardDeck nDeck, CardDeck leftDeck, CardDeck rightDeck, int round)
{
	if(leftDeck.size == 0)
	{
		for(int k = 0; k < rightDeck.size; k++)
		{
			memcpy(&nDeck.cards[nDeck.size], &rightDeck.cards[k], 1);
			nDeck.size = nDeck.size + 1;
		}
		shuffleAgain(nDeck, round -1);
		return;
	}

	if(rightDeck.size == 0)
	{
		for(int y = 0; y < leftDeck.size; y++)
		{
			memcpy(&nDeck.cards[nDeck.size], &leftDeck.cards[y], 1);
			nDeck.size = nDeck.size + 1;
		}
		shuffleAgain(nDeck, round - 1);
		return;
	}

	CardDeck nleft;
	nleft.size = 0;

	CardDeck nDeckcopy;
	nDeckcopy.size = nDeck.size;

	for(int z = 0; z < nDeck.size; z++)
	{
		memcpy(&nDeckcopy.cards[z], &nDeck.cards[z], 1);
	}
	memcpy(&nDeckcopy.cards[nDeckcopy.size], &leftDeck.cards[0], 1);
	nDeckcopy.size += 1;

	for(int m = 1; m < leftDeck.size; m++)
	{
		memcpy(&nleft.cards[m - 1], &leftDeck.cards[m], 1);
		nleft.size += 1;
	}

	help(nDeckcopy, nleft, rightDeck, round);
	//
	CardDeck nright;
	nright.size = 0;

	CardDeck nDeckcopyB;
	nDeckcopyB.size = nDeck.size;

	for(int z = 0; z < nDeck.size; z++)
	{
		memcpy(&nDeckcopyB.cards[z], &nDeck.cards[z], 1);
	}
	memcpy(&nDeckcopyB.cards[nDeckcopyB.size], &rightDeck.cards[0], 1);
	nDeckcopyB.size += 1;

	for(int m = 1; m < rightDeck.size; m++)
	{
		memcpy(&nright.cards[m - 1], &rightDeck.cards[m], 1);
		nright.size += 1;
	}

	help(nDeckcopyB, leftDeck, nright, round);
}

void interleave(CardDeck leftDeck, CardDeck rightDeck, int round)
{
	CardDeck nDeck;
	nDeck.size = 0;
	help(nDeck, leftDeck, rightDeck, round);
}

void shuffle(CardDeck origDeck, int round)
{
	int numlr; 
	numlr = origDeck.size - 1;

	if(numlr == 0)
	{
		return;
	}

	CardDeck * leftDeck = NULL;
	CardDeck * rightDeck = NULL;

	leftDeck = malloc(numlr * sizeof(CardDeck));
	if(leftDeck == NULL)
	{
		return;
	}

	rightDeck = malloc(numlr * sizeof(CardDeck));
	if(rightDeck == NULL)
	{
		return;
	}

	divide(origDeck, leftDeck, rightDeck);

	for(int i = 0; i < numlr; i++)
	{
		interleave(leftDeck[i], rightDeck[i], round);
	}

	free(leftDeck);
	free(rightDeck);

}
