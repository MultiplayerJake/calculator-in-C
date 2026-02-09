#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// variables
int howmeny = 0;


void multiplytable() {
    int number;
    int rows;
    int biggest = 0;
    int width = 1;
    printf("type biggest number multiplayer>");
    scanf("%i", &number);
    printf("type how much do you want to multiply it>");
    scanf("%i", &rows);

    //biggest number
    biggest = number * rows;
    if (biggest > 9999) {
        printf("biggest number was bigger then 9999\n");
        return;
    }
    while (biggest / 10 >= 1) {
        biggest = biggest / 10;
        width += 1;
    }


    for (int i = 1; i <= rows; i++) {
        for (int j = number; j >= 1; j--) {
            printf("%*i ", width ,j*i);
        }
        printf("\n");
    }
    return;
}

void powertable() {
    int number;
    int topower;
    int width = 2;
    int biggest = 0;
    printf("be aware that if you type a big number and power it with another big number it won't look good\n");
    printf("to what power number>");
    scanf("%i", &number);
    printf("how many power multiplayer>");
    scanf("%i", &topower);

    // biggest number
    biggest = number;
    for (int b = 1; b <= topower - 1; b++) {
        biggest = biggest * number;
    }
    if (biggest > 99999 || biggest < -10 || biggest == 0) {
        printf("biggest number was bigger then 9999\n");
        return;
    }
    while (biggest / 10 >= 1) {
        biggest = biggest / 10;
        width += 1;
    }


    for (int i = number; i >= 1; i--) {
        printf("%*i ", width , i);
    }
    printf("\n");

    for (int j = 1; j <= topower - 1; j++) {
        for (int i = number; i >= 1; i--) {
            int answer = i;
            for (int k = 1; k <= j; k++) {
                answer *= i;
            }
            printf("%*i ", width ,answer);
        }
        printf("\n");
    }
}

void multiply() {
    int number;
    int multiplayer;
    printf("type number you want to multiply>");
    scanf("%i", &number);
    printf("type how much you want to multiply it>");
    scanf("%i", &multiplayer);

    printf("the answer is: %i \n", number * multiplayer);

}

void power() {
    int number;
    int power;
    printf("type number you want to power>");
    scanf("%i", &number);
    printf("type how much power you want to power it>");
    scanf("%i", &power);

    int answer = number;
    for (int b = 1; b <= power - 1; b++) {
        answer = answer * number;
    }
    if (answer < -1) {
        printf("number is too big\n");
        return;
    }
    else {
        printf("the answer is: %i \n", answer);
    }
}

void splittable() {
    int number;
    int splitnumbers[2];
    int width = 2;
    printf("Type number you want to split>");
    scanf("%i", &number);
    printf("Type what two particles you want to divide them into>");
    scanf("%i %i", &splitnumbers[0], &splitnumbers[1]);

    int biggest = number;
    while (biggest / 10 >= 1) {
        biggest = biggest / 10;
        biggest += 1;
    }

    int onesplit = splitnumbers[0]+splitnumbers[1];
    int answer =  number / onesplit;
    printf("we split then into %i and %i\n", splitnumbers[0] * answer, splitnumbers[1] * answer);
    printf("The rest: %i \n", number - ((splitnumbers[0] * answer) + (splitnumbers[1] * answer)));

    return;
}

void split() {
    int number;
    int divide;
    int answer;
    int restanswer;
    printf("type number you want to divide>");
    scanf("%i", &number);
    printf("type number you want to divide by>");
    scanf("%i", &divide);

    answer = number / divide;
    restanswer = number % divide;

    if (restanswer > 0 || restanswer < 0) {
        printf("the answer is: %i the rest is: %i \n", answer, restanswer);
    }
    else if ( answer == 0) {
        printf("number is too big or error occurred \n");
    }
    else {
        printf("the answer is: %i \n", answer);
    }

}


int main(void) {
    if (howmeny == 0) {
        printf(
        "commands:\n"
        "multiply_table   | Makes multiplication table\n"
        "power_table      | Makes power table\n"
        "split_values     | Divide number into two parts\n"
        "multiply         | Multiply number you gave it\n"
        "power            | Power your number by value you give it\n"
        "split            | Divides number\n"
        "quit             | Quits the program\n"
);
    }
    char command[100];
    printf("Command>");
    scanf("%s", &command);

    if (stricmp("multiply_table", command) == 0 || stricmp("multiplytable", command) == 0) {
        multiplytable();
    }
    else if (stricmp("power_table", command) == 0 || stricmp("powertable", command) == 0) {
        powertable();
    }
    else if (stricmp("split_values", command) == 0 || stricmp("splitvalues", command) == 0) {
        splittable();
    }
    else if (stricmp("split", command) == 0) {
        split();
    }
    else if (stricmp("quit", command) == 0) {
        exit(0);
    }
    else if (stricmp("log", command) == 0) {
        printf("you wrote command %i times \n", howmeny + 1);
    }
    else if (stricmp("multiply", command) == 0) {
        multiply();
    }
    else if (stricmp("power", command) == 0) {
        power();
    }
    else if (stricmp("help", command) == 0) {
        printf(
        "commands:\n"
        "multiply_table   | Makes multiplication table\n"
        "power_table      | Makes power table\n"
        "split_values     | Divide number into two parts\n"
        "multiply         | Multiply number you gave it\n"
        "power            | Power your number by value you give it\n"
        "split            | Divides number\n"
        "quit             | Quits the program\n"
);
    }
    else {
        printf("Invalid command\n");
    }
    howmeny++;
    main();
}




