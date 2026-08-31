#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// tic-tac-toe

void print_board(int num1[9]){
    printf("Now the board looks like: \n\n");
    int i;
    for(i=1; i<=9; i++){
        if((i)%3!=0){
            if(num1[i-1]==0) printf(" %d |", i);
            else if(num1[i-1]==3) printf(" X |");
            else if(num1[i-1]==4) printf(" O |");
        } else {
            if(num1[i-1]==0) printf(" %d\n", i);
            else if(num1[i-1]==3) printf(" X\n");
            else if(num1[i-1]==4) printf(" O\n");
        }
    }
}

void print_win(int num3[9], int char2, int i2) {
    if(char2==1) {
        if(num3[i2]==3){
            printf("\nCongrats, You win!\n");
            exit(0);
        } else if(num3[i2]==4){
            printf("\nYou lost! Better luck next time.");
            exit(0);
        }
    } else if(char2==0) {
        if(num3[i2]==4){
            printf("\nCongrats, You win!\n");
            exit(0);
        } else if(num3[i2]==3){
            printf("\nYou lost! Better luck next time.\n");
            exit(0);
        }
    }
}

void check_win(int num2[9], int character) {
    int i;
    for(i=0; i<3; i++){
        int z = 3*i;
        if(num2[i]==num2[i+3] && num2[i+3]==num2[i+6] && num2[i]!=0) print_win(num2, character, i);
        if(num2[z]==num2[z+1] && num2[z+1]==num2[z+2] && num2[z]!=0) print_win(num2, character, z);
    }
    if(num2[0]==num2[4] && num2[4]==num2[8] && num2[4]!=0) print_win(num2, character, 4);
    if(num2[2]==num2[4] && num2[4]==num2[6] && num2[4]!=0) print_win(num2, character, 4);
}

int return_num(int startx) {
    if(startx == 1) return 4;
    else if(startx == 0) return 3;
}

int user_num(int starty) {
    if(starty == 1) return 3;
    else if(starty == 0) return 4;
}

int win_in_two(int dx, int numx[9], int comp_charx){
    int numx2[9] = {0};
    int ix, c, wins = 0;
    for(ix=0; ix<9; ix++){
        numx2[ix] = numx[ix];
    }
    numx2[dx]=comp_charx;
    //Above line creates a simulation for every dx entered
    for(c = 0; c < 9; c += 3){
        if(numx2[c] == 0 && numx2[c+1] != 0 && numx2[c+1] == numx2[c+2] && numx2[c+2] == comp_charx) { wins++; break; }
        if(numx2[c+1] == 0 && numx2[c] != 0 && numx2[c] == numx2[c+2] && numx2[c+2] == comp_charx) { wins++; break; }
        if(numx2[c+2] == 0 && numx2[c] != 0 && numx2[c] == numx2[c+1] && numx2[c+1]== comp_charx) { wins++; break; }
    }

    for(c = 0; c < 3; c++){
        if(numx2[c] == 0 && numx2[c+3] != 0 && numx2[c+3] == numx2[c+6] && numx2[c+6] == comp_charx) { wins++; break; }
        if(numx2[c+3] == 0 && numx2[c] != 0 && numx2[c] == numx2[c+6] && numx2[c+6]== comp_charx) { wins++; break; }
        if(numx2[c+6] == 0 && numx2[c] != 0 && numx2[c] == numx2[c+3] && numx2[c+3]== comp_charx) { wins++; break; }
    }

    if(numx2[0] == 0 && numx2[4] != 0 && numx2[4] == numx2[8] && numx2[4] == comp_charx) wins++;
    if(numx2[4] == 0 && numx2[0] != 0 && numx2[0] == numx2[8] && numx2[8] == comp_charx) wins++;
    if(numx2[8] == 0 && numx2[0] != 0 && numx2[0] == numx2[4] && numx2[4] == comp_charx) wins++;
    if(numx2[2] == 0 && numx2[4] != 0 && numx2[4] == numx2[6] && numx2[4] == comp_charx) wins++;
    if(numx2[4] == 0 && numx2[2] != 0 && numx2[2] == numx2[6] && numx2[2] == comp_charx) wins++;
    if(numx2[6] == 0 && numx2[2] != 0 && numx2[2] == numx2[4] && numx2[4] == comp_charx) wins++;

    if(wins>=2) return 1;
    else return 0;
}

/* int win_in_three(int dx, int numx[9], int unoccx[9], int comp_charx){

} */

int loss_in_three(int dx, int user_charx, int numx[9]){
    int numx2[9] = {0};
    int ix2=0;
    for(ix2=0; ix2<9; ix2++){
        numx2[ix2]=numx[ix2];
    }
    numx2[dx] = user_charx;

    if(win_in_two(dx, numx2, user_charx) == 1) return 1;
    else return 0;
}

