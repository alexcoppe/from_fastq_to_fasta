/*
 * Author: Alessandro Coppe
 * Purpose: To tranform a FASTQ file to a FASTA one
 * Language: C
 * 
 *  (c) 2019 Coppe
 *  This code is licensed under MIT license (see LICENSE.txt for details)
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


void split_line_with_newlines(char *string);


int main(int argc, char *argv[]){
    const int STRING_MAX_LEN = 350;
    char line[STRING_MAX_LEN + 1];
    FILE *file;
    char ch;
    int exit = 0;
    _Bool READ_LABEL = 0;
    int string_length;
    char *seq;


    /* Help string */
    char help[] = "Usage: from_fastq_to_fasta [OPTION]... FASTA_FILE.\n  "
        "-h\tshow help options";

    /* Options section */
    while ((ch = getopt(argc, argv, "dh")) != EOF) {
        switch (ch) {
            case 'd':
                break;
            case 'h':
                exit = 1;
                puts(help);
                return 0;
            default:
                return -1;
        }
    }

    argc -= optind;
    argv += optind;
    /* Options end */

    /* Check if there is a FASTA file argument */
    if (argc < 1) {
        fprintf(stderr, "Fastq file name not specified\n");
        return 1;
    }

    /* If the FASTA file is not present */
    if (!(file = fopen(argv[0], "r"))) {
        fprintf(stderr, "Coud not find file: %s\n", argv[0]);
        return 1;
    }


    while (fgets(line, STRING_MAX_LEN, file)) {
        if (line[0] == '@'){
            READ_LABEL = 1;
            fprintf(stdout, ">%s", line + 1);
            continue;
        }

        if (READ_LABEL == 1) {
            seq = line;
            string_length = strlen(seq);

            /* Split and print the DNA/RNA strings by new lines */
            split_line_with_newlines(seq);

            READ_LABEL = 0;
            continue;
        }

    }

}


void split_line_with_newlines(char *string) {
    int start = 0;
    int length = 80;
    int string_length = strlen(string);

    fprintf(stdout, "%.*s\n", length, string);
    while (start < string_length) {
        fprintf(stdout, "%.*s", length, string + (start + length));
        start = start + length;
    }
}
