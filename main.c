#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include "calc.h"

int main(void) {
	double a;
	double b;
	double res;
	int err;
	char operator;

	printf("Welcome to Advanced Computation Software Suite!\n"
			"Available operations:\n"
			"+ - sum\n"
			"- - subtraction\n"
			"/ - division\n"
			"* - multiplication\n"
			"r - square root of a number\n"
			"f - factorial\n");
	while (true) {
		printf("Choose math operation by corresponding char:\n");
		err = scanf(" %c", &operator);
//		printf("error: %d %c %#x\n", err, operator, operator);

		if (strchr("+-/*", operator)) {
			printf(" (%c)  Please, enter two numbers separated by space:\n", operator);
			err = scanf(" %lf %lf", &a, &b);
			printf("error: %d %lf %lf\n", err, a, b);
			if (err != 2) {
				printf("Expected two numbers\n");
				continue;
			}
		} else if (strchr("rf", operator)) {
			printf(" (%c)  Please, enter a number:\n", operator);
			err = scanf(" %lf", &a);
			if (err != 1) {
				printf("Expected a number\n");
				continue;
			}
		}

		switch (operator) {
			case '+':
				res = sum(a, b);
				break;
			case '-':
				res = subtract(a, b);
				break;
			case '/':
				if (b == 0)
					printf("Division by zero is not allowed in this plane of reality.\n");
				else
					res = div(a, b);
				break;
			case '*':
				res = mult(a, b);
				break;
			case 'r':
				res = sqrt_d(a);
				break;
			case 'f':
				res = factorial((int)a);
				break;
			default:
				fprintf(stderr, "Unknown operator: %c %x\n", operator, operator);
				continue;
				break;
		}
		printf("%.3lf\n", res);
	}
}
