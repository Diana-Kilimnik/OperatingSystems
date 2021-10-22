#include<stdio.h>

void printName() {
    printf("One-armed bandit game\n");
}

void printEnterBudget() {
    printf("Enter your count of money: ");
}

void printYouWinX(int number) {
    printf("You win x%d!\n", number);
}
void printReturnYourMoney() {
    printf("Return your money\n");
}
void printDoYouWantContinue() {
    printf("To continue- 1\nTo take money - 0\n>>");
}
void printYouLose() {
    printf("You lose\n");
}
void printYourCurrentBalance(double balance) {
    printf("Your current balance: %.2lf\n", balance);
}
void printGameOver() {
    printf("Game Over!");
}

void printThanksForPlaying() {
    printf("Thank you for playing!\n");
}

void printEnterCorrectData() {
    printf("Please, enter correct data!\n");
}