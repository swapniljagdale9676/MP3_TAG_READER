#include "mp3_header.h"

//Validation for the .mp3 file
int is_mp3(const char *file)
{
    char *dot = strrchr(file, '.');
    if (!dot)
        return 0;    // no extension

    if (strcmp(dot, ".mp3") == 0)
        return 1;
    
    return 0;
}

//PRINT IF USER DID NOT PASS ARGUMENTS
void no_arg()
{
    printf("===================================================================================\n");
    printf("                           INVALID ARGUMENTS PROVIDED\n");
    printf("===================================================================================\n");
    printf("Usage:\n");
    printf("To \"HELP\" please pass like: ./a.out --help\n");
    printf("To \"VIEW\" please pass like: ./a.out -v <file>\n");
    printf("To \"EDIT\" please pass like: ./a.out -e [-t/-a/-A/-y/-m/-c] \"<changing_txt>\" <file>\n");

    printf("Help:\n");
    printf("      ./a.out --help\n");
    printf("===================================================================================\n");
}

//HELP MENU
void help_mp3()
{
    printf("===================================================================================\n");
    printf("                                MP3 TAG READER HELP\n");
    printf("===================================================================================\n");

    printf("Options:\n");
    printf("  -v <file>                View MP3 tag information\n");
    printf("  -e <tag> <text> <file>   Edit MP3 tag\n\n");

    printf("Tag Options for editing:\n");
    printf("  -t    Edit Title\n");
    printf("  -a    Edit Artist\n");
    printf("  -A    Edit Album\n");
    printf("  -y    Edit Year\n");
    printf("  -m    Edit Genre\n");
    printf("  -c    Edit Comment\n\n");

    printf("Examples:\n");
    printf("  View tags:\n");
    printf("      ./a.out -v sample.mp3\n\n");

    printf("  Edit title:\n");
    printf("      ./a.out -e -t \"New Song Name\" sample.mp3\n\n");

    printf("  Edit artist:\n");
    printf("      ./a.out -e -a \"New Artist\"  sample.mp3\n\n");

    printf("===================================================================================\n");
}