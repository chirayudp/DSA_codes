#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// typedef struct fnd {
//     int val;
//     struct fnd* next;
// } fnd;
// fnd* create(int n) {
//     fnd* new = malloc(sizeof(fnd));
//     new->val = n;
//     new->next = NULL;
//     return new;
// }

// int findTheWinner(int n, int k) {
//     int t = k - 1;
//     fnd* head = create(1);
//     fnd* tmp = head;
//     for (int i = 2; i < n + 1; i++) {
//         fnd* new = create(i);
//         tmp->next = new;
//         tmp = tmp->next;
//     }
//     tmp->next = head;
    
//     fnd* prev = tmp;
//     tmp = tmp->next;
//     while (tmp->next != tmp) {
//         for (int i = 1; i < k; i++) {
//             prev = tmp;
//             tmp = tmp->next;
//         }

//         // delete tmp
//         prev->next = tmp->next;
//         fnd* del = tmp;
//         tmp = tmp->next;
//         free(del);
//     }

//     return tmp->val;
// }


int findTheWinner(int n, int k) {
    int winner = 0;
    for (int i = 1; i <= n; i++) {
        int w = winner;
        winner = (winner + k) % i;
        printf("%d = (%d + %d) %% %d\n",winner,w,k,i);
    }
    return winner + 1;
}
int main(){
int n, k;
scanf("%d %d",&n,&k);
int a=findTheWinner( n,  k);
printf("%d\n",a);
}

// Suppose you already know the winner among i-1 people

// When the i-th person joins:

// Everyone shifts by k steps

// The old winner’s index shifts by +k

// Modulo i keeps it in bounds