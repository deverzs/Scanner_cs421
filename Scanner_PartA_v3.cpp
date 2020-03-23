#include<iostream>
#include<fstream>
#include<string>
using namespace std;


//=====================================================                                                                                                                                                     
// File scanner.cpp written by: Group Number: 18                                                                                                                                                            
//Alaa Ahmed                                                                                                                                                                                                
//Maria Baranova                                                                                                                                                                                            
//Zsuzsanna Dianovics                                                                                                                                                                                       
//=====================================================                                                                                                                                                     

// --------- Two DFAs ---------------------------------                                                                                                                                                     

// WORD DFA                                                                                                                                                                                                 
// Done by: Alaa                                                                                                                                                                                            
// RE:  (vowel | vowel n | consonant vowel | consonant vowel n | consonant-pair vowel | consonant-pair vowel n)^+                                                                                           
// Comments by Maria                                                                                                                                                                                        
bool word(string s) //boolian function that has to check if word is valid or not                                                                                                                            
{
	string state = "q0"; //string that we will be comparing                                                                                                                                                   
	int charpos = 0;
	//replace the following todo the word dfa  DONE                                                                                                                                                           
	while (s[charpos] != '\0') //while loop will work if we have a word                                                                                                                                       
	{
		//in all of those if and else statements we will be checking orders of letters in word and by the 
		//roles we have we will be able to identify if it is a valid word or not                              
		if (state == "q0" && (s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' ||
			s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r' || s[charpos] == 'g' || s[charpos] == 'n'))
			state = "qy"; //bmkhprgn                                                                                                                                                                            
		else if (state == "q0" && s[charpos] == 'c')
			state = "qc"; //c                                                                                                                                                                                   
		else if (state == "q0" && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u'
			|| s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
			state = "q0q1"; //vowel                                                                                                                                                                             
		else if (state == "q0" && s[charpos] == 't')
			state = "qt"; //t                                                                                                                                                                                   
		else
			if (state == "q0" && s[charpos] == 's')
				state = "qs"; //s                                                                                                                                                                                 
			else
				if (state == "q0" && (s[charpos] == 'd' || s[charpos] == 'w' ||
					s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
					state = "qsa"; //dwzyj                                                                                                                                                                          

				else if (state == "qy" && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' ||
					s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
					state = "q0q1"; //vowel                                                                                                                                                                         
				else
					if (state == "qy" && s[charpos] == 'y')
						state = "qsa"; //y                                                                                                                                                                            
					else
						if (state == "qc" && s[charpos] == 'h')
							state = "qsa"; //h                                                                                                                                                                          
						else
							if (state == "q0qy" && s[charpos] == 'c')
								state = "qc"; //c                                                                                                                                                                         
							else
								if (state == "q0qy" && s[charpos] == 't')
									state = "qt"; //t                                                                                                                                                                       
								else
									if (state == "q0qy" && s[charpos] == 's')
										state = "qs"; //s                                                                                                                                                                     
									else
										if (state == "q0qy" && (s[charpos] == 'd' || s[charpos] == 'w' ||
											s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
											state = "qsa"; //dwzyj                                                                                                                                                              
										else
											if (state == "q0qy" && (s[charpos] == 'a' || s[charpos] == 'i' ||
												s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' ||
												s[charpos] == 'I' || s[charpos] == 'E'))
												state = "q0q1"; //vowel                                                                                                                                                           
											else
												if (state == "q0qy" && (s[charpos] == 'b' || s[charpos] == 'm' ||
													s[charpos] == 'k' || s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r' ||
													s[charpos] == 'g' || s[charpos] == 'n'))
													state = "qy"; //bmkhprgn                                                                                                                                                        

												else
													if (state == "qt" && s[charpos] == 's')
														state = "qsa"; //s                                                                                                                                                            
													else
														if (state == "qt" && (s[charpos] == 'a' || s[charpos] == 'i' ||
															s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' ||
															s[charpos] == 'I' || s[charpos] == 'E'))
															state = "q0q1"; //vowel                                                                                                                                                     
														else
															if (state == "qs" && (s[charpos] == 'a' || s[charpos] == 'i' ||
																s[charpos] == 'u' || s[charpos] == 'e' ||
																s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
																state = "q0q1"; //vowel                                                                                                                                                   
															else
																if (state == "qs" && s[charpos] == 'h')
																	state = "qsa"; //h                                                                                                                                                      
																else
																	if (state == "qsa" && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' ||
																		s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
																		state = "q0q1"; //vowel                                                                                                                                               


																	else
																		if (state == "q0q1" && (s[charpos] == 'b' || s[charpos] == 'm' ||
																			s[charpos] == 'k' || s[charpos] == 'h' ||
																			s[charpos] == 'p' || s[charpos] == 'r' || s[charpos] == 'g'))
																			state = "qy"; //bmkhprg                                                                                                                                             
																		else
																			if (state == "q0q1" && s[charpos] == 'c')
																				state = "qc"; //c                                                                                                                                                 
																			else
																				if (state == "q0q1" && s[charpos] == 'n')
																					state = "q0qy"; //n                                                                                                                                             
																				else
																					if (state == "q0q1" && s[charpos] == 't')
																						state = "qt"; //t                                                                                                                                             
																					else
																						if (state == "q0q1" && s[charpos] == 's')
																							state = "qs"; //s                                                                                                                                           
																						else
																							if (state == "q0q1" && (s[charpos] == 'd' || s[charpos] == 'w' ||
																								s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
																								state = "qsa"; //dwzyj                                                                                                                                    
																							else
																								if (state == "q0q1" && (s[charpos] == 'a' || s[charpos] == 'i' ||
																									s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' ||
																									s[charpos] == 'I' || s[charpos] == 'E'))//                                                                                        
																									state = "q0q1"; //vowel                                                                                                                                 

																								else
																									return(false); //we exit if non of the rules were aplyed                                                                                                
		charpos++; //have more charectors                                                                                                                                                                     
	}//end of while                                                                                                                                                                                         

  // where did I end up????                                                                                                                                                                                 
	if (state == "q0" || state == "q0qy" || state == "q0q1") return(true);  // end in a final state                                                                                                           
	else return(false);

}

// PERIOD DFA                                                                                                                                                                                               
// Done by: Maria       
// RE: (.)                                                                                                                                                                                   
// Comment by: Maria                                                                                                                                                                                        
bool period(string s)
{  // complete this **                                                                                                                                                                                      
	if (s == ".") {
		return true;
	}

  else {
  false;
  }
}

// ------ Three  Tables -------------------------------------                                                                                                                                               

// TABLES Done by: Alaa                                                                                                                                                                                     

// Tokentype enum                                                                                                                                                                                           
enum tokentype { ERROR, WORD1, WORD2, PERIOD, EOFM, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR };

// TokenName                                                                                                                                                                                                
string tokenName[30] = { "ERROR", "WORD1", "WORD2", "PERIOD", "EOFM", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR" };

// Reserved Words                                                                                                                                                                                           
string reservedWords[19] = { "masu", "masen", "mashita", "masendeshita", "desu", "deshita", "o", "wa", "ni", "watashi", "anata", "kare", "kanojo", "sore", "mata", "soshite", "shikashi", "dakara", "eofm" \
};
//check for reserved word prototype                                                                                                                                                                         
bool reserved(std::string& w, tokentype& tt);

// ------------ Scanner and Driver -----------------------      
ifstream fin;  // global stream for reading from the input file                                                                                                                                             

// Scanner processes only one word each time it is called                                                                                                                                                   
// Gives back the token type and the word itself                                                                                                                                                            
// Done by: Alaa and Zsuzsanna                                                                                                                                                                             
// Comment by Maria and Zsuzsanna                                                                                                                                                                           
//                                                                                                                                                                                                          
/*Algorithm:
  0. reads next word
  1. If it is eofm, return right now
  2. Else if it is a word
  if reserved word, set the tt reference
  if last character of w is a|e|i|o|u|n
  tt = WORD1
  if last character is I|E
  tt = WORD2
  3. Else if it is a period
  4. Else if it is an error
  5. return the token type
*/
int scanner(tokentype& tt, string& w)
{
	// Grab the next word from the file via fin                                                                                                                                                               
	fin >> w;

	// 1. If it is eofm, return right now.                                                                                                                                                                    
	if (w == "eofm")
	{
		tt = EOFM;
	}
	//2. Else if it is a word                                                                                                                                                                                 
	else if (word(w) == true)
	{
		char lastCh = w[w.size() - 1];

		//if reserved word, set the tt                                                                                                                                                                        
		if (reserved(w, tt)) {}

		//WORD1                                                                                                                                                                                               
		//if last character of w is a|e|i|o|u|n                                                                                                                                                               
		else if (lastCh == 'a' || lastCh == 'o' || lastCh == 'n' ||
			lastCh == 'e' || lastCh == 'i' || lastCh == 'u')
		{
			tt = WORD1;
		}
		//WORD2                                                                                                                                                                                               
		//if last character is I|E                                                                                                                                                                            
		else if (lastCh == 'I' || lastCh == 'E')
		{
			tt = WORD2;
		}

	}
	//3. Else if it is a period                                                                                                                                                                               
	else if (period(w) == true)
	{
		tt = PERIOD;
	}
	//4. Else if it is an error                                                                                                                                                                               
	else
	{
		cout << ">>>>>Lexical Error: The string is not in my language\n";
		tt = ERROR;
	}

	//return the token type                                                                                                                                                                                   
	return tt;

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
	filename = "C:\\Users\\Small\\Desktop\\cs421_TheoryComp\\ScannerFiles\\scannertest1";
	fin.open(filename.c_str());

	// the loop continues until eofm is returned.                                                                                                                                                             
	while (true)
	{
		scanner(thetype, theword);  // call the scanner which sets                                                                                                                                            
		// the arguments                                                                                                                                                                                      
		if (theword == "eofm") break;  // stop now                                                                                                                                                            


		cout << "\"" << theword << " \" is ";
		cout << "token type " << tokenName[thetype] << endl << endl;
	}

	cout << "End of file is encountered." << endl;
	fin.close();

}// end                                                                                                                                                                                                     

// Reserved checks the word for being reserved                                                                                                                                                              
// Returns true or false and sets the tokenType                                                                                                                                                             
// Done by: Zsuzsanna and Maria                                                                                                                                                                              
//Comment by: Maria                                                                                                                                                                                         
bool reserved(std::string& w, tokentype& tt)
{
	//check reserved words                                                                                                                                                                                    
	string reservedWord;
	bool foundIt = false; //making boolian statement to be false                                                                                                                                              
   //set foundIt for reserved word                                                                                                                                                                           
	for (int i = 0; i < 19; i++) //go in to loop and check for other conditions in it until we reach 19 words                                                                                                 
	{
		//we are cheking in those if and else statments wat tipe of word that is                                                                                                                              
		if (w == reservedWords[i])
		{
			reservedWord = reservedWords[i];
			if (reservedWord == "masu") {
				tt = VERB;
				foundIt = true;
			}
			else if (reservedWord == "masen") {
				tt = VERBNEG;
				foundIt = true;
			}
			else if (reservedWord == "mashita") {
				tt = VERBPAST;
				foundIt = true;
			}
			else if (reservedWord == "masendeshita") {
				tt = VERBPASTNEG;
				foundIt = true;
			}
			else if (reservedWord == "desu") {
				tt = IS;
				foundIt = true;
			}
			else if (reservedWord == "deshita") {
				tt = WAS;
				foundIt = true;
			}
			else if (reservedWord == "o") {
				tt = OBJECT;
				foundIt = true;
			}
			else if (reservedWord == "wa") {
				tt = SUBJECT;
				foundIt = true;
			}
			else if (reservedWord == "ni") {
				tt = DESTINATION;
				foundIt = true;
			}
			else if (reservedWord == "watashi" || reservedWord == "anata" || reservedWord == "kare" || reservedWord == "kanojo" || reservedWord == "sore") {
				tt = PRONOUN;
				foundIt = true;
			}
			else if (reservedWord == "mata" || reservedWord == "soshite" || reservedWord == "shikashi" || reservedWord == "dakara") {
				tt = CONNECTOR;
				foundIt = true;
			}
		}
	}// end set foundIt                                                                                                                                                                                     

	return foundIt;
}

