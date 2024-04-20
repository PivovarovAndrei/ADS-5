// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priority(char op) {
    if (op == '' || op == '/') return 3;
    else if (op == '+' || op == '-') return 2;
    else if (op == '(') return 1;
    else return 0;
}

std::string infx2pstfx(std::string inf) {
    std::string pst;
    TStack<char, 100> stack;
    
    for (int i = 0; i < inf.length(); i++) {
        if (inf[i] == ' ') continue;
        
        if (inf[i] >= '0' && inf[i] <= '9') {
            pst += inf[i];
            while (i + 1 < inf.length() && (inf[i + 1] >= '0' && inf[i + 1] <= '9')) {
                pst += inf[++i];
            }
            pst += ' ';
        } else if (stack.isEmpty() || inf[i] == '(' || priority(inf[i]) > priority(stack.get())) {
            stack.push(inf[i]);
        } else if (inf[i] == ')') {
            char top = stack.get();
            stack.pop();
            while (top != '(') {
                pst += top;
                pst += ' ';
                top = stack.get();
                stack.pop();
            }
        } else {
            while (!stack.isEmpty() && priority(stack.get()) >= priority(inf[i])) {
                pst += stack.get();
                pst += ' ';
                stack.pop();
            }
            stack.push(inf[i]);
        }
    }
    
    while (!stack.isEmpty()) {
        pst += stack.get();
        pst += ' ';
        stack.pop();
    }
    
    return pst;
}

int eval(std::string post) {
    TStack<int, 100> stack;
    
    for (int i = 0; i < post.length(); i++) {
        if (post[i] == ' ') continue;
        
        if (post[i] >= '0' && post[i] <= '9') {
            int num = 0;
            while (post[i] != ' ') {
                num = num  10 + (posti - '0');
                i++;
            }
            stack.push(num);
        } else {
            int a = stack.get();
            stack.pop();
            int b = stack.get();
            stack.pop();
            if (posti == '+') stack.push(b + a);
            else if (posti == '-') stack.push(b - a);
            else if (posti == '') stack.push(b  a);
            else if (posti == '/') stack.push(b / a);
        }
    }
    
    return stack.get();
}
