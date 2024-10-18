// MIT License

// Copyright (c) 2024 Nikola Kipariz Stamov

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#include <getopt.h>
#include <pwd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <unistd.h>

/// All Function Prototypes ///

void print_usage();

void kernel_info();

void all_users();
void regular_users();

/// Main Function ///

int main(int argc, char **argv)

{
    opterr = 0; // No Default Error Message (getopt)

    int option = 0, uflag = 0, rflag = 0, dflag = 0, kflag = 0, tflag = 0;

    // All values set to 0

    // If there are no arguments, print the default usage message and exit

    if (argc < 2)
    {
        print_usage();
        exit(1);
    }

    // Argument Flags (Including Default Flag)

    char str[80]; // Default Message

    while ((option = getopt(argc, argv, "-:kurt")) != -1)

    {
        switch (option)

        {
        case 'k':
            if (kflag)
            {
            }
            else
            {
                kflag++;
                printf("\n");
                kernel_info();
            }
            break;

        case 't':
            if (tflag)
            {
            }
            else
            {
                printf("\n[TEMPORARY]\n");
            }
            break;

        case 'u':
            if (uflag)
            {
            }
            else
            {
                uflag++;
                printf("\n");
                all_users();
            }
            break;

        case 'r':
            if (rflag)
            {
            }
            else
            {
                rflag++;
                regular_users();
            }
            break;

        default:
            if (dflag)
            {
            }
            else
            {
                dflag++;
                snprintf(str, 80, "\n---\n\nWARNING: Bad input detected! -%c\n", optopt);
            }
        }
    }

    puts(str); // Print the unrecognized option if any exist

    return 0;
}

/// All Function Definitions ///

void print_usage()
{
    // Print Usage Function

    printf ("\nUsage: ./lscav \n\n");
    printf ("	[-u List All Users] \n");
    printf ("	[-r List Regular Users Only] \n");
    printf ("	[-k List Available Kernel Information] \n");
    printf ("	[-t testing_temporary]");
}

void kernel_info()
{
    // Kernel Information Function

    printf("--- Kernel Information --- \n\n");

    struct utsname uts;

    if (uname(&uts) < 0)
        perror("uname() error");
    else
    {
        printf("OS              : %s\n", uts.sysname);
        printf("Hostname        : %s\n", uts.nodename);
        printf("Release         : %s\n", uts.release);
        printf("Version         : %s\n", uts.version);
        printf("Architecture    : %s\n", uts.machine);
    }
}

void regular_users()
{
    printf("\n--- Regular User List ---\n\n");

    struct passwd *p_single;

    uid_t uid = 1000; // Start Point for Regular Users

    while ((p_single = getpwuid(uid)) != NULL)
    {

        printf("Username        : %s\n", p_single->pw_name);
        printf("UID             : %d\n", (int)p_single->pw_uid);
        printf("GID             : %d\n", (int)p_single->pw_gid);
        printf("Home Directory  : %s\n", p_single->pw_dir);
        printf("Default Shell   : %s\n", p_single->pw_shell);
        printf("Information     : %s\n", p_single->pw_gecos);
        printf("\n");
        uid++;
    }
}

void all_users()

{
    printf("\n--- Full User List ---\n\n");

    struct passwd *p_loop;

    while ((p_loop = getpwent()) != NULL)
    {
        printf("Username        : %s\n", p_loop->pw_name);
        printf("UID             : %d\n", (int)p_loop->pw_uid);
        printf("GID             : %d\n", (int)p_loop->pw_gid);
        printf("Home Directory  : %s\n", p_loop->pw_dir);
        printf("Default Shell   : %s\n", p_loop->pw_shell);
        printf("Information     : %s\n", p_loop->pw_gecos);
        printf("\n");
    }
}