int comp_ai(int comp_char1, int num[9]){
    int chosen2 = -1;
    int c=0;
    for(c = 0; c < 9; c += 3){
        if(num[c] == 0 && num[c+1] != 0 && num[c+1] == num[c+2] && num[c+2] == comp_char1) { chosen2 = c; break; }
        if(num[c+1] == 0 && num[c] != 0 && num[c] == num[c+2] && num[c+2] == comp_char1) { chosen2 = c+1; break; }
        if(num[c+2] == 0 && num[c] != 0 && num[c] == num[c+1] && num[c+1]== comp_char1) { chosen2 = c+2; break; }
    }

    if(chosen2 == -1){
        for(c = 0; c < 3; c++){
            if(num[c] == 0 && num[c+3] != 0 && num[c+3] == num[c+6] && num[c+6] == comp_char1) { chosen2 = c; break; }
            if(num[c+3] == 0 && num[c] != 0 && num[c] == num[c+6] && num[c+6]== comp_char1) { chosen2 = c+3; break; }
            if(num[c+6] == 0 && num[c] != 0 && num[c] == num[c+3] && num[c+3]== comp_char1) { chosen2 = c+6; break; }
        }
    }

    if(chosen2 == -1){
        if(num[0] == 0 && num[4] != 0 && num[4] == num[8] && num[4] == comp_char1) chosen2 = 0;
        else if(num[4] == 0 && num[0] != 0 && num[0] == num[8] && num[8] == comp_char1) chosen2 = 4;
        else if(num[8] == 0 && num[0] != 0 && num[0] == num[4] && num[4] == comp_char1) chosen2 = 8;
        else if(num[2] == 0 && num[4] != 0 && num[4] == num[6] && num[4] == comp_char1) chosen2 = 2;
        else if(num[4] == 0 && num[2] != 0 && num[2] == num[6] && num[2] == comp_char1) chosen2 = 4;
        else if(num[6] == 0 && num[2] != 0 && num[2] == num[4] && num[4] == comp_char1) chosen2 = 6;
    }
    return chosen2;
}

int main() {
    int num[9] = {0};
    int start, x, place;
    int unocc[9] = {0};
    srand(time(NULL));
    x = rand() % 10;
    //printf("%d", x);
    printf("Format eg: \n\n1 | 2 | 3\n4 | 5 | 6\n7 | 8 | 9\n");
    if(x%2==0) {
        printf("You start! Your character is X.\n\n");
        start = 1;
    } else {
        printf("The computer starts! Your character is O.\n\n");
        start=0;
    }
    int i;
    for(i=1; i<=9; i++){
        if((i-start)%2==0){
            printf("Enter the number corresponding to the place you'd like to place your character: \n");
            scanf("%d", &place);
            printf("You entered the number: %d\n", place);
            while(place<=0 || place>9 || num[place-1] != 0) {
                printf("Invalid Move\nEnter Again:");
                scanf("%d", &place);
            }
            if(start==1) num[place-1]=3;
            else if(start==0) num[place-1]=4;
            // 3 corresponds to X and 4 corresponds to O
            print_board(num);
            check_win(num, start);
            printf("\n");
        } else {
            int j, rand1, c;
            int k = 0;
            // Build array of unoccupied spots
            for(j = 0; j < 9; j++){
                if(num[j] == 0) unocc[k++] = j;
            }

            int comp_char = return_num(start);
            int user_char = user_num(start);
            int chosen=-1;

            if(i==1) chosen=4;
            else if(i==2){
                if(num[4]!=0){unocc[0]=0; unocc[1]=2; unocc[2]=6; unocc[3]=8; k = 4;}
                else chosen=4;
            } else if(i==4){
                if((num[0]==num[8] && num[0]==user_char)||(num[2]==num[6] && num[2]==user_char)){
                    unocc[0]=1; unocc[1]=3; unocc[2]=5; unocc[3]=7; k=4;
                }
            }

            if(chosen==-1) chosen = comp_ai(comp_char, num);
            if(chosen==-1) chosen = comp_ai(user_char, num);

            if(chosen==-1){
                int d=0;
                for(d=0; d<k; d++){
                    if(win_in_two(unocc[d], num, comp_char)==1){
                        chosen = unocc[d];
                        break;
                    }
                }
            }

            if(chosen==-1){
                int d2=0;
                for(d2=0;d2<k; d2++){
                    if(loss_in_three(unocc[d2], user_char, num)){ chosen = unocc[d2]; break; }
                }
            }

            if(chosen == -1 && k > 0){
                rand1 = rand() % k;
                chosen = unocc[rand1];
            }

            if(chosen != -1){
                num[chosen] = comp_char;
                printf("The Computer chose position- %d.\n", chosen + 1);
                print_board(num);
                check_win(num, start);
            }
        }
        if(i==9) printf("Its a tie! You're as smart as a computer.");
    }
}
