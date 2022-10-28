#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;


// Find the location of the first occurrence of pattern in text
// or say that it does not occur if that is the case.
// If you find the pattern in the text, output the index of the
// first letter in text where the pattern first occurs.

// You must also print the total number of character compairsons that
// the program made.

// If the number of unchecked characters in the text is ever less than
// the length of the pattern the algorithm must stop.

// NOTE:  All test texts and patterns should not contain any white space
//        (e.g. blank space character, newline, tab, etc.) as scanf
//        will stop on such an input character.






int main()
{
  char text[10000] ;
  char pattern[200] ;
  int m,n ;

  printf("enter text : ") ;
  scanf("%s", text) ;
  printf("enter pattern you are searching for : ") ;
  scanf("%s", pattern) ;

  m = strlen(pattern) ;
  n = strlen(text) ;
  printf("The pattern has %d characters and the text has %d characters.\n", m,n) ;





  int arr[128];
  for(int i = 0; i < 128; ++i){
    arr[i] = m;
  }

  arr[pattern[m-1]] = m;
  for(int i = m - 1, j = 0; i > 0; --i, ++j){
    arr[pattern[j]] = i;
  }

  int startPoint = m - 1;
  bool success = false;
  int found = 0;
  int totalCompares = 0;

  while(startPoint < n && !success){
    for(int a = m-1, b = startPoint; a >= 0; --a, --b){
      ++totalCompares;
      if(pattern[a] != text[b]) break;
      if(a == 0){
        success = true;
        found = b;
      }
    }
    
    startPoint += arr[text[startPoint]];
  }

  if(success) printf("The pattern was found at index %d, with %d comparisons.\n", found, totalCompares);
  else printf("Pattern not found. Used %d comparisons.\n", totalCompares);



  return 0;
}


  


