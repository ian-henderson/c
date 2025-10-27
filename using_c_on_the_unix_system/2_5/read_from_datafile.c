#include <stdio.h>
#include <stdlib.h>

typedef struct record {
    int uid;
    char login[8];
} record;

int uids[] = {3, 0, 2, 1, 4};

int main(int argc, char *argv[]) {
    FILE *fp;

    if ((fp = fopen("datafile", "r")) == NULL) {
        perror("datafile");
        exit(1);
    }

    record r;
    for (int i = 0; i < sizeof(uids) / sizeof(uids[0]); i++) {
        fseek(fp, (long)uids[i] * sizeof(record), SEEK_SET);
        fread(&r, sizeof(record), 1, fp);
        printf("Record[uid=%d, login='%s']\n", r.uid, r.login);
    }

    fclose(fp);
    exit(0);
}
