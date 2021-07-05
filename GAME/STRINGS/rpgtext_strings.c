#include "rpgtext_strings.h"

char* remove_spaces(char* string)//Returns a malloced pointer with the minimum space needed to "save" the string; 
{
    char character_name[31];
    int x = 0, y = 0;
    while(string[x] == ' ')x++;//Erasing Initial Spaces
    while(string[x] != '\0')
    {
        if (!(string[x] == ' ' && string[x+1] == ' '))//If next char is a space, the while jumps to the next till find a non-space character
        {
            character_name[y] = string[x];
            y++;
        }
        x++;//If current and next char is a "space", we jump to the next char
    }
    character_name[y] = '\0'; //Terminates the string with atleast one space AKA ' ';
    x = strlen(character_name)-1; //"strlen(character_name) -1" Because  "strlen(character_name)" would return the '\0' Index on the string
    while(character_name[x] == ' '){character_name[x] = '\0'; x--;} //Erase spaces at the end, and the last char becomes a '\0' char

    return strdup(character_name); //Returns a malloced pointer with the minimum space needed to "save" the string; 
}
