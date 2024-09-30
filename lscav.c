// MIT License

// Copyright (c) 2024 Nikola Kipariz Stamov

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

void print_usage()
{
    printf("\nUsage: ./lscav [-u users] [-g groups]\n\n");
    exit(2);
}

int main(int argc, char** argv)

{

    if (argc < 2) {
        print_usage();
        exit(1);
    }

    opterr = 0; // No Default Error Message

    int option;

    int uflag = 0, gflag = 0, dflag = 0; // Argument Flags

    while ((option = getopt(argc, argv, "ug")) != -1)

    {

        switch (option)

        {

        case 'u':
            if (uflag) {
            } else {
                uflag++;
                printf("\n[USER_LIST]\n");
            }
            break;

        case 'g':
            if (gflag) {
            } else {
                gflag++;
                printf("\n[GROUP_LIST]\n");
            }
            break;

        default:
            if (dflag) {
            } else {
                dflag++;
                printf("\n---\n\nWARNING: Option was not recognized or used: %c\n", optopt);
                // redirect to Global Variable
            }
        }
    }

    printf("\n");

    return 0;
}
