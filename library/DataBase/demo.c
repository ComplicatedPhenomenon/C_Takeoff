/**
 * gcc -I/usr/include/postgresql  -std=c11 demo.c -lpq
 **/

#include <stdio.h>
#include<stdlib.h>
#include <libpq-fe.h>

void do_exit(PGconn *conn) {
    PQfinish(conn);
    exit(1);
}

int main() {
    int lib_ver = PQlibVersion();
    printf("Version of libpq: %d\n", lib_ver);

    PGconn *conn = PQconnectdb("user=postgres dbname=postgres");

    if (PQstatus(conn) == CONNECTION_BAD) {
        fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
        do_exit(conn);
    }

    int ver = PQserverVersion(conn);
    char *user = PQuser(conn);
    char *db_name = PQdb(conn);

    printf("Server version: %d, user: %s, db_name: %s\n", ver, user, db_name);

    PGresult *res = PQexec(conn, "SELECT * from following_relation ");

    printf("%s\n", PQgetvalue(res, 0, 1));
    printf("%s\n", PQgetvalue(res, 1, 1));
    PQclear(res);

    PQfinish(conn);

    return 0;
}