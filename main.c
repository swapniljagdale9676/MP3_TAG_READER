/*  
 * Project   : MP3 Tag Reader & Editor
 * Name      : Swapnil Jagdale
 
 * Description:
    ->  This program reads and edits ID3 metadata tags from MP3 files. 
    ->  It supports viewing tags like Title, Artist, Album, Year, Genre, 
        and Comment, as well as updating them with new user-provided data.
*/

#include "mp3_header.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int v;

    // No arguments
    if (argc == 1) 
    {
        no_arg();
        return 0;
    }

    // Help option
    else if (argc == 2) {
        if (strcmp(argv[1], "--help") == 0) {
            help_mp3();
            return 0;
        }
        printf("\n=========================================================\n");;
        printf("               ERROR: INVALID INPUT..!\n");
        printf("\n=========================================================\n");
        return 0;
    }

    // View option: ./a.out -v file.mp3
    else if (argc == 3) {
        v = is_mp3(argv[2]);
        if (v == 0) {
            printf("\n=========================================================\n");
            printf("              ERROR: INVALID MP3 FILE  \n");
            printf("---------------------------------------------------------\n");
            printf("   The file '%s' is not a valid MP3/ID3 tagged file.\n", argv[2]);
            printf("=========================================================\n\n");
            return 0;
        }

        if (strcmp(argv[1], "-v") == 0) {
            printf("\n=============================================================\n");
            printf("                 MP3 TAG INFORMATION \n");
            printf("=============================================================\n");
            view_mp3(argv[2]);
            printf("=============================================================\n");
            return 0;
        }

        printf("Invalid view option!\n");
        return 0;
    }

    // Edit option: ./a.out -e -t "New Title" file.mp3
    else if (argc == 5) {

        v = is_mp3(argv[4]);
        if (v == 0) {
            printf("\n=========================================================\n");
            printf("     ERROR: INVALID MP3 FILE  \n");
            printf("---------------------------------------------------------\n");
            printf("   The file '%s' is not a valid MP3/ID3 tagged file.\n", argv[4]);
            printf("=========================================================\n\n");

            return 0;
        }

        if (strcmp(argv[1], "-e") != 0) {
            printf("Invalid command! Use -e for edit.\n");
            return 0;
        }

        const char *opt      = argv[2];  // -t / -a / -A / -y / -c
        const char *new_txt  = argv[3];
        const char *filename = argv[4];

        // Map options to ID3 frame names
        if (strcmp(opt, "-t") == 0) {
            edit_mp3("TIT2", new_txt, filename);   // Title
        }
        else if (strcmp(opt, "-a") == 0) {
            edit_mp3("TPE1", new_txt, filename);   // Artist
        }
        else if (strcmp(opt, "-A") == 0) {
            edit_mp3("TALB", new_txt, filename);   // Album
        }
        else if (strcmp(opt, "-y") == 0) {
            edit_mp3("TYER", new_txt, filename);   // Year
        }
        else if (strcmp(opt, "-m") == 0) {
            edit_mp3("TCON", new_txt, filename);   // Genre
        }
        else if (strcmp(opt, "-c") == 0) {
            edit_mp3("COMM", new_txt, filename);   // Comment
        }
        else {
            printf("Invalid edit option: %s\n", opt);
            no_arg();
            return 0;
        }

        printf("=========================================================\n");
        printf("         CONTENT UPDATED SUCCESSFULLY!   \n");
        printf("=========================================================\n\n");

        return 0;
    }

    // Anything else
    no_arg();
    return 0;
}
