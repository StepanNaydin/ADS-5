// Copyright 2021 NNTU-CS
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include "tstack.h"

int prioritet(char value) {
    if (value == '(') {
        return 0;
    } else if (value == '+' || value == '-') {
        return 2;
    } else if (value == '*' || value == '/') {
        return 3;
    }
    return -1;
}

std::string infx2pstfx(std::string inf) {
    Stack<char, 100> stack1;
    std::string post;
    for (int q = 0; q < inf.length(); ++q) {
        if (inf[q] == '1' || inf[q] == '2'
            || inf[q] == '3' || inf[q] == '4'
            || inf[q] == '5' || inf[q] == '6'
            || inf[q] == '7' || inf[q] == '8'
            || inf[q] == '9' || inf[q] == '0'
            || inf[q] == ' ') {
            if (inf[q] == ' ') {
                if (post[post.length() - 1] != ' ') {
                    post += inf[q];
                    continue;
                }
            } else {
                post += inf[q];
            }
            continue;
        }
        if (prioritet(inf[q]) == 0 || stack1.isEmpty()
            || prioritet(inf[q]) > prioritet(stack1.Get())) {
            if (post[post.length() - 1] != ' ') {
                post += ' ';
            }
            stack1.push(inf[q]);
        } else if (inf[q] != ')') {
            while (!stack1.isEmpty()) {
                if (prioritet(stack1.Get()) >= prioritet(inf[q])) {
                    post += stack1.Pop();
                    if (post[post.length() - 1] != ' ') {
                        post += ' ';
                    }
                }
            }
            stack1.push(inf[q]);
        }
        if (inf[q] == ')') {
            std::string DopString;
            while (1) {
                char a = stack1.Pop();
                if (a == '(') {
                    break;
                }
                DopString += a;
            }
            post += DopString;
        }
    }
    while (!stack1.isEmpty()) {
        if (post[post.length() - 1] != ' ') {
            post += ' ';
        }
        post += stack1.Pop();
    }
    return post;
}
int eval(std::string inf) {
    Stack<char, 100> stack1;
    int post = 0, q = -1;
    for (int q = 0; q < inf.length(); ++q) {
        if (inf[q] == '1' || inf[q] == '2'
            || inf[q] == '3' || inf[q] == '4'
            || inf[q] == '5' || inf[q] == '6'
            || inf[q] == '7' || inf[q] == '8'
            || inf[q] == '9' || inf[q] == '0'
            || inf[q] == ' ') {
            stack1.push(inf[q]);;
            continue;
        } else if (inf[q] == '+' || inf[q] == '-'
                   || inf[q] == '*' || inf[q] == '/') {
            char a = stack1.Pop();
            while (1) {
                std::cout << a << " a" << std::endl;
                if (a == ' ') {
                    a = stack1.Pop();
                } else {
                    break;
                }
            }
            int x1, x2;
            std::string DopString1, DopString2;
            while (1) {
                if (a == ' ') {
                    break;
                }
                DopString1 += a;
                a = stack1.Pop();
            }
            std::reverse(DopString1.begin(), DopString1.end());
            std::istringstream(DopString1) >> x1;
            while (1) {
                if (stack1.isEmpty()) {
                    break;
                }
                char a = stack1.Pop();
                if (a == ' ') {
                    break;
                }
                DopString2 += a;
            }
            std::reverse(DopString2.begin(), DopString2.end());
            std::istringstream(DopString2) >> x2;
            if (inf[q] == '+') {
                post += (x2 + x1);
            } else if (inf[q] == '-') {
                post += (x2 - x1);
            } else if (inf[q] == '*') {
                post += (x2 * x1);
            } else if (inf[q] == '/') {
                post += (x2 / x1);
            }
            char dig = ' ';
            stack1.push(dig);
            int w = 10;
            int e = 1;
            std::string DopDopString;
            while (1) {
                if (post > 0) {
                    DopDopString += std::to_string(post % w / e);
                    post = post / w;
                } else {
                    break;
                }
            }
            for (int q = DopDopString.length() - 1; q > -1; --q) {
                stack1.push(DopDopString[q]);
            }
        }
    }
    std::string DopDopString;
    while (!stack1.isEmpty()) {
        DopDopString += stack1.Pop();
    }
    std::reverse(DopDopString.begin(), DopDopString.end());
    std::istringstream(DopDopString) >> post;
    return post;
}
