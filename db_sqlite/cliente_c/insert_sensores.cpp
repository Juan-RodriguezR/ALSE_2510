#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   string sql;

   /* Open database */
   rc = sqlite3_open("test.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "INSERT INTO sensor (id_medida, Temperatura, Humedad, Fecha) "  \
         "VALUES (01, 27, 16,'7 Abril 2024'); " \
         "INSERT INTO sensor (id_medida, Temperatura, Humedad, Fecha) "  \
         "VALUES (02, 28, 15,'8 Abril 2024'); " \
	     "INSERT INTO sensor (id_medida, Temperatura, Humedad, Fecha) "  \
         "VALUES (03, 30, 10,'9 Abril 2024'); " \
	     "INSERT INTO sensor (id_medida, Temperatura, Humedad, Fecha) "  \
         "VALUES (04, 26, 12,'10 Abril 2024'); " ;

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);
   return 0;
}
