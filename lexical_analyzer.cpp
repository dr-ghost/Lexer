#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "def.h"

using namespace std;

int main(int argc, char* argv[])
{
    string inpBuffer;
    string buffer;

    while (getline(cin, inpBuffer))
    {
        buffer += inpBuffer;
        buffer += '\n';
    }

    char *lexmebegin = &buffer[0];
    char *forward = &buffer[0];

    while (forward != &buffer[buffer.size()])
    {
        while (lexmebegin != &buffer[buffer.size()] && *lexmebegin == ' ')
        {
            lexmebegin++;
        }

        while (lexmebegin != &buffer[buffer.size()] && *lexmebegin == '\n')
        {
            lexmebegin++;
        }

        if (*lexmebegin == '/*')
        {
            while (forward != &buffer[buffer.size()] && *forward != '*/')
            {
                forward++;
            }

            if (forward == &buffer[buffer.size()])
            {
                cout << "Error: Comment not closed" << endl;
                return 0;
            }
        }
    }
}
