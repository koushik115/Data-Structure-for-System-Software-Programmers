#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_ARRAY_SIZE 100

struct Node {
  char data;
  struct Node *next;
};

char stackArray[STACK_ARRAY_SIZE];
char stackp = -1;

void pushStackArray(char character);
char popStackArray(void);
int isEmptyStackArray(void);
int isFullStackArray(void);
char topStackArray(void);

struct Node *pushStackList(struct Node *top, char character);
int popStackList(struct Node **top, char *character);
int isEmptyStackList(struct Node *top);

void reverseStackElement(char *string);
void reverseStackElementVer2(char *string);

int checkBalancedParenthesis(char *string);

int evaluateToPostfix(char *expr);
char *infixToPostfix(char *expr);

int main(void) {

  char characterArray[] = "ReverseString";
  reverseStackElement(characterArray);
  printf("%s\n", characterArray);
  reverseStackElementVer2(characterArray);
  printf("%s\n", characterArray);
  printf("%d\n", checkBalancedParenthesis("([{}])"));

  char expr[] = "1 2 3 * + 4 +";
  char *infixExpr = "((1 + 2) * 3 - 4) * 5";
  char *postfixExpr = infixToPostfix(infixExpr);
  printf("%s\n", postfixExpr);
  printf("%d\n", evaluateToPostfix(expr));

  free(postfixExpr);
  return 0;
}

void pushStackArray(char character) {
  if (isFullStackArray()) {
    printf("error: stack overflow!\n");
    return;
  }

  stackArray[++stackp] = character;
}

char popStackArray(void) {
  if (isEmptyStackArray()) {
    return CHAR_MIN;
  }

  return stackArray[stackp--];
}

struct Node *pushStackList(struct Node *top, char character) {
  struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
  if (tmp == NULL)
    return NULL;

  tmp->data = character;
  if (isEmptyStackList(top))
    tmp->next = NULL;
  else
    tmp->next = top;

  top = tmp;
  return top;
}

int popStackList(struct Node **top, char *character) {
  struct Node *tmp = NULL;
  if (isEmptyStackList(*top))
    return 0;

  tmp = *top;
  *top = tmp->next;
  *character = tmp->data;

  free(tmp);
  tmp = NULL;

  return 1;
}

char topStackArray(void) {
  if (isEmptyStackArray())
    return CHAR_MIN;
  return stackArray[stackp];
}

char topStackList(struct Node *top) {
  if (top == NULL)
    return CHAR_MIN;
  return top->data;
}

int isEmptyStackArray(void) { return (stackp == -1); }

int isFullStackArray(void) { return (stackp == STACK_ARRAY_SIZE - 1); }

int isEmptyStackList(struct Node *top) { return (top == NULL); }

/* Application */
void reverseStackElement(char *string) {
  int i;
  char character;

  for (i = 0; string[i] != '\0'; i++)
    pushStackArray(string[i]);

  i = 0;
  while ((character = popStackArray()) != CHAR_MIN)
    string[i++] = character;
}

void reverseStackElementVer2(char *string) {
  int i;
  char character;
  struct Node *top = NULL;

  for (i = 0; string[i] != 0; i++)
    top = pushStackList(top, string[i]);

  i = 0;
  while (popStackList(&top, &character) != 0)
    string[i++] = character;
}

int checkBalancedParenthesis(char *string) {
  int i, element;
  for (i = 0; string[i] != '\0'; i++) {
    switch (string[i]) {
    case '(':
    case '{':
    case '[':
      pushStackArray(string[i]);
      break;

    case ')':
    case '}':
    case ']':
      if (isEmptyStackArray())
        return 0;
      element = topStackArray();
      if ((string[i] == ')' && element != '(') ||
          (string[i] == '}' && element != '{') ||
          (string[i] == ']' && element != '['))
        return 0;
      popStackArray();
      break;

    default:
      break;
    }
  }

  return isEmptyStackArray();
}

int checkBalancedParenthesisVer2(char *string) {
  int i, element;
  struct Node *top = NULL;
  for (i = 0; string[i] != '\0'; i++) {
    switch (string[i]) {
    case '(':
    case '{':
    case '[':
      top = pushStackList(top, string[i]);
      break;

    case ')':
    case '}':
    case ']':
      if (isEmptyStackList(top))
        return 0;
      element = topStackList(top);
      if ((string[i] == ')' && element != '(') ||
          (string[i] == '}' && element != '{') ||
          (string[i] == ']' && element != '['))
        return 0;
      popStackList(&top, (char *)&element);
      break;

    default:
      break;
    }
  }

  return isEmptyStackList(top);
}

int evaluateToPostfix(char *expr) {
  int i, op1, op2, res;

  for (i = 0; expr[i] != '\0'; i++) {
    if (expr[i] >= '0' && expr[i] <= '9')
      pushStackArray(expr[i] - '0');
    else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' ||
             expr[i] == '/' || expr[i] == '%') {
      op2 = popStackArray();
      op1 = popStackArray();

      switch (expr[i]) {
      case '+':
        pushStackArray(op1 + op2);
        break;
      case '-':
        pushStackArray(op1 - op2);
        break;
      case '*':
        pushStackArray(op1 * op2);
        break;
      case '/':
        if (op2 != 0)
          pushStackArray(op1 / op2);
        else
          printf("error: illegal operaion\n");
        break;

      case '%':
        if (op2 != 0)
          pushStackArray(op1 % op2);
        else
          printf("error: illegal operaion\n");
        break;
      }
    }
  }

  return topStackArray();
}

static int isOperand(char op) { return (op >= '0' && op <= '9'); }

static int isOperator(char op) {
  return ((op == '+')   ? 1
          : (op == '-') ? 1
          : (op == '/') ? 1
          : (op == '*') ? 1
          : (op == '%') ? 1
                        : 0);
}

static int getWeight(char op) {
  switch (op) {
  case '+':
  case '-':
    return 1;

  case '/':
  case '*':
    return 2;

  case '^':
    return 3;

  default:
    return 0;
  }
}

static int IsHigherOrEqualPrecedence(char op1, char op2) {
  return (getWeight(op1) >= getWeight(op2));
}

char *infixToPostfix(char *expr) {
  char *postfixExpr = (char *)malloc(strlen(expr) + 1);
  if (postfixExpr == NULL)
    return NULL;
  char *startOfExpr = postfixExpr;

  for (int i = 0; expr[i] != '\0'; i++) {
    if (isOperand(expr[i]))
      *postfixExpr++ = expr[i];
    else if (isOperator(expr[i])) {
      while (!isEmptyStackArray() &&
             IsHigherOrEqualPrecedence(topStackArray(), expr[i]) &&
             topStackArray() != '(') {
        *postfixExpr++ = topStackArray();
        popStackArray();
      }

      pushStackArray(expr[i]);
    } else if (expr[i] == '(') {
      pushStackArray(expr[i]);
    } else if (expr[i] == ')') {
      while (!isEmptyStackArray() && topStackArray() != '(') {
        *postfixExpr++ = topStackArray();
        popStackArray();
      }
      popStackArray();
    }
  }

  while (!isEmptyStackArray())
    *postfixExpr++ = popStackArray();

  *postfixExpr = '\0';

  return startOfExpr;
}
