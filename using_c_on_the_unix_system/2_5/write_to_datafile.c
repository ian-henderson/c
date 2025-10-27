#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record {
    int uid;
    char login[8];
} record;

char *logins[] = {"user1", "user2", "user3", "user4", "user5"};

void putrec(FILE *fp, int i, record *r) {
    fseek(fp, (long)i * sizeof(record), SEEK_SET);
    fwrite(r, sizeof(record), 1, fp);
}

int main(int argc, char *argv[]) {
    FILE *fp;

    if ((fp = fopen("datafile", "w")) == NULL) {
        perror("datafile");
        exit(1);
    }

    record r;

    for (int i = 4; i >= 0; i--) {
        r.uid = i;
        strcpy(r.login, logins[i]);
        putrec(fp, i, &r);
    }

    fclose(fp);
    exit(0);
}
