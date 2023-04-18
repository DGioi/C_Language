#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 1000

int word_length_frequency[MAX_WORD_LENGTH + 1];
char longest_word[MAX_WORD_LENGTH + 1];
char shortest_word[MAX_WORD_LENGTH + 1];
int char_frequency[256];
char most_used_char;
char least_used_char;
char longest_sentence[MAX_SENTENCE_LENGTH + 1];
char shortest_sentence[MAX_SENTENCE_LENGTH + 1];

void analyze_text(char text[]) {
    char words[MAX_WORDS][MAX_WORD_LENGTH + 1];
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH + 1];

    int word_count = 0;
    int sentence_count = 0;

    char *word = strtok(text, " ,.!?");
    while (word != NULL) {
        strcpy(words[word_count], word);
        int word_length = strlen(word);
        word_length_frequency[word_length]++;

        if (word_length > strlen(longest_word)) {
            strcpy(longest_word, word);
        }

        if (word_length < strlen(shortest_word) || word_count == 0) {
            strcpy(shortest_word, word);
        }

        for (int i = 0; i < word_length; i++) {
            char_frequency[(int)tolower(word[i])]++;
        }

        word_count++;
        word = strtok(NULL, " ,.!?");
    }

    char *sentence = strtok(text, ".");
    while (sentence != NULL) {
        strcpy(sentences[sentence_count], sentence);

        if (strlen(sentence) > strlen(longest_sentence)) {
            strcpy(longest_sentence, sentence);
        }

        if (strlen(sentence) < strlen(shortest_sentence) || sentence_count == 0) {
            strcpy(shortest_sentence, sentence);
        }

        sentence_count++;
        sentence = strtok(NULL, ".");
    }

    for (int i = 0; i < 256; i++) {
        if (char_frequency[i] > char_frequency[(int)most_used_char]) {
            most_used_char = (char)i;
        }

        if (char_frequency[i] < char_frequency[(int)least_used_char
    }
}

int main() {
    char text[MAX_SENTENCE_LENGTH + 1];
    printf("Enter a text: ");
    fgets(text, MAX_SENTENCE_LENGTH, stdin);

    memset(word_length_frequency, 0, sizeof(word_length_frequency));
    memset(longest_word, 0, sizeof(longest_word));
    memset(shortest_word, 0, sizeof(shortest_word));
    memset(char_frequency, 0, sizeof(char_frequency));
    most_used_char = least_used_char = 0;
    memset(longest_sentence, 0, sizeof(longest_sentence));
    memset(shortest_sentence, 0, sizeof(shortest_sentence));

    analyze_text(text);

    printf("Word length frequency:\n");
    for (int i = 0; i <= MAX_WORD_LENGTH; i++) {
        if (word_length_frequency[i] > 0) {
            printf("%d-letter words: %d\n", i, word_length_frequency[i]);
        }
    }

    printf("\nLongest word: %s\n", longest_word);
    printf("Shortest word: %s\n", shortest_word);

    printf("\nCharacter frequency:\n");
    for (int i = 0; i < 256; i++) {
        if (char_frequency[i] > 0) {
            printf("'%c': %d\n", (char)i, char_frequency[i]);
        }
    }

    printf("\nMost used character: '%c'\n", most_used_char);
    printf("Least used character: '%c'\n", least_used_char);

    printf("\nLongest sentence: %s\n", longest_sentence);
    printf("Shortest sentence: %s\n", shortest_sentence);

    return 0;
}

