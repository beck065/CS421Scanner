#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: ** 
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA 
// Done by: Adam Beck
// RE:   (vowel | vowel n | consonant vowel | consonant vowel n | consonant-pair vowel | consonant-pair vowel n)^+
bool word (string s)
{

  int state = 0;
  int charpos = 0;
  enum States { q0, q1, qsa, qy, qt, qs, qc, q0q1, q0qy}; // enums for easier state transitions
  
  while (s[charpos] != '\0') 
    {
      // states for q0
      if (state == q0 && s[charpos] == 'V')
      state = q0;
      else
      if (state == q0 && s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j')
      state = qsa;
      else
      if (state == q0 && s[charpos] == 's')
      state = qs;
      else
      if (state == q0 && s[charpos] == 't')
      state = qt;
      else
      if (state == q0 && s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r')
      state = qy;
      else
      if (state == q0 && s[charpos] == 'c')
      state = qc;
      else
      // states for q1
      if (state == q1 && s[charpos] == 'n')
      state = q0;
      else
      // states for qsa
      if (state == qsa && s[charpos] == 'V')
      state = q0q1;
      else
      // states for qy
      if (state == qy && s[charpos] == 'V')
      state = q0;
      else
      if (state == qy && s[charpos] == 'y')
      state = qsa;
      else
      // states for qt
      if (state == qt && s[charpos] == 'V')
      state = q0q1;
      else
      if (state == qt && s[charpos] == 's')
      state = qsa;
      else
      // states for qs
      if (state == qs && s[charpos] == 'V')
      state = q0q1;
      else
      if (state == qs && s[charpos] == 'h')
      state = qsa;
      else
      // states for qc
      if (state == qc && s[charpos] == 'h')
      state = qsa;
      else
      // states for q0q1
      if (state == q0q1 && s[charpos] == 'V')
      state = q0q1;
      else
      if (state == q0q1 && s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j')
      state = qsa;
      else
      if (state == q0q1 && s[charpos] == 's')
      state = qs;
      else
      if (state == q0q1 && s[charpos] == 't')
      state = qt;
      else
      if (state == q0q1 && s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'p' || s[charpos] == 'r')
      state = qy;
      else
      if (state == q0q1 && s[charpos] == 'c')
      state = qc;
      else
      if (state == q0q1 && s[charpos] == 'n')
      state = q0qy;
      else
      // states for q0qy
      if (state == q0qy && s[charpos] == 'V')
      state = q0q1;
      else
      if (state == q0qy && s[charpos] == ' ')
      state = qsa;
      else
      if (state == q0qy && s[charpos] == 's')
      state = qs;
      else
      if (state == q0qy && s[charpos] == 't')
      state = qt;
      else
      if (state == q0qy && s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r')
      state = qy;
      else
      if (state == q0qy && s[charpos] == 'c')
      state = qc;
      else
      if (state == q0qy && s[charpos] == 'y')
      state = qsa;
      else
	    return(false);
      charpos++;
    }//end of while

  // where did I end up????
  if (state == q0 || state == q0q1 || state == q0qy) return(true);  // end in a final states
   else return(false);

}

// PERIOD DFA 
// Done by: Adam Beck
bool period (string s)
{ 
  int state = 0;
  int charpos = 0;

  if (state == 0 && s[charpos] == '.')
  return(true);
  else
  return(false);
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: **

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype {ERROR, };

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = { }; 

// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.


// ------------ Scanner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: 
int scanner(tokentype& tt, string& w)
{

  // ** Grab the next word from the file via fin
  // 1. If it is eofm, return right now.   
  
  /*  **
  2. Call the token functions (word and period) 
     one after another (if-then-else).
     Generate a lexical error message if both DFAs failed.
     Let the tokentype be ERROR in that case.

  3. If it was a word,
     check against the reservedwords list.
     If not reserved, tokentype is WORD1 or WORD2
     decided based on the last character.

  4. Return the token type & string  (pass by reference)
  */

}//the end of scanner



// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!! 
// Done by:  Louis
int main()
{
  tokentype thetype;
  string theword; 
  string filename;

  cout << "Enter the input file name: ";
  cin >> filename;

  fin.open(filename.c_str());

  // the loop continues until eofm is returned.
   while (true)
    {
       scanner(thetype, theword);  // call the scanner which sets
                                   // the arguments  
       if (theword == "eofm") break;  // stop now

       cout << "Type is:" << tokenName[thetype] << endl;
       cout << "Word is:" << theword << endl;   
    }

   cout << "End of file is encountered." << endl;
   fin.close();

}// end

