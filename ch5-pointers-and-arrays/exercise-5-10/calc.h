#define NUMBER '0' /* signal that a number was found */

int getop(char s[]);

int getch(void);
void ungetch(int c);

void push(double val);
double pop(void);
