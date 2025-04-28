#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string>
#include <iostream>

using namespace std;

static int callback(void *data, int argc, char **argv, char **azColName)
{
    int i;
    std::cout << (*(double *)data) << std::endl;

    if (argc > 0 && argv[0])
    {
        double *local = (double *)data;
        *local = atof(argv[0]); // Store the average temperature
    }
    return 0;
}

int main(int argc, char *argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sql;
    const char *data = "He llamado la función Callback";
    double f = 0.0; // Variable to store the average temperature

    /* Open database */
    rc = sqlite3_open("test.db", &db);

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return (0);
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
    }

    /* Create SQL statement */
    sql = "SELECT * FROM sensor;";

    /* Execute SQL statement */
    sql = "SELECT AVG(temperatura) AS promedio FROM sensor;";

    rc = sqlite3_exec(db, sql.c_str(), callback, &f, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Operation done successfully\n");
        printf("El promedio de temperatura es: %.2f\n", f);
    }
    sqlite3_close(db);
    return 0;
}
