#include <stdio.h>
#include <string.h>
#define d 10
void rabinKarp(char pattern[], char text[], int q) 
{
    int m = strlen(pattern);
    int n = strlen(text);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    // Calculate h as (d^m-1)%q
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;
    // Calculate initial hash values for pattern and text
    for (i = 0; i < m; i++) 
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    // Slide the pattern over the text and compare their hash values
    for (i = 0; i <= n - m; i++) 
    {
        if (p == t) 
        {
            for (j = 0; j < m; j++) 
            {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                printf("Pattern is found at position: %d\n", i + 1 );
        }
        // Calculate hash value for next window of text
        if (i < n - m) 
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}
int main() 
{
    char text[100], pattern[100];
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);
    int q = 101;
    rabinKarp(pattern, text, q);
    return 0;
}