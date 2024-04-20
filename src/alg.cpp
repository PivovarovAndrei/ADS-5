// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int Priority(char c) {
  if (c == '(')
    return 0;
  else if (c == ')')
    return 1;
  else if (c == '+' || c == '-')
    return 2;
  else if (c == '*' || c == '/')
    return 3;
  else
    return -1;
}
std::string infx2pstfx(std::string inf) {
  // добавьте код
  return std::string("");
  std::string post;
  TStack<char, 100> stack1;
  for (char c : inf) {
    if (Priority(c) == -1) {
      post += c;
      post += ' ';
    } else {
        if (c == ')') {
          while (stack1.get() != '(') {
            post += stack1.pop();
            post += ' ';
          }
          stack1.pop();
        } else if (c == '(' || stack1.isempty()) {
            stack1.push(c);
          } else if (!stack1.isempty()) {
              char elem = stack1.get();
              if (Priority(elem) < Priority(c)) {
                stack1.push(c);
              } else {
                  while (Priority(elem) >= Priority(c) && !stack1.isempty()) {
                    post += stack1.pop();
                    post += ' ';
                  }
                  stack1.push(c);
                }
            }
      }
  }
  while (!stack1.isempty()) {
    post += stack1.pop();
    post += ' ';
  }
  post.pop_back();
  return post;
}

int eval(std::string pref) {
  // добавьте код
  return 0;
  int eval(std::string post) {
  TStack<int, 100> stack2;
  std::string number;
  for (int i = 0; i < post.size(); ++i) {
    if (Priority(post[i]) == -1) {
      if (post[i] == ' ') {
        continue;
      } else if (isdigit(post[i + 1])) {
          number += post[i];
          continue;
        } else {
            number += post[i];
            int value = atoi(number.c_str());
            stack2.push(value);
            number = "";
          }
    } else {
        int b = stack2.pop();
        int a = stack2.pop();
        switch (post[i]) {
        case '+':
          stack2.push(a + b);
          break;
        case '-':
          stack2.push(a - b);
          break;
        case '*':
          stack2.push(a * b);
          break;
        case '/':
          stack2.push(a / b);
          break;
        }
      }
  }
  return stack2.get();
}
