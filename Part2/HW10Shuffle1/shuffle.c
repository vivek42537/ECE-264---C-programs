// ***
// *** You must modify this file
// ***

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// do not modify this function
static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}

#ifdef TEST_DIVIDE
// leftDeck and rightDeck are arrays of CardDeck
// This function creates pairs of left and right decks
// Each pair divides the original deck into two non-overlapping decks and
// together they form the original deck.
//
// You can think of the left deck held by the left hand taking some
// cards (at least one) from the top of the original deck.
//
// The right deck is held by the right hand taking some (at least one)
// cards from the bottom of the original deck.
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
#endif

#ifdef TEST_INTERLEAVE

// Interleave two decks to generate all possible results.
//
// If the leftDeck is {'A'} and the right deck is {'2', '3'}, this
// function prints
// A 2 3
// 2 A 3
// 2 3 A
//
// If the leftDeck is {'A', '2'} and the right deck is {'3', '4'}, this
// function prints 
// 3 4 A 2
// 3 A 4 2
// A 3 4 2 
// 3 A 2 4 
// A 3 2 4 
// A 2 3 4 
//
// Please notice the space does not matter because grading will use
// diff -w
//
// How to generate all possible interleaves?

// Understand that a card at a particular position can come from
// either left or right (two options). The following uses left for
// explanation but it is equally applicable to the right.
//
// After taking one card from the left deck, the left deck has one
// fewer card. Now, the problem is the same as the earlier problem
// (thus, this problem can be solved by using recursion), excecpt one
// left card has been taken. Again, the next card can come from left
// or right.
//
// This process continues until either the left deck or the right deck
// runs out of cards. The remaining cards are added to the result.
// 
// It is very likely that you want to create a "helper" function that
// can keep track of some more arguments.  If you create a helper
// function, please keep it inside #ifdef TEST_INTERLEAVE and #endif
// so that the function can be removed for grading other parts of the
// program.
void help(CardDeck nDeck, CardDeck leftDeck, CardDeck rightDeck)
{
 if(leftDeck.size == 0)
 {
  for(int k = 0; k < rightDeck.size; k++)
  {
   memcpy(&nDeck.cards[nDeck.size], &rightDeck.cards[k], 1);
   nDeck.size = nDeck.size + 1;
  }
  printDeck(nDeck);
  return;
 }
 
 if(rightDeck.size == 0)
 {
  for(int y = 0; y < leftDeck.size; y++)
  {
   memcpy(&nDeck.cards[nDeck.size], &leftDeck.cards[y], 1);
   nDeck.size = nDeck.size + 1;
  }
  printDeck(nDeck);
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
 
 help(nDeckcopy, nleft, rightDeck);
 
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

 help(nDeckcopyB, leftDeck, nright);

}
 void interleave(CardDeck leftDeck, CardDeck rightDeck)
 {
  CardDeck nDeck;
  nDeck.size = 0;
  help(nDeck, leftDeck, rightDeck);
 }




#endif

#ifdef TEST_SHUFFLE
// The shuffle function has the following steps:

// 1. calculate the number of possible left and right decks. It is
// the number of cards - 1 because the left deck may have 1, 2,...,
// #cards - 1 cards.
//
// 2. allocate memory to store these possible pairs of left and right
// decks.
//
// 3. send each pair to the interleave function
//
// 4. release allocated memory
//
void shuffle(CardDeck origDeck)
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
 rightDeck = malloc(numlr * sizeof(CardDeck));

 divide(origDeck, leftDeck, rightDeck);
 
 for(int i = 0; i < numlr; i++)
 {
  interleave(leftDeck[i], rightDeck[i]);
 }
 
 free(leftDeck);
 free(rightDeck);
 
}
#endif







